"""This script automates the generation of the QMK API data.
"""
from pathlib import Path
import shutil
import hjson
import json

from milc import cli

from qmk.datetime import current_datetime
from qmk.info import info_json
from qmk.json_encoders import InfoJSONEncoder
from qmk.json_schema import json_load
from qmk.keyboard import find_readme, list_keyboards
from qmk.keycodes import load_spec, list_versions, list_languages
from qmk.xap.common import get_xap_definition_files, update_xap_definitions

DATA_PATH = Path('data')
TEMPLATE_PATH = DATA_PATH / 'templates/api/'
BUILD_API_PATH = Path('.build/api_data/')


def _list_constants(output_folder):
    """Produce a map of available constants
    """
    ret = {}
    for file in (output_folder / 'constants').glob('**/*_[0-9].[0-9].[0-9].json'):
        name, version = file.stem.rsplit('_', 1)
        if name not in ret:
            ret[name] = []
        ret[name].append(version)

    # Ensure content is sorted
    for name in ret:
        ret[name] = sorted(ret[name])

    return ret


def _resolve_keycode_specs(output_folder):
    """To make it easier for consumers, publish pre-merged spec files
    """
    for version in list_versions():
        overall = load_spec(version)

        output_file = output_folder / f'constants/keycodes_{version}.json'
        output_file.write_text(json.dumps(overall, indent=4), encoding='utf-8')

    for lang in list_languages():
        for version in list_versions(lang):
            overall = load_spec(version, lang)

            output_file = output_folder / f'constants/keycodes_{lang}_{version}.json'
            output_file.write_text(json.dumps(overall, indent=4), encoding='utf-8')

    # Purge files consumed by 'load_spec'
    shutil.rmtree(output_folder / 'constants/keycodes/')


def _filtered_copy(src, dst):
    src = Path(src)
    dst = Path(dst)

    if dst.suffix == '.hjson':
        data = json_load(src)

        dst = dst.with_suffix('.json')
        dst.write_text(json.dumps(data, indent=4), encoding='utf-8')
        return dst

    return shutil.copy2(src, dst)


def _filtered_keyboard_list():
    """Perform basic filtering of list_keyboards
    """
    keyboard_list = list_keyboards()
    if cli.args.filter:
        kb_list = []
        for keyboard_name in keyboard_list:
            if any(i in keyboard_name for i in cli.args.filter):
                kb_list.append(keyboard_name)
        keyboard_list = kb_list
    return keyboard_list


def _resolve_xap_specs(output_folder):
    """To make it easier for consumers, publish pre-merged spec files
    """
    overall = None
    for file in get_xap_definition_files():
        overall = update_xap_definitions(overall, hjson.load(file.open(encoding='utf-8')))

        # Inject dummy bits for unspecified response flags
        for n in range(0, 8):
            if str(n) not in overall['response_flags']['bits']:
                overall['response_flags']['bits'][str(n)] = {'name': '', 'description': '', 'define': '-'}

        output_file = output_folder / (file.stem + ".json")
        output_file.write_text(json.dumps(overall, indent=4), encoding='utf-8')


@cli.argument('-n', '--dry-run', arg_only=True, action='store_true', help="Don't write the data to disk.")
@cli.argument('-f', '--filter', arg_only=True, action='append', default=[], help="Filter the list of keyboards based on partial name matches the supplied value. May be passed multiple times.")
@cli.subcommand('Generate QMK API data', hidden=False if cli.config.user.developer else True)
def generate_api(cli):
    """Generates the QMK API data.
    """
    v1_dir = BUILD_API_PATH / 'v1'
    keyboard_all_file = v1_dir / 'keyboards.json'  # A massive JSON containing everything
    keyboard_list_file = v1_dir / 'keyboard_list.json'  # A simple list of keyboard targets
    keyboard_aliases_file = v1_dir / 'keyboard_aliases.json'  # A list of historical keyboard names and their new name
    keyboard_metadata_file = v1_dir / 'keyboard_metadata.json'  # All the data configurator/via needs for initialization
    constants_metadata_file = v1_dir / 'constants_metadata.json'  # Metadata for available constants
    usb_file = v1_dir / 'usb.json'  # A mapping of USB VID/PID -> keyboard target

    if BUILD_API_PATH.exists():
        shutil.rmtree(BUILD_API_PATH)

    shutil.copytree(TEMPLATE_PATH, BUILD_API_PATH)
    shutil.copytree(DATA_PATH, v1_dir, copy_function=_filtered_copy)

    # Filter down when required
    keyboard_list = _filtered_keyboard_list()

    kb_all = {}
    usb_list = {}

    # Generate and write keyboard specific JSON files
    for keyboard_name in keyboard_list:
        kb_all[keyboard_name] = info_json(keyboard_name)
        keyboard_dir = v1_dir / 'keyboards' / keyboard_name
        keyboard_info = keyboard_dir / 'info.json'
        keyboard_readme = keyboard_dir / 'readme.md'
        keyboard_readme_src = find_readme(keyboard_name)

        keyboard_dir.mkdir(parents=True, exist_ok=True)
        keyboard_json = json.dumps({'last_updated': current_datetime(), 'keyboards': {keyboard_name: kb_all[keyboard_name]}})
        if not cli.args.dry_run:
            keyboard_info.write_text(keyboard_json)
            cli.log.debug('Wrote file %s', keyboard_info)

            if keyboard_readme_src:
                shutil.copyfile(keyboard_readme_src, keyboard_readme)
                cli.log.debug('Copied %s -> %s', keyboard_readme_src, keyboard_readme)

        if 'usb' in kb_all[keyboard_name]:
            usb = kb_all[keyboard_name]['usb']

            if 'vid' in usb and usb['vid'] not in usb_list:
                usb_list[usb['vid']] = {}

            if 'pid' in usb and usb['pid'] not in usb_list[usb['vid']]:
                usb_list[usb['vid']][usb['pid']] = {}

            if 'vid' in usb and 'pid' in usb:
                usb_list[usb['vid']][usb['pid']][keyboard_name] = usb

    # Generate data for the global files
    keyboard_list = sorted(kb_all)
    keyboard_aliases = json_load(Path('data/mappings/keyboard_aliases.hjson'))
    keyboard_metadata = {
        'last_updated': current_datetime(),
        'keyboards': keyboard_list,
        'keyboard_aliases': keyboard_aliases,
        'usb': usb_list,
    }

    # Feature specific handling
    _resolve_keycode_specs(v1_dir)
    _resolve_xap_specs(v1_dir / 'xap')

    # Write the global JSON files
    keyboard_all_json = json.dumps({'last_updated': current_datetime(), 'keyboards': kb_all}, cls=InfoJSONEncoder)
    usb_json = json.dumps({'last_updated': current_datetime(), 'usb': usb_list}, cls=InfoJSONEncoder)
    keyboard_list_json = json.dumps({'last_updated': current_datetime(), 'keyboards': keyboard_list}, cls=InfoJSONEncoder)
    keyboard_aliases_json = json.dumps({'last_updated': current_datetime(), 'keyboard_aliases': keyboard_aliases}, cls=InfoJSONEncoder)
    keyboard_metadata_json = json.dumps(keyboard_metadata, cls=InfoJSONEncoder)
    constants_metadata_json = json.dumps({'last_updated': current_datetime(), 'constants': _list_constants(v1_dir)})

    if not cli.args.dry_run:
        keyboard_all_file.write_text(keyboard_all_json)
        usb_file.write_text(usb_json)
        keyboard_list_file.write_text(keyboard_list_json)
        keyboard_aliases_file.write_text(keyboard_aliases_json)
        keyboard_metadata_file.write_text(keyboard_metadata_json)
        constants_metadata_file.write_text(constants_metadata_json)
