#include "jd45.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _SYSTEM 5

// Keycodes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  SYSTEM
};
/*
enum macro_keycodes {
  KC_ALT_TAB,
  KC_CMD_TAB,
  KC_CTL_TAB,
  KC_CMD_SLSH,
  KC_AG_FIND,
  KC_AG_AGAIN,
  KC_AG_UNDO,
  KC_AG_CUT,
  KC_AG_COPY,
  KC_AG_PASTE,
  KC_AG_DESK_L,
  KC_AG_DESK_R,
  KC_AG_TAB_C,
  KC_AG_TAB_N,
  KC_AG_TAB_R,
};
*/
// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Tap ´n´ Hold
//// Requires KC_TRNS/_______ for the trigger key in the destination layer
#define LT_LOWER    LT(_LOWER, KC_SPC)          // L-ayer T-ap Lower / Space
#define LT_RAISE    LT(_RAISE, KC_SPC)          // L-ayer T-ap Raise / Space

/* Qwerty
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+------+------.
 * |  Esc    |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   =  | Bksp |
 * |---------`------`------`------`------`------`------`------`------`------`------`------`------|
 * |  Tab    |   A  |   S  |   D |   F  |   G  |   H  |   J  |   K  |   L  |   ;    |  Enter     |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |   Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  Shift    |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |   Ctrl | System|  Alt  |  GUI  |Lower/Spc |Raise/Spc | GUI     |  Alt   | System |  Ctrl    |
 *  `-------+-------+-------+-------+---^^^----+---^^^----+---------+--------+--------+----------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_JD45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.*/
    KC_ESC ,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,KC_EQUAL, KC_BSPC,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------|*/
    KC_TAB  ,  KC_A ,  KC_S  ,  KC_D  ,  KC_F  ,   KC_G ,  KC_H  ,   KC_J ,  KC_K  ,   KC_L ,KC_SCLN ,     KC_ENT     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
     KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    KC_LCTL  ,  SYSTEM   , KC_LALT   ,  KC_LGUI  ,  LT_LOWER ,  LT_RAISE , KC_RGUI   ,  KC_RALT  , SYSTEM    ,KC_RCTL),
/*`----------+-----------+-----------+-----------+----^^^----+----^^^----+-----------+-----------+-----------+--------'*/

/* Lower
 * ,---------+------+------+------+------+------+------+------+------+------+------+------+------.
 * |         |      |      |      |      |      | End  | PgUp |  Up  | PgDwn|      |  [  |   ]   |
 * |---------`------`------`------`------`------`------`------`------`------`------`------`------|
 * |          |      |      |     |      |      | Home |  Left |Down | Right |  END  |    '      |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           |      |      |      |      |      |      |      |      |      |  \   |           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |        |       |       |       |          |          |         |        |        |          |
 *  `-------+-------+-------+-------+---^^^----+---^^^----+---------+--------+--------+----------'
 */
[_LOWER] = KEYMAP_JD45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.*/
   _______ ,_______,_______ , _______, _______, _______, KC_END, KC_PGUP,  KC_UP , KC_PGDN, KC_MINS , KC_LBRC, KC_RBRC,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------|*/
    _______ , _______,_______,_______, _______,   _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,KC_END,   KC_QUOT      ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,_______,_______,_______,_______,  _______,  _______, _______, _______, _______, KC_BSLASH,   _______    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______  ,    _______,    _______,    _______,  _______  ,  _______  ,    _______,  _______,    _______, _______),
/*`----------+-----------+-----------+-----------+----^^^----+----^^^----+-----------+-----------+-----------+--------'*/

/* Raise
 * ,---------+------+------+------+------+------+------+------+------+------+------+------+------.
 * |   ~     |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |  [   |   ]  |
 * |---------`------`------`------`------`------`------`------`------`------`------`------`------|
 * |   1      |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  0  |   -  |     =      |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           |      |      |      |      |      |      |      |      |      |      |           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |        |       |       |       |          |          |         |        |        |          |
 *  `-------+-------+-------+-------+---^^^----+---^^^----+---------+--------+--------+----------'
 */
[_RAISE] = KEYMAP_JD45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.*/
   KC_GRAVE,  KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,   KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,  KC_0  , KC_MINS, KC_EQUAL,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------|*/
    _______ , KC_EXLM , KC_AT,  KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    _______     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______ ,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______     ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______  ,    _______,    _______,    _______,  _______  ,  _______  ,    _______,  _______,  _______, _______),
/*`----------+-----------+-----------+-----------+----^^^----+----^^^----+-----------+-----------+-----------+--------'*/

/* System
 * ,---------+------+------+------+------+------+------+------+------+------+------+------+------.
 * |  Reset  |  F1  | F2   | F3   | F4   | F5   | F6   |  F7  | F8   |  F9  | F10  | F11  | Sleep |
 * |---------`------`------`------`------`------`------`------`------`------`------`------`------|
 * |          | Prev | Play  |Next |      |      |      |      |      |      |     |             |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           |      |VolDwn|VolUp|      |      |      |      |      |      |      |           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |        |       |       |       |          |          |         |        |        |          |
 *  `-------+-------+-------+-------+---^^^----+---^^^----+---------+--------+--------+----------'
 */

[_SYSTEM = KEYMAP_JD45(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.*/
    RESET,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_SLEP  ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------`--------|*/
    _______ , KC_MRWD,KC_MPLY,KC_MFFD, _______,   _______, _______, _______, _______, _______, _______,   _______     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,_______,KC__VOLDOWN, KC__VOLUP,_______,_______,_______, _______, _______, _______, _______,    _______      ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______  ,    _______,    _______,    _______,  _______  ,  _______  ,    _______,  _______,    _______, _______)
/*`----------+-----------+-----------+-----------+----^^^----+----^^^----+-----------+-----------+-----------+--------'*/
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _SYSTEM);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _SYSTEM);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _SYSTEM);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _SYSTEM);
      }
      return false;
      break;
    case SYSTEM:
      if (record->event.pressed) {
        layer_on(_SYSTEM);
        update_tri_layer(_LOWER, _RAISE, _SYSTEM);
      } else {
        layer_off(_SYSTEM);
        update_tri_layer(_LOWER, _RAISE, _SYSTEM);
      }
      return false;
      break;
  }
  return true;
}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
/*
    bool use_cmd = true;    // Use, for example, Cmd-Tab, Cmd-C, Cmd-V, etc.
    // Compare to MAGIC_SWAP_ALT_GUI and MAGIC_UNSWAP_ALT_GUI configs, set in:
    // quantum/quantum.c
    if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) {
      use_cmd = false;      // ... or, Alt-Tab, Ctrl-C, Ctrl-V, etc.
    }


    switch (id) {
      case KC_ALT_TAB:
        if(use_cmd) { return (record->event.pressed ? MACRO( D(LALT),  D(TAB), END ) : MACRO( U(TAB), END )); }
        else        { return (record->event.pressed ? MACRO( D(LGUI),  D(TAB), END ) : MACRO( U(TAB), END )); }
      case KC_CMD_TAB:
        if(use_cmd) { return (record->event.pressed ? MACRO( D(LGUI),  D(TAB), END ) : MACRO( U(TAB), END )); }
        else        { return (record->event.pressed ? MACRO( D(LALT),  D(TAB), END ) : MACRO( U(TAB), END )); }

      case KC_CTL_TAB:
        return (record->event.pressed ? MACRO( D(LCTRL), D(TAB), END ) : MACRO( U(TAB), END ));
      case KC_CMD_SLSH:
        return (record->event.pressed ? MACRO( D(LGUI),  D(SLSH),END ) : MACRO( U(SLSH),END ));

      case KC_AG_FIND:
        return use_cmd ? MACRODOWN( D(LGUI), T(F), END ) : MACRODOWN( D(LCTRL), T(F), END );
      case KC_AG_AGAIN:
        return use_cmd ? MACRODOWN( D(LGUI), T(G), END ) : MACRODOWN( D(LCTRL), T(G), END );
      case KC_AG_UNDO:
        return use_cmd ? MACRODOWN( D(LGUI), T(Z), END ) : MACRODOWN( D(LCTRL), T(Z), END );
      case KC_AG_CUT:
        return use_cmd ? MACRODOWN( D(LGUI), T(X), END ) : MACRODOWN( D(LCTRL), T(X), END );
      case KC_AG_COPY:
        return use_cmd ? MACRODOWN( D(LGUI), T(C), END ) : MACRODOWN( D(LCTRL), T(C), END );
      case KC_AG_PASTE:
        return use_cmd ? MACRODOWN( D(LGUI), T(V), END ) : MACRODOWN( D(LCTRL), T(V), END );

      case KC_AG_DESK_L:
        return use_cmd ? MACRODOWN( D(LGUI), D(LCTRL), T(SCLN), END ) : MACRODOWN( D(LALT), D(LCTRL), T(SCLN), END );
      case KC_AG_DESK_R:
        return use_cmd ? MACRODOWN( D(LGUI), D(LCTRL), T(QUOT), END ) : MACRODOWN( D(LALT), D(LCTRL), T(QUOT), END );

      case KC_AG_TAB_C:
        return use_cmd ? MACRODOWN( D(LGUI),            T(W), END ) : MACRODOWN( D(LCTRL),            T(W), END );
      case KC_AG_TAB_N:
        return use_cmd ? MACRODOWN( D(LGUI),            T(T), END ) : MACRODOWN( D(LCTRL),            T(T), END );
      case KC_AG_TAB_R:
        return use_cmd ? MACRODOWN( D(LGUI), D(LSHIFT), T(T), END ) : MACRODOWN( D(LCTRL), D(LSHIFT), T(T), END );
    }
*/
    return MACRO_NONE;
}
