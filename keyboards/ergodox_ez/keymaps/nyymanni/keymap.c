#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE        0 // Default layer
#define SYMB        1 // Symbol layer
#define MOVEMENT    2 // Arrow keys, window manager
#define FINNISH     3 // Layer for typing nordic characters
#define US_OVERRIDE 4 // Layer for temporarily typing keys from US layout
/* #define MDIA 2 // media keys */



/* Nordic keys are implemented as macros */
#define FI_AE 2
#define FI_OE 3

#define _______ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  #   |           |  *   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc/Cmd|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | '/Cmd  |
 * |--------+------+------+------+------+------|  ^   |           |  $   |------+------+------+------+------+--------|
 * | LAlt   |Z/Shft|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Shft| -/RAlt |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|      |   (  |   )  | Ctrl |                                       | Ctrl |   [  |   ]  |      | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(FINNISH),
        KC_DELT,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_HASH,
        GUI_T(KC_ESC),  KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_RALT,        SFT_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   KC_CIRC,
        MO(MOVEMENT),   MO(SYMB),     KC_LPRN,KC_RPRN,KC_LCTRL,
                                              KC_VOLD,  KC_VOLU,
                                                              KC_HOME,
                                               KC_BSPC,KC_TAB,KC_END,
        // right hand
             TG(FINNISH), KC_6,   KC_7,    KC_8,   KC_9,   KC_0,           KC_EQL,
             KC_ASTR,     KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,           KC_BSLS,
                          KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,        GUI_T(KC_QUOT),
             KC_DLR,      KC_N,   KC_M,    KC_COMM,KC_DOT, SFT_T(KC_SLSH), ALT_T(KC_MINS),
                                  KC_RCTRL,KC_LBRC,KC_RBRC,MO(SYMB),       KC_FN1,
             KC_MSTP,        KC_MPLY,
             KC_PGUP,
             KC_PGDN,KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Symbols
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
       _______,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,_______,
       _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,_______,
          EPRM,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,
       _______, KC_UP,   KC_P7,   KC_P8,    KC_P9,    KC_PAST, KC_F12,
                KC_DOWN, KC_P4,   KC_P5,    KC_P6,    KC_PPLS, _______,
       _______, KC_AMPR, KC_P1,   KC_P2,    KC_P3,    KC_PSLS, _______,
                         _______, KC_PDOT,  KC_P0,    _______, _______,
       KC_MPRV, KC_MNXT,
       _______,
       _______, _______, _______
),
/* Keymap 2: Movement keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/* MEDIA AND MOUSE */
[MOVEMENT] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, LGUI(KC_F10), LGUI(KC_F15), // Start screen saver
       _______,  _______, _______, _______, _______, _______, _______,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* MEDIA AND MOUSE */
[FINNISH] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, RALT(KC_A),
                 _______, _______, _______, _______, M(FI_OE), M(FI_AE),
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function

  switch (id) {
  case 0:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
  case 1:
    if (record->event.pressed) { // For resetting EEPROM
      eeconfig_init();
    }
    break;
  case FI_AE:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LSHIFT)) {
        /* Left shift pressed. */
        unregister_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(KC_U);
        unregister_code(KC_U);
        unregister_code(KC_RALT);
        register_code(KC_LSFT);
        register_code(KC_A);
        unregister_code(KC_A);
        return MACRO_NONE;

      } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
        /* Right shift pressed. */
        unregister_code(KC_RSFT);
        register_code(KC_RALT);
        register_code(KC_U);
        unregister_code(KC_U);
        unregister_code(KC_RALT);
        register_code(KC_RSFT);
        register_code(KC_A);
        unregister_code(KC_A);
        return MACRO_NONE;
      } else {
        return MACRO(D(RALT), T(U), U(RALT), T(A), END);
      }
    }
    break;
  case FI_OE:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LSHIFT)) {
        /* Left shift pressed. */
        unregister_code(KC_LSFT);
        register_code(KC_RALT);
        register_code(KC_U);
        unregister_code(KC_U);
        unregister_code(KC_RALT);
        register_code(KC_LSFT);
        register_code(KC_O);
        unregister_code(KC_O);
        return MACRO_NONE;

      } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
        /* Right shift pressed. */
        unregister_code(KC_RSFT);
        register_code(KC_RALT);
        register_code(KC_U);
        unregister_code(KC_U);
        unregister_code(KC_RALT);
        register_code(KC_RSFT);
        register_code(KC_O);
        unregister_code(KC_O);
        return MACRO_NONE;
      } else {
        return MACRO(D(RALT), T(U), U(RALT), T(O), END);
      }
    }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // dynamically generate these.
  case EPRM:
    if (record->event.pressed) {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case RGB_SLD:
    if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
#endif
    }
    return false;
    break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  case 3:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    break;
  default:
    // none
    break;
  }
};
