// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "xap.h"

#define INVALID_EFFECT 0xFF

#if ((defined(BACKLIGHT_ENABLE)))
#    include "backlight.h"

extern backlight_config_t backlight_config;

bool xap_respond_get_backlight_config(xap_token_t token, const void *data, size_t length) {
    xap_route_lighting_backlight_get_config_t ret;

    ret.enable = backlight_config.enable;
    ret.mode   = backlight_config.breathing;
    ret.val    = backlight_config.level;

    return xap_respond_data(token, &ret, sizeof(ret));
}

bool xap_respond_set_backlight_config(xap_token_t token, const void *data, size_t length) {
    if (length != sizeof(xap_route_lighting_backlight_set_config_arg_t)) {
        return false;
    }

    xap_route_lighting_backlight_set_config_arg_t *arg = (xap_route_lighting_backlight_set_config_arg_t *)data;

    if (arg->enable) {
        backlight_level_noeeprom(arg->val);
    } else {
        backlight_level_noeeprom(0);
    }

#    ifdef BACKLIGHT_BREATHING
    if (arg->mode) {
        backlight_enable_breathing();
    } else {
        backlight_disable_breathing();
    }
#    endif

    return xap_respond_success(token);
}

bool xap_respond_save_backlight_config(xap_token_t token, const void *data, size_t length) {
    eeconfig_update_backlight_current();

    return xap_respond_success(token);
}
#endif

#if ((defined(RGBLIGHT_ENABLE)))
#    include "rgblight.h"

extern rgblight_config_t rgblight_config;

uint8_t rgblight_effect_to_id(uint8_t val);
uint8_t rgblight_id_to_effect(uint8_t val);

bool xap_respond_get_rgblight_config(xap_token_t token, const void *data, size_t length) {
    xap_route_lighting_rgblight_get_config_t ret;

    ret.enable = rgblight_config.enable;
    ret.mode   = rgblight_effect_to_id(rgblight_config.mode);
    ret.hue    = rgblight_config.hue;
    ret.sat    = rgblight_config.sat;
    ret.val    = rgblight_config.val;
    ret.speed  = rgblight_config.speed;

    return xap_respond_data(token, &ret, sizeof(ret));
}

bool xap_respond_set_rgblight_config(xap_token_t token, const void *data, size_t length) {
    if (length != sizeof(xap_route_lighting_rgblight_set_config_arg_t)) {
        return false;
    }

    xap_route_lighting_rgblight_set_config_arg_t *arg = (xap_route_lighting_rgblight_set_config_arg_t *)data;

    uint8_t mode = rgblight_id_to_effect(arg->mode);
    if (mode == INVALID_EFFECT) {
        return false;
    }

    rgblight_enabled_noeeprom(arg->enable);
    rgblight_mode_noeeprom(mode);
    rgblight_sethsv_noeeprom(arg->hue, arg->sat, arg->val);
    rgblight_set_speed_noeeprom(arg->speed);

    return xap_respond_success(token);
}

bool xap_respond_save_rgblight_config(xap_token_t token, const void *data, size_t length) {
    eeconfig_update_rgblight_current();

    return xap_respond_success(token);
}
#endif

#if ((defined(RGB_MATRIX_ENABLE)))
#    include "rgb_matrix.h"

extern rgb_config_t rgb_matrix_config;

uint8_t rgb_matrix_effect_to_id(uint8_t val);
uint8_t rgb_matrix_id_to_effect(uint8_t val);

void rgb_matrix_enabled_noeeprom(bool val) {
    val ? rgb_matrix_enable_noeeprom() : rgb_matrix_disable_noeeprom();
}

bool xap_respond_get_rgb_matrix_config(xap_token_t token, const void *data, size_t length) {
    xap_route_lighting_rgb_matrix_get_config_t ret;

    ret.enable = rgb_matrix_config.enable;
    ret.mode   = rgb_matrix_effect_to_id(rgb_matrix_config.mode);
    ret.hue    = rgb_matrix_config.hsv.h;
    ret.sat    = rgb_matrix_config.hsv.s;
    ret.val    = rgb_matrix_config.hsv.v;
    ret.speed  = rgb_matrix_config.speed;
    ret.flags  = rgb_matrix_config.flags;

    return xap_respond_data(token, &ret, sizeof(ret));
}

bool xap_respond_set_rgb_matrix_config(xap_token_t token, const void *data, size_t length) {
    if (length != sizeof(xap_route_lighting_rgb_matrix_set_config_arg_t)) {
        return false;
    }

    xap_route_lighting_rgb_matrix_set_config_arg_t *arg = (xap_route_lighting_rgb_matrix_set_config_arg_t *)data;

    uint8_t mode = rgb_matrix_id_to_effect(arg->mode);
    if (mode == INVALID_EFFECT) {
        return false;
    }

    rgb_matrix_enabled_noeeprom(arg->enable);
    rgb_matrix_mode_noeeprom(mode);
    rgb_matrix_sethsv_noeeprom(arg->hue, arg->sat, arg->val);
    rgb_matrix_set_speed_noeeprom(arg->speed);
    rgb_matrix_set_flags_noeeprom(arg->flags);

    return xap_respond_success(token);
}

bool xap_respond_save_rgb_matrix_config(xap_token_t token, const void *data, size_t length) {
    eeconfig_update_rgb_matrix();

    return xap_respond_success(token);
}

#   if defined(ENABLE_RGB_MATRIX_XAP_DIRECT)

#ifdef XAP_DIRECT_FOLLOW_QMK_BRIGHTNESS
#define FOLLOW_QMK_BRIGHTNESS() { \
    float brightness = (float)(RGB_MATRIX_MAXIMUM_BRIGHTNESS - (RGB_MATRIX_MAXIMUM_BRIGHTNESS - rgb_matrix_config.hsv.v)) / (float)RGB_MATRIX_MAXIMUM_BRIGHTNESS; \
    rgb.r = rgb.r * brightness; \
    rgb.g = rgb.g * brightness; \
    rgb.b = rgb.b * brightness; \
}
#else // XAP_DIRECT_FOLLOW_QMK_BRIGHTNESS
#define FOLLOW_QMK_BRIGHTNESS()
#endif // XAP_DIRECT_FOLLOW_QMK_BRIGHTNESS

#if (defined( XAP_DIRECT_DISABLE_UPPER_LIMIT)) || \
    (!defined(RGB_MATRIX_MAXIMUM_BRIGHTNESS))  || \
    (RGB_MATRIX_MAXIMUM_BRIGHTNESS == UINT8_MAX)
// Not really recommended unless you don't have a cap anyways
#define UL(input) (input)
#else // XAP_DIRECT_DISABLE_UPPER_LIMIT
#define UL(input) (input > RGB_MATRIX_MAXIMUM_BRIGHTNESS ? RGB_MATRIX_MAXIMUM_BRIGHTNESS : input)
#endif // XAP_DIRECT_DISABLE_UPPER LIMIT

static bool flags_saved = false;
// Rounding up math: ((input + (num - 1)) / num)
#define FLAG_COUNT ((RGB_MATRIX_LED_COUNT + (2 - 1)) / 2)
// Assigning LED_FLAG_NONE doesn't make a lot of sense since each uint8_t is more than 1 flag
uint8_t stored_flags[FLAG_COUNT] = {0};

//#define FLAG_SAVED ((RGB_MATRIX_LED_COUNT + (8 - 1)) / 8)
//uint8_t flags_saved[FLAG_SAVED] = {0};

#define BITMASK_MODIFIER 0
#define BITMASK_UNDERGLOW 1
#define BITMASK_KEYLIGHT 2
#define BITMASK_INDICATOR 3

/* TODO:
    Add way to release single LEDs from Direct modes
    Similar structure to setting them (DONE)

    Figure out how to gracefully use indicator functions outside of calling them manually
    Add way to free LEDs from keyboard
*/
bool xap_respond_direct_free(xap_token_t token, const void *data, size_t length) {
    xap_route_lighting_rgb_matrix_direct_free_arg_t* args = (xap_route_lighting_rgb_matrix_direct_free_arg_t*)data;
    int starting_led = args->starting_led;
    int led_count = args->led_count;
    bool free_all = args->free_all;

    if ((starting_led < 0) || (starting_led >= RGB_MATRIX_LED_COUNT))
        return false;
    
    if ((led_count <= 0) || ((starting_led + led_count) > RGB_MATRIX_LED_COUNT))
        return false;

    if (!flags_saved)
        return false;

    if (free_all)
        starting_led = 0;
    
    int ending_led = (free_all ? RGB_MATRIX_LED_COUNT : (starting_led + led_count));

    for (int led_ndx = starting_led; led_ndx < ending_led; led_ndx++) {
        int flag_ndx = led_ndx / 2;
        // Section is the starting bit index for the flags to be stored at
        // 0..3 is the first LED, and 4..7 is the second LED
        int section = ((led_ndx % 2 == 0) ? 0 : 4);
        if ((1 << (section + BITMASK_MODIFIER )) & stored_flags[flag_ndx])
          g_led_config.flags[led_ndx] += LED_FLAG_MODIFIER;
        if ((1 << (section + BITMASK_UNDERGLOW)) & stored_flags[flag_ndx])
          g_led_config.flags[led_ndx] += LED_FLAG_UNDERGLOW;
        if ((1 << (section + BITMASK_KEYLIGHT)) & stored_flags[flag_ndx])
          g_led_config.flags[led_ndx] += LED_FLAG_KEYLIGHT;
        if ((1 << (section + BITMASK_INDICATOR)) & stored_flags[flag_ndx])
          g_led_config.flags[led_ndx] += LED_FLAG_INDICATOR;
        if (g_led_config.flags[led_ndx] == (LED_FLAG_MODIFIER + LED_FLAG_UNDERGLOW + LED_FLAG_KEYLIGHT + LED_FLAG_INDICATOR)) {
          g_led_config.flags[led_ndx] = LED_FLAG_ALL;
        }
        //if (section == 4) {
        //    stored_flags[flag_ndx] = 0;
        //}
    }
    //flags_saved = false;

    return xap_respond_success(token);
}

bool xap_respond_direct_set_leds(xap_token_t token, const void *data, size_t length) {
    if (!flags_saved) {
        for (int led_ndx = 0; led_ndx < RGB_MATRIX_LED_COUNT; led_ndx++) {
            int flag_ndx = led_ndx / 2;
            // Section is the starting bit index for the flags to be stored at
            // 0..3 is the first LED, and 4..7 is the second LED
            int section = ((led_ndx % 2 == 0) ? 0 : 4);
            if (g_led_config.flags[led_ndx] & LED_FLAG_MODIFIER)
                stored_flags[flag_ndx] |= (1 << (section + BITMASK_MODIFIER));
            if (g_led_config.flags[led_ndx] & LED_FLAG_UNDERGLOW)
                stored_flags[flag_ndx] |= (1 << (section + BITMASK_UNDERGLOW));
            if (g_led_config.flags[led_ndx] & LED_FLAG_KEYLIGHT)
                stored_flags[flag_ndx] |= (1 << (section + BITMASK_KEYLIGHT));
            if (g_led_config.flags[led_ndx] & LED_FLAG_INDICATOR)
                stored_flags[flag_ndx] |= (1 << (section + BITMASK_INDICATOR));
        }
        flags_saved = true;
    }

    xap_route_lighting_rgb_matrix_direct_set_leds_arg_t* args = (xap_route_lighting_rgb_matrix_direct_set_leds_arg_t*)data;

    // 5 is the minimum to set at least 1 LED
    if (length < 5)
        return false;

    const uint8_t starting_led = args->starting_led;
    const uint8_t led_count = args->led_count;

    bool single_color = (length == 5);

    // Check bounds on the starting point
    if ((starting_led < 0) || (starting_led >= RGB_MATRIX_LED_COUNT))
        return false;

    // Check bounds on the ending point
    // The for loop using led_count is exclusive. Meaning starting_led + led_count is never written to
    if ((starting_led + led_count) > RGB_MATRIX_LED_COUNT)
        return false;

    // Make sure we have enough data to actually set the LEDs
    if (((length - 2) < (led_count * 3)) && (!single_color))
        return false;

    if (single_color) {
        for (int led_pos = 0; led_pos < led_count; led_pos++) {
            RGB rgb = (RGB){.r = UL(args->colors[0]),
                            .g = UL(args->colors[1]),
                            .b = UL(args->colors[2])};
            FOLLOW_QMK_BRIGHTNESS();
            rgb_matrix_set_color(starting_led + led_pos, rgb.r, rgb.g, rgb.b);
        }
    } else {
        int starting_led_pos = 0;
        for (int led_pos = 0; led_pos < led_count; led_pos++) {
            RGB rgb = (RGB){.r = UL(args->colors[starting_led_pos + 0]),
                            .g = UL(args->colors[starting_led_pos + 1]),
                            .b = UL(args->colors[starting_led_pos + 2])};
            FOLLOW_QMK_BRIGHTNESS();
            rgb_matrix_set_color(starting_led + led_pos, rgb.r, rgb.g, rgb.b);
            starting_led_pos += 3; // Serves the same purpose as `starting_led_pos = led_pos * 3;` at the beginning of the loop
        }
    }

    if (args->use_indicators) {
        memset(&g_led_config.flags[starting_led], LED_FLAG_ALL, sizeof(uint8_t) * led_count );
        rgb_matrix_indicators_advanced_user(starting_led, starting_led + led_count);
    }

    memset(&g_led_config.flags[starting_led], LED_FLAG_NONE, sizeof(uint8_t) * led_count );

    return xap_respond_success(token);
}
#   endif // ENABLE_RGB_MATRIX_XAP_DIRECT

#endif
