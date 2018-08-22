#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_RGHT KC_RIGHT

// Defines for task manager and such
//#define CALTDEL LCTL(LALT(KC_DEL))
//#define TSKMGR LCTL(LSFT(KC_ESC))
#define LT_LOWR    LT(_LOWER, KC_SPC)          // L-ayer T-ap Lower / Space
#define LT_RAIS    LT(_RAISE, KC_SPC)          // L-ayer T-ap Raise / Space

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------------------------------------------------------------------.
 * | Esc   |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Tab   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |   "   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Ctrl  | Adjust| Alt   |  GUI  | Lower | Space | Space | Raise | Lower |  Alt  | Adjust| Ctrl  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
    KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC, \
    KC_TAB, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_ENT,  \
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,RSFT_T(KC_QUOT), \
    KC_LCTL,ADJUST, RAISE, KC_LALT, KC_LGUI,LT_LOWR,LT_RAIS,KC_RGUI,KC_RALT,LOWER,  ADJUST ,KC_RCTL  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |   ~   |       |       |       |       |       |       | PGUP  |  Up   | PGDN  |   [   |   ]   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       | HOME  | Left  | Down  | Right |   (   |   )   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |   -   |   =   |   \   |  |    |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       | Next  | Vol-  | Vol+  | Play  |
 * `-----------------------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT( \
    KC_GRV ,_______,_______,_______,_______,_______,_______,KC_PGUP,KC_UP,  KC_PGDN,KC_LBRC,KC_RBRC, \
    _______,_______,_______,_______,_______,_______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_LPRN,KC_RPRN, \
    _______,_______,_______,_______,_______,_______,_______,_______,KC_MINS,KC_EQL ,KC_RCBR,KC_PIPE, \
    _______,_______,_______,_______,_______,_______,_______,_______,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |  =    |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F11  |  F12  |       |       |       |   /   |  [    |   ]   |   |   |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,  \
    _______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, _______, \
    _______,KC_F11, KC_F12, _______,_______,_______,KC_SLSH,KC_LBRC,KC_RBRC,KC_PIPE,_______,_______, \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______  \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------------------.
 * | Reset |       | Vol+  |Aud Off|       |       |       |       |  PgUp |       |       | Sleep |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * |       | Stop  | Vol-  | Play  |       |       |       | Home  |PgDown | End   |       | Wake  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       | Mute  |       |       |       |       |       |       |       |       |PwrDown|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
    RESET,  _______,KC_VOLU,_______,_______,_______,_______,_______,KC_PGUP,_______,_______,KC_SLEP, \
    _______,KC_MSTP,KC_VOLD,KC_MPLY,_______,_______,_______,KC_HOME,KC_PGDN,KC_END, _______,KC_WAKE, \
    _______,_______,KC_MUTE,_______,_______,_______,_______,_______,_______,_______,_______,KC_PWR,  \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______  \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
