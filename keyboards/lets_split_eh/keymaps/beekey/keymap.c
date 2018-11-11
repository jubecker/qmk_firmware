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
#define KC_RGHT KC_RIGHT

#define KC_EURO   LSFT(LALT(KC_2))
#define LT_LOWR   LT(_LOWER, KC_SPC)          // L-ayer T-ap Lower / Space
#define LT_F      LT(_LOWER, KC_F)
#define LT_RAIS   LT(_RAISE, KC_SPC)          // L-ayer T-ap Raise / Space

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * | Esc   |   Q   |   W   |   E   |   R   |   T   ||   Y   |   U   |   I   |   O   |   P   | Bksp  |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Tab   |   A   |   S   |   D   |   F   |   G   ||   H   |   J   |   K   |   L   |   ;   | Enter |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   ||   N   |   M   |   ,   |   .   |   /   |   "   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * | Ctrl  | Raise | Adjust|  Alt  | Gui   | LW_SPC|| RS_SPC|   [   |   ]   | Adjust|   -   |   =   |
 * `------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
    KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC, \
    KC_TAB, KC_A,   KC_S,   KC_D,   LT_F,   KC_G,    KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_ENT,  \
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,RSFT_T(KC_QUOT), \
    KC_LCTL,RAISE,  ADJUST, KC_LALT,KC_LGUI,LT_LOWR, LT_RAIS,KC_LBRC,KC_RBRC,ADJUST, KC_MINS,KC_EQL \
),

/* Lower
 * ,------------------------------------------------------------------------------------------------.
 * |   ~   |       | Vol+  |   €   |       |       ||       | PgDn  | Up    | PgUp  |   [   |   ]   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       | Stop  | Mute  | Play  |       |       || Home  | Left  | Down  | Right |  End  |   "   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       | Vol-  |       |       |       ||   ~   |       |       |       |   \   |   |   |
 * |-------+-------+-------+-------+-------+-------++-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       ||       |       |       |       |       |       |
 * `------------------------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT(
    KC_TILD,_______,KC_VOLU,KC_EURO,_______,_______, _______,KC_PGDN,KC_UP,  KC_PGUP,KC_LBRC,KC_RBRC, \
    _______,KC_MSTP,KC_MUTE,KC_MPLY,_______,_______, KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, KC_QUOT, \
    _______,_______,KC_VOLD,_______,_______,_______, KC_TILD,_______,_______,_______,KC_BSLS,KC_PIPE, \
    _______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   "   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |   [   |   ]   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,  KC_MINS,KC_EQL,  \
    KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_LBRC,KC_RBRC, \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______  \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------------------.
 * | Reset |       |       |       |       |       |       |       |       |       |       | Reset |
 * |-------+-------+-------+-------+-------+---------------+-------+-------+-------+-------+-------|
 * |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  | Sleep |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       | Wake  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
    RESET,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET,   \
    KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_SLEP, \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_WAKE, \
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

