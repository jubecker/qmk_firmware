/*
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

// Layer shorthand
enum layer {
  _2UARROW,
  _LOWER,
  _RAISE

};

#define LT_LWR    LT(1, KC_SPC)          // L-ayer T-ap Lower / Space
#define KC_EURO   LSFT(LALT(KC_2))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | BACKSP | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      |  \     |   \    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTR   | LCTR   | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | ENTER  | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | SHIFT  | SHIFT  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LCTL   | Raise  | Lower  | LALT   | LGUI   |      SPACE      | SPACE  | LEFT   | DOWN   | Up     | RIGHT  | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_2UARROW] = LAYOUT_ortho_5x14(
    KC_ESC,  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC_BSPC, \
    KC_TAB,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, KC_BSLS, \
    KC_LCTL, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  KC_ENT,  \
    KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT, \
    KC_LCTL, KC_LCTL, MO(2),   MO(1),   KC_LALT, KC_LGUI, LT_LWR,  LT_LWR,  LT_LWR,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RGHT  \
 ),

/* Lower
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |  ~     |  ~     | !      | @      | #      | $      | %      | ^      | &      | *      | -      | =      | Bksp   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | Vol+   | €      |        |        |        | PgUp   | Up     | PgDn   | [      | ]      | ]      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | Prev   | Stop   | Mute   | Play   | Next   |        | Home   | Left   | Down   | Right  | End    | "      | "      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | Vol-   |        |        |        | ~      |        |        |        | \      | |      | |      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |                 |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_LOWER] = LAYOUT_ortho_5x14(
     KC_GRV, KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, \
    _______, _______, _______, KC_VOLU, KC_EURO, _______, _______, _______, KC_PGUP, KC_UP  , KC_PGDN, KC_LBRC, KC_RBRC, KC_RBRC, \
    _______, KC_MPRV, KC_MSTP, KC_MUTE, KC_MPLY, KC_MNXT, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , KC_QUOT, KC_QUOT, \
    _______, _______, _______, KC_VOLD, _______, _______, _______, KC_TILD, _______, _______, _______, KC_BSLS, KC_PIPE, KC_PIPE, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* Raise
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |  Reset |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |   F10  |  F11   |  F12   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        | Wake   |        |        | Reset  |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        | Sleep  |        |        |        |        |        |        |        |        |        | Power  | Power  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |                 |                 |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_RAISE] = LAYOUT_ortho_5x14(
    RESET  , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , _______, \
    _______, _______, KC_WAKE, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PWR,  KC_PWR,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 )
};
