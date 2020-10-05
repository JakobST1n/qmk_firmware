/* Copyright 2020 jakobst1n
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
    #ifdef SLEEPMODE_ENABLE
        static bool sleepmode_on = false;
        static uint8_t sleepmode_before_mode = -1;
        static uint8_t sleepmode_before_brightness = -1;
        static uint8_t sleepmode_before_anim_speed = -1;
        static uint8_t halfmin_counter = 0;
        static uint16_t idle_timer = 0;
    #endif
    #ifdef LAYER_LIGHTING_ENABLE
        enum layer_lighting_type{
            NORMAL,
            MAP
        };
    #endif
#endif

/* Custom keycodes that fits my liking, currently one.
   but lets plan for expandability ;) */
enum JAKOBST1N_KEYCODES {
    JKC_GRAVE
};

/* ,-----------------------------------------------------------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
 * |-----------------------------------------------------------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
 * |------------------------------------------------------\    |
 * |      |   |   |   |   |   |   |   |   |   |   |   |   |    |
 * |-----------------------------------------------------------|
 * |    |   |   |   |   |   |   |   |   |   |   |      |   |   |
 * |-----------------------------------------------------------|
 * |    |    |    |                            |   |   |   |   |
 * `-----------------------------------------------------------' */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ,-----------------------------------------------------------.
     * |ESC| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | + | ´ |  BACK |
     * |-----------------------------------------------------------|
     * | TAB | Q | W | E | R | T | Y | U | I | O | P | Å | ¨ |     |
     * |------------------------------------------------------\    |
     * | CAPS | A | S | D | F | G | H | J | K | L | Ø | Æ | @ |    |
     * |-----------------------------------------------------------|
     * | ^  | < | Z | X | C | V | B | N | M | , | . |  ^/- | U | - |
     * |-----------------------------------------------------------|
     * |ctrl| win| alt|                        |alt| fn| L | D | R |
     * `-----------------------------------------------------------' */
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,  KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MT(MOD_RSFT, KC_SLSH),  KC_UP,  JKC_GRAVE,
        KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC,                              KC_RALT, OSL(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* ,-----------------------------------------------------------.
     * |GRA| f1| f2| f3| f4| f5| f6| f7| f8| f9|f10|f11|f12|  DEL  |
     * |-----------------------------------------------------------|
     * |     | R | R | R | R | R | R | R | R |   |   |   |   |     |
     * |------------------------------------------------------\    |
     * |      |   |   |   |   |   | H |PGD|PGU| E |   |   |   |    |
     * |-----------------------------------------------------------|
     * |    |   |   |   |   |   |   |   |   |   |   |      |V_D|V_U|
     * |-----------------------------------------------------------|
     * |    |    |    |                            |   |PRE|PLA|NEX|
     * `-----------------------------------------------------------' */
    [1] = LAYOUT(
        KC_GRAVE,   KC_F1,   KC_F2,     KC_F3, KC_F4,     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_DEL,
         _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU,
         _______, _______, _______,                      _______,                         _______,  OSL(2), KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
    ),
    [2] = LAYOUT(
         OSL(3), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                      _______,                         _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, EEP_RST,   RESET, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,   DEBUG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                      _______,                         _______, _______, _______, _______, _______
    ),
};

#ifdef RGB_MATRIX_ENABLE
    #ifdef LAYER_LIGHTING_ENABLE
        const uint8_t layer_lighting_types[] = {
            [0] = NORMAL,
            [1] = MAP,
            [2] = MAP,
            [3] = MAP
        };
        const uint32_t layer_lighting_map[][MATRIX_ROWS][MATRIX_COLS] = {
            [0] = {
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,                        ________,                                   ________,  ________,  ________,  ________,  ________}
            },
            [1] = {
                { 0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF0000},
                { ________,  _TRANS__,  0x00FF00,  _TRANS__,  _TRANS__,  0x00FF00,  0x00FF00,  _TRANS__,  _TRANS__,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  0xFF00FE,  0xFF00FE,  0xFF00FE,  0xFF00FE,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  0xFF00FE,   0xFF00FE},
                { ________,  ________,  ________,                        ________,                                   ________,  ________,  0xFF00FE,   0xFF00FE,   0xFF00FE}
            },
            [2] = {
                { 0xFF0000,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,                        ________,                                   ________,  ________,  ________,  ________,  ________}
            },
            [3] = {
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  0xFF7700,  0xFF0000,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  0x00FF00,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________,  ________},
                { ________,  ________,  ________,                        ________,                                   ________,  ________,  ________,  ________,  ________}
            }
        };
    #endif
#endif

void rgb_matrix_indicators_user(void) {
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(28, 255, 0, 0);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    #ifdef RGB_MATRIX_ENABLE
        #ifdef SLEEPMODE_ENABLE
            if (record->event.pressed) {
                if (sleepmode_before_mode == -1) { sleepmode_before_mode = rgb_matrix_get_mode(); }
                if (sleepmode_before_brightness == -1) { sleepmode_before_brightness = rgb_matrix_get_val(); }
                if (sleepmode_before_anim_speed == -1) { sleepmode_before_anim_speed = rgb_matrix_get_speed(); }

                if (sleepmode_on == true) {
                    rgb_matrix_mode_noeeprom(sleepmode_before_mode);
                    rgb_matrix_set_speed_noeeprom(sleepmode_before_anim_speed);
                    rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), rgb_matrix_get_sat(), sleepmode_before_brightness);
                    sleepmode_on = false;
                }
                idle_timer = timer_read();
                halfmin_counter = 0;
            }
        #endif
    #endif

    switch(keycode) {
        case JKC_GRAVE: {
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    register_code(KC_SLSH);
                } else {
                    register_code(KC_GRAVE);
                }
            } else {
                unregister_code(KC_SLSH);
                unregister_code(KC_GRAVE);
            }
            return false;
            break;
        }
    }
    return true;
 }

 void matrix_scan_user(void) {
    #ifdef RGB_MATRIX_ENABLE
        #ifdef SLEEPMODE_ENABLE
            if (idle_timer == 0) idle_timer = timer_read();

            if ( !sleepmode_on && timer_elapsed(idle_timer) > 30000) {
                halfmin_counter++;
                idle_timer = timer_read();
            }

            if ( !sleepmode_on && halfmin_counter >= SLEEPMODE_TIMEOUT * 2) {// * 2) {
                layer_clear();
                sleepmode_before_anim_speed = rgb_matrix_get_speed();
                sleepmode_before_brightness = rgb_matrix_get_val();
                sleepmode_before_mode = rgb_matrix_get_mode();

                rgb_matrix_mode_noeeprom(SLEEPMODE_RGB_MODE);
                rgb_matrix_set_speed_noeeprom(SLEEPMODE_RGB_ANIMATION_SPEED);
                rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), rgb_matrix_get_sat(), SLEEPMODE_RGB_VAL);
                sleepmode_on = true;
                halfmin_counter = 0;
            }
        #endif

        #ifdef LAYER_LIGHTING_ENABLE
            uint8_t layer = biton32(layer_state);

            if (layer_lighting_types[layer] == MAP) {
                uint16_t led = 0;
                uint32_t hexValue;
                for (int y = 0; y < MATRIX_ROWS; y++) {
                    for (int x = 0; x < MATRIX_COLS; x++) {
                        hexValue = layer_lighting_map[layer][y][x];
                        if ((hexValue >> 24) > 0) { led++; continue; }
                        rgb_matrix_set_color(
                            led,
                            ((hexValue >> 16) & 0xFF),
                            ((hexValue >>  8) & 0xFF),
                            ((hexValue      ) & 0xFF)
                        );
                        led++;
                    }
                }
            }
        #endif
    #endif
}
