// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once
// clang-format off

#define RGBLIGHT_EFFECT_STATIC_LIGHT
#define ENABLE_RGB_MATRIX_SOLID_COLOR
#define ENABLE_LED_MATRIX_SOLID

#ifdef RGBLIGHT_ENABLE
static uint8_t rgblight_effect_map[][2] = {

#ifdef RGBLIGHT_EFFECT_STATIC_LIGHT
    { 0x00, RGBLIGHT_MODE_STATIC_LIGHT},
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    { 0x01, RGBLIGHT_MODE_BREATHING},
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    { 0x02, RGBLIGHT_MODE_BREATHING + 1},
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    { 0x03, RGBLIGHT_MODE_BREATHING + 2},
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    { 0x04, RGBLIGHT_MODE_BREATHING + 3},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    { 0x05, RGBLIGHT_MODE_RAINBOW_MOOD},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    { 0x06, RGBLIGHT_MODE_RAINBOW_MOOD + 1},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    { 0x07, RGBLIGHT_MODE_RAINBOW_MOOD + 2},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    { 0x08, RGBLIGHT_MODE_RAINBOW_SWIRL},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    { 0x09, RGBLIGHT_MODE_RAINBOW_SWIRL + 1},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    { 0x0A, RGBLIGHT_MODE_RAINBOW_SWIRL + 2},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    { 0x0B, RGBLIGHT_MODE_RAINBOW_SWIRL + 3},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    { 0x0C, RGBLIGHT_MODE_RAINBOW_SWIRL + 4},
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    { 0x0D, RGBLIGHT_MODE_RAINBOW_SWIRL + 5},
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    { 0x0E, RGBLIGHT_MODE_SNAKE},
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    { 0x0F, RGBLIGHT_MODE_SNAKE + 1},
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    { 0x10, RGBLIGHT_MODE_SNAKE + 2},
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    { 0x11, RGBLIGHT_MODE_SNAKE + 3},
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    { 0x12, RGBLIGHT_MODE_SNAKE + 4},
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    { 0x13, RGBLIGHT_MODE_SNAKE + 5},
#endif

#ifdef RGBLIGHT_EFFECT_KNIGHT
    { 0x14, RGBLIGHT_MODE_KNIGHT},
#endif

#ifdef RGBLIGHT_EFFECT_KNIGHT
    { 0x15, RGBLIGHT_MODE_KNIGHT + 1},
#endif

#ifdef RGBLIGHT_EFFECT_KNIGHT
    { 0x16, RGBLIGHT_MODE_KNIGHT + 2},
#endif

#ifdef RGBLIGHT_EFFECT_CHRISTMAS
    { 0x17, RGBLIGHT_MODE_CHRISTMAS},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x18, RGBLIGHT_MODE_STATIC_GRADIENT},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x19, RGBLIGHT_MODE_STATIC_GRADIENT + 1},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x1A, RGBLIGHT_MODE_STATIC_GRADIENT + 2},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x1B, RGBLIGHT_MODE_STATIC_GRADIENT + 3},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x1C, RGBLIGHT_MODE_STATIC_GRADIENT + 4},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x1D, RGBLIGHT_MODE_STATIC_GRADIENT + 5},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x1E, RGBLIGHT_MODE_STATIC_GRADIENT + 6},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x1F, RGBLIGHT_MODE_STATIC_GRADIENT + 7},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x20, RGBLIGHT_MODE_STATIC_GRADIENT + 8},
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    { 0x21, RGBLIGHT_MODE_STATIC_GRADIENT + 9},
#endif

#ifdef RGBLIGHT_EFFECT_RGB_TEST
    { 0x22, RGBLIGHT_MODE_RGB_TEST},
#endif

#ifdef RGBLIGHT_EFFECT_ALTERNATING
    { 0x23, RGBLIGHT_MODE_ALTERNATING},
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    { 0x24, RGBLIGHT_MODE_TWINKLE},
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    { 0x25, RGBLIGHT_MODE_TWINKLE + 1},
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    { 0x26, RGBLIGHT_MODE_TWINKLE + 2},
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    { 0x27, RGBLIGHT_MODE_TWINKLE + 3},
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    { 0x28, RGBLIGHT_MODE_TWINKLE + 4},
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    { 0x29, RGBLIGHT_MODE_TWINKLE + 5},
#endif
};

uint8_t rgblight2xap(uint8_t val) {
    for(uint8_t i = 0; i < ARRAY_SIZE(rgblight_effect_map); i++) {
        if (rgblight_effect_map[i][1] == val)
            return rgblight_effect_map[i][0];
    }
    return 0xFF;
}

uint8_t xap2rgblight(uint8_t val) {
    for(uint8_t i = 0; i < ARRAY_SIZE(rgblight_effect_map); i++) {
        if (rgblight_effect_map[i][0] == val)
            return rgblight_effect_map[i][1];
    }
    return 0xFF;
}
enum { ENABLED_RGBLIGHT_EFFECTS = 0

#ifdef RGBLIGHT_EFFECT_STATIC_LIGHT
    | (1ULL << 0x00)
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    | (1ULL << 0x01)
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    | (1ULL << 0x02)
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    | (1ULL << 0x03)
#endif

#ifdef RGBLIGHT_EFFECT_BREATHING
    | (1ULL << 0x04)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    | (1ULL << 0x05)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    | (1ULL << 0x06)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    | (1ULL << 0x07)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    | (1ULL << 0x08)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    | (1ULL << 0x09)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    | (1ULL << 0x0A)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    | (1ULL << 0x0B)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    | (1ULL << 0x0C)
#endif

#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    | (1ULL << 0x0D)
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    | (1ULL << 0x0E)
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    | (1ULL << 0x0F)
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    | (1ULL << 0x10)
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    | (1ULL << 0x11)
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    | (1ULL << 0x12)
#endif

#ifdef RGBLIGHT_EFFECT_SNAKE
    | (1ULL << 0x13)
#endif

#ifdef RGBLIGHT_EFFECT_KNIGHT
    | (1ULL << 0x14)
#endif

#ifdef RGBLIGHT_EFFECT_KNIGHT
    | (1ULL << 0x15)
#endif

#ifdef RGBLIGHT_EFFECT_KNIGHT
    | (1ULL << 0x16)
#endif

#ifdef RGBLIGHT_EFFECT_CHRISTMAS
    | (1ULL << 0x17)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x18)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x19)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x1A)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x1B)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x1C)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x1D)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x1E)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x1F)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x20)
#endif

#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    | (1ULL << 0x21)
#endif

#ifdef RGBLIGHT_EFFECT_RGB_TEST
    | (1ULL << 0x22)
#endif

#ifdef RGBLIGHT_EFFECT_ALTERNATING
    | (1ULL << 0x23)
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    | (1ULL << 0x24)
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    | (1ULL << 0x25)
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    | (1ULL << 0x26)
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    | (1ULL << 0x27)
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    | (1ULL << 0x28)
#endif

#ifdef RGBLIGHT_EFFECT_TWINKLE
    | (1ULL << 0x29)
#endif
};
#endif //RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
static uint8_t rgb_matrix_effect_map[][2] = {

#ifdef ENABLE_RGB_MATRIX_SOLID_COLOR
    { 0x00, RGB_MATRIX_SOLID_COLOR},
#endif

#ifdef ENABLE_RGB_MATRIX_ALPHAS_MODS
    { 0x01, RGB_MATRIX_ALPHAS_MODS},
#endif

#ifdef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    { 0x02, RGB_MATRIX_GRADIENT_UP_DOWN},
#endif

#ifdef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    { 0x03, RGB_MATRIX_GRADIENT_LEFT_RIGHT},
#endif

#ifdef ENABLE_RGB_MATRIX_BREATHING
    { 0x04, RGB_MATRIX_BREATHING},
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_SAT
    { 0x05, RGB_MATRIX_BAND_SAT},
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_VAL
    { 0x06, RGB_MATRIX_BAND_VAL},
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    { 0x07, RGB_MATRIX_BAND_PINWHEEL_SAT},
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    { 0x08, RGB_MATRIX_BAND_PINWHEEL_VAL},
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    { 0x09, RGB_MATRIX_BAND_SPIRAL_SAT},
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    { 0x0A, RGB_MATRIX_BAND_SPIRAL_VAL},
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_ALL
    { 0x0B, RGB_MATRIX_CYCLE_ALL},
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    { 0x0C, RGB_MATRIX_CYCLE_LEFT_RIGHT},
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    { 0x0D, RGB_MATRIX_CYCLE_UP_DOWN},
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    { 0x0E, RGB_MATRIX_CYCLE_OUT_IN},
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    { 0x0F, RGB_MATRIX_CYCLE_OUT_IN_DUAL},
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    { 0x10, RGB_MATRIX_RAINBOW_MOVING_CHEVRON},
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    { 0x11, RGB_MATRIX_CYCLE_PINWHEEL},
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    { 0x12, RGB_MATRIX_CYCLE_SPIRAL},
#endif

#ifdef ENABLE_RGB_MATRIX_DUAL_BEACON
    { 0x13, RGB_MATRIX_DUAL_BEACON},
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_BEACON
    { 0x14, RGB_MATRIX_RAINBOW_BEACON},
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    { 0x15, RGB_MATRIX_RAINBOW_PINWHEELS},
#endif

#ifdef ENABLE_RGB_MATRIX_RAINDROPS
    { 0x16, RGB_MATRIX_RAINDROPS},
#endif

#ifdef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    { 0x17, RGB_MATRIX_JELLYBEAN_RAINDROPS},
#endif

#ifdef ENABLE_RGB_MATRIX_HUE_BREATHING
    { 0x18, RGB_MATRIX_HUE_BREATHING},
#endif

#ifdef ENABLE_RGB_MATRIX_HUE_PENDULUM
    { 0x19, RGB_MATRIX_HUE_PENDULUM},
#endif

#ifdef ENABLE_RGB_MATRIX_HUE_WAVE
    { 0x1A, RGB_MATRIX_HUE_WAVE},
#endif

#ifdef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    { 0x1B, RGB_MATRIX_PIXEL_FRACTAL},
#endif

#ifdef ENABLE_RGB_MATRIX_PIXEL_FLOW
    { 0x1C, RGB_MATRIX_PIXEL_FLOW},
#endif

#ifdef ENABLE_RGB_MATRIX_PIXEL_RAIN
    { 0x1D, RGB_MATRIX_PIXEL_RAIN},
#endif

#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS

#ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
    { 0x1E, RGB_MATRIX_TYPING_HEATMAP},
#endif
#endif

#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS

#ifdef ENABLE_RGB_MATRIX_DIGITAL_RAIN
    { 0x1F, RGB_MATRIX_DIGITAL_RAIN},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    { 0x20, RGB_MATRIX_SOLID_REACTIVE_SIMPLE},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE
    { 0x21, RGB_MATRIX_SOLID_REACTIVE},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    { 0x22, RGB_MATRIX_SOLID_REACTIVE_WIDE},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    { 0x23, RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    { 0x24, RGB_MATRIX_SOLID_REACTIVE_CROSS},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    { 0x25, RGB_MATRIX_SOLID_REACTIVE_MULTICROSS},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    { 0x26, RGB_MATRIX_SOLID_REACTIVE_NEXUS},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    { 0x27, RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SPLASH
    { 0x28, RGB_MATRIX_SPLASH},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_MULTISPLASH
    { 0x29, RGB_MATRIX_MULTISPLASH},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
    { 0x2A, RGB_MATRIX_SOLID_SPLASH},
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
    { 0x2B, RGB_MATRIX_SOLID_MULTISPLASH},
#endif
#endif

#ifdef ENABLE_RGB_MATRIX_XAP_DIRECT
    { 0x2C, RGB_MATRIX_XAP_DIRECT},
#endif
};

uint8_t rgb_matrix2xap(uint8_t val) {
    for(uint8_t i = 0; i < ARRAY_SIZE(rgb_matrix_effect_map); i++) {
        if (rgb_matrix_effect_map[i][1] == val)
            return rgb_matrix_effect_map[i][0];
    }
    return 0xFF;
}

uint8_t xap2rgb_matrix(uint8_t val) {
    for(uint8_t i = 0; i < ARRAY_SIZE(rgb_matrix_effect_map); i++) {
        if (rgb_matrix_effect_map[i][0] == val)
            return rgb_matrix_effect_map[i][1];
    }
    return 0xFF;
}
enum { ENABLED_RGB_MATRIX_EFFECTS = 0

#ifdef ENABLE_RGB_MATRIX_SOLID_COLOR
    | (1ULL << 0x00)
#endif

#ifdef ENABLE_RGB_MATRIX_ALPHAS_MODS
    | (1ULL << 0x01)
#endif

#ifdef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    | (1ULL << 0x02)
#endif

#ifdef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    | (1ULL << 0x03)
#endif

#ifdef ENABLE_RGB_MATRIX_BREATHING
    | (1ULL << 0x04)
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_SAT
    | (1ULL << 0x05)
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_VAL
    | (1ULL << 0x06)
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    | (1ULL << 0x07)
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    | (1ULL << 0x08)
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    | (1ULL << 0x09)
#endif

#ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    | (1ULL << 0x0A)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_ALL
    | (1ULL << 0x0B)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    | (1ULL << 0x0C)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    | (1ULL << 0x0D)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    | (1ULL << 0x0E)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    | (1ULL << 0x0F)
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    | (1ULL << 0x10)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    | (1ULL << 0x11)
#endif

#ifdef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    | (1ULL << 0x12)
#endif

#ifdef ENABLE_RGB_MATRIX_DUAL_BEACON
    | (1ULL << 0x13)
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_BEACON
    | (1ULL << 0x14)
#endif

#ifdef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    | (1ULL << 0x15)
#endif

#ifdef ENABLE_RGB_MATRIX_RAINDROPS
    | (1ULL << 0x16)
#endif

#ifdef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    | (1ULL << 0x17)
#endif

#ifdef ENABLE_RGB_MATRIX_HUE_BREATHING
    | (1ULL << 0x18)
#endif

#ifdef ENABLE_RGB_MATRIX_HUE_PENDULUM
    | (1ULL << 0x19)
#endif

#ifdef ENABLE_RGB_MATRIX_HUE_WAVE
    | (1ULL << 0x1A)
#endif

#ifdef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    | (1ULL << 0x1B)
#endif

#ifdef ENABLE_RGB_MATRIX_PIXEL_FLOW
    | (1ULL << 0x1C)
#endif

#ifdef ENABLE_RGB_MATRIX_PIXEL_RAIN
    | (1ULL << 0x1D)
#endif

#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS

#ifdef ENABLE_RGB_MATRIX_TYPING_HEATMAP
    | (1ULL << 0x1E)
#endif
#endif

#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS

#ifdef ENABLE_RGB_MATRIX_DIGITAL_RAIN
    | (1ULL << 0x1F)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    | (1ULL << 0x20)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE
    | (1ULL << 0x21)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    | (1ULL << 0x22)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    | (1ULL << 0x23)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    | (1ULL << 0x24)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    | (1ULL << 0x25)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    | (1ULL << 0x26)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    | (1ULL << 0x27)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SPLASH
    | (1ULL << 0x28)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_MULTISPLASH
    | (1ULL << 0x29)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
    | (1ULL << 0x2A)
#endif
#endif

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
    | (1ULL << 0x2B)
#endif
#endif

#ifdef ENABLE_RGB_MATRIX_XAP_DIRECT
    | (1ULL << 0x2C)
#endif
};
#endif //RGB_MATRIX_ENABLE
#ifdef LED_MATRIX_ENABLE
static uint8_t led_matrix_effect_map[][2] = {

#ifdef ENABLE_LED_MATRIX_SOLID
    { 0x00, LED_MATRIX_SOLID},
#endif

#ifdef ENABLE_LED_MATRIX_ALPHAS_MODS
    { 0x01, LED_MATRIX_ALPHAS_MODS},
#endif

#ifdef ENABLE_LED_MATRIX_BREATHING
    { 0x02, LED_MATRIX_BREATHING},
#endif

#ifdef ENABLE_LED_MATRIX_BAND
    { 0x03, LED_MATRIX_BAND},
#endif

#ifdef ENABLE_LED_MATRIX_BAND_PINWHEEL
    { 0x04, LED_MATRIX_BAND_PINWHEEL},
#endif

#ifdef ENABLE_LED_MATRIX_BAND_SPIRAL
    { 0x05, LED_MATRIX_BAND_SPIRAL},
#endif

#ifdef ENABLE_LED_MATRIX_CYCLE_LEFT_RIGHT
    { 0x06, LED_MATRIX_CYCLE_LEFT_RIGHT},
#endif

#ifdef ENABLE_LED_MATRIX_CYCLE_UP_DOWN
    { 0x07, LED_MATRIX_CYCLE_UP_DOWN},
#endif

#ifdef ENABLE_LED_MATRIX_CYCLE_OUT_IN
    { 0x08, LED_MATRIX_CYCLE_OUT_IN},
#endif

#ifdef ENABLE_LED_MATRIX_DUAL_BEACON
    { 0x09, LED_MATRIX_DUAL_BEACON},
#endif

#ifdef ENABLE_LED_MATRIX_WAVE_LEFT_RIGHT
    { 0x0A, LED_MATRIX_WAVE_LEFT_RIGHT},
#endif

#ifdef ENABLE_LED_MATRIX_WAVE_UP_DOWN
    { 0x0B, LED_MATRIX_WAVE_UP_DOWN},
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_SIMPLE
    { 0x0C, LED_MATRIX_SOLID_REACTIVE_SIMPLE},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_WIDE
    { 0x0D, LED_MATRIX_SOLID_REACTIVE_WIDE},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTIWIDE
    { 0x0E, LED_MATRIX_SOLID_REACTIVE_MULTIWIDE},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_CROSS
    { 0x0F, LED_MATRIX_SOLID_REACTIVE_CROSS},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTICROSS
    { 0x10, LED_MATRIX_SOLID_REACTIVE_MULTICROSS},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_NEXUS
    { 0x11, LED_MATRIX_SOLID_REACTIVE_NEXUS},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTINEXUS
    { 0x12, LED_MATRIX_SOLID_REACTIVE_MULTINEXUS},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_SPLASH
    { 0x13, LED_MATRIX_SOLID_SPLASH},
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_MULTISPLASH
    { 0x14, LED_MATRIX_SOLID_MULTISPLASH},
#endif
#endif
};

uint8_t led_matrix2xap(uint8_t val) {
    for(uint8_t i = 0; i < ARRAY_SIZE(led_matrix_effect_map); i++) {
        if (led_matrix_effect_map[i][1] == val)
            return led_matrix_effect_map[i][0];
    }
    return 0xFF;
}

uint8_t xap2led_matrix(uint8_t val) {
    for(uint8_t i = 0; i < ARRAY_SIZE(led_matrix_effect_map); i++) {
        if (led_matrix_effect_map[i][0] == val)
            return led_matrix_effect_map[i][1];
    }
    return 0xFF;
}
enum { ENABLED_LED_MATRIX_EFFECTS = 0

#ifdef ENABLE_LED_MATRIX_SOLID
    | (1ULL << 0x00)
#endif

#ifdef ENABLE_LED_MATRIX_ALPHAS_MODS
    | (1ULL << 0x01)
#endif

#ifdef ENABLE_LED_MATRIX_BREATHING
    | (1ULL << 0x02)
#endif

#ifdef ENABLE_LED_MATRIX_BAND
    | (1ULL << 0x03)
#endif

#ifdef ENABLE_LED_MATRIX_BAND_PINWHEEL
    | (1ULL << 0x04)
#endif

#ifdef ENABLE_LED_MATRIX_BAND_SPIRAL
    | (1ULL << 0x05)
#endif

#ifdef ENABLE_LED_MATRIX_CYCLE_LEFT_RIGHT
    | (1ULL << 0x06)
#endif

#ifdef ENABLE_LED_MATRIX_CYCLE_UP_DOWN
    | (1ULL << 0x07)
#endif

#ifdef ENABLE_LED_MATRIX_CYCLE_OUT_IN
    | (1ULL << 0x08)
#endif

#ifdef ENABLE_LED_MATRIX_DUAL_BEACON
    | (1ULL << 0x09)
#endif

#ifdef ENABLE_LED_MATRIX_WAVE_LEFT_RIGHT
    | (1ULL << 0x0A)
#endif

#ifdef ENABLE_LED_MATRIX_WAVE_UP_DOWN
    | (1ULL << 0x0B)
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_SIMPLE
    | (1ULL << 0x0C)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_WIDE
    | (1ULL << 0x0D)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTIWIDE
    | (1ULL << 0x0E)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_CROSS
    | (1ULL << 0x0F)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTICROSS
    | (1ULL << 0x10)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_NEXUS
    | (1ULL << 0x11)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_REACTIVE_MULTINEXUS
    | (1ULL << 0x12)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_SPLASH
    | (1ULL << 0x13)
#endif
#endif

#ifdef LED_MATRIX_KEYREACTIVE_ENABLED

#ifdef ENABLE_LED_MATRIX_SOLID_MULTISPLASH
    | (1ULL << 0x14)
#endif
#endif
};
#endif //LED_MATRIX_ENABLE
