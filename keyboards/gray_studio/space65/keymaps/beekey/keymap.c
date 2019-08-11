/* Copyright 2019 MechMerlin
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

#define LT_SPC    LT(1, KC_SPC)          // L-ayer T-ap Lower / Space
#define LT_F      LT(1, KC_F)            // L-ayer T-ap Lower / F

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,    KC_BSPC,  \
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,             KC_VOLU,  \
    KC_LCTL, KC_A,    KC_S,   KC_D,   LT_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                       KC_VOLD, \
    KC_LSFT, KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,             KC_UP,   MO(1), \
    KC_LCTL, KC_LGUI, KC_LALT,                KC_LGUI, LT_SPC, KC_SPC,            KC_RALT, MO(2),                    KC_LEFT, KC_DOWN, KC_RGHT  \
),
[1] = LAYOUT( \
    KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11, KC_F12, _______, _______, _______, \
    _______, KC_MPRV, KC_VOLU, KC_MNXT, _______, _______, _______, KC_PGUP, KC_UP, KC_PGDN, _______, _______, _______, _______,        KC_SLEP, \
    _______, KC_MSTP, KC_VOLD, KC_MPLY, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______, _______,               KC_WAKE, \
    _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_PGUP, _______, \
    _______, _______, _______,                _______, _______, _______,          _______, _______,                  KC_HOME, KC_PGDN, KC_END   \
),
[2] = LAYOUT( \
    _______, _______, _______, _______,_______, _______, _______, _______,_______, _______, _______, _______, _______,_______, _______,RESET,   \
    _______, RGB_HUI, RGB_VAI, RGB_SAI, RGB_MOD, _______, BL_TOGG, BL_INC, 	BL_STEP, _______, _______, _______, _______, _______,      _______, \
    _______, RGB_HUD, RGB_VAD, RGB_SAD, RGB_RMOD,_______, _______, BL_DEC, _______, _______, _______, _______, _______,                _______, \
    _______, _______, _______, RGB_TOG, RGB_M_P, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, \
    _______, _______, _______,                _______, _______, _______,          _______, _______,                  _______, _______, _______  \
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) { }

void matrix_scan_user(void) { }

void led_set_user(uint8_t usb_led) { }
