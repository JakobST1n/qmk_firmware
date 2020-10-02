/*
Copyright 2020 jakobst1n

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*******************************************
 * SLEEPMODE CONFIG
 *******************************************/
#define SLEEPMODE_ENABLE
#ifdef SLEEPMODE_ENABLE
    /* How long the backlight should stay on
       without any interaction before turning off. */
    #define SLEEPMODE_TIMEOUT 2  // in minutes
    /* Which mode we should enter after the timeout,
       RGB_MATRIX_NONE to turn off.
       I thinks RGB_MATRIX_DIGITAL RAIN is pretty. */
    #define SLEEPMODE_RGB_MODE RGB_MATRIX_DIGITAL_RAIN
    /* The desired animation speed when in "sleep mode" */
    #define SLEEPMODE_RGB_ANIMATION_SPEED 10
    /* The desired brightness when in "sleep mode" */
    #define SLEEPMODE_RGB_VAL 10
#endif

/*******************************************
 * LAYER PER KEY LIGHTING
 *******************************************/
#define LAYER_LIGHTING_ENABLE
#ifdef LAYER_LIGHTING_ENABLE
    /* This is for keys that should not be changed on a certain layer.
       Which means, either the base rgb_matrix mode will affect that led,
       or a lower layer could potentially affect it. */
    #define MAP_TRANS 0xF000000
    /* This is used for other keys, set to MAP_TRANS instead of 0x0 for having
       the unchanged effect on those leds */
    #define MAP_DEF   0x0
#endif

/*******************************************
 * RGB_MATRIX CONFIG
 *******************************************/
// #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 250 /* The maximum brightness level */
#define RGB_MATRIX_STARTUP_VAL 150
#define RGB_MATRIX_STARTUP_HUE 130
#define RGB_MATRIX_STARTUP_SAT 180
#define RGB_MATRIX_KEYPRESSES
//#define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8
/*== all animations enable ==*/
#define RGBLIGHT_ANIMATIONS
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// /*== or choose animations ==*/
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
