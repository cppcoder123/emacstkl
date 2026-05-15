/* Copyright 2026 cppcoder123
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

enum custom_keycodes  {
  /**/
  MACRO_AVY_GOTO_CHAR_TIMER = SAFE_RANGE,
  /**/
  MACRO_BUFFER_0,
  MACRO_BUFFER_1,
  MACRO_BUFFER_2,
  MACRO_BUFFER_3,
  MACRO_BUFFER_SWITCH,
  /**/
  MACRO_COMPILE,
  MACRO_COMPILE_AGAIN,
  /**/
  MACRO_CTL_ALT_DEL,		/* for M$ */
  /**/
  MACRO_FILE_OPEN,
  MACRO_FILE_SAVE,
  MACRO_MAGIT,
  MACRO_MAKE,
  MACRO_MAKE_CLEAN,
  MACRO_MAKE_J,                 /* parallel make*/
  MACRO_NEXT_ERROR,
  MACRO_SHIFT_INSERT,           /* for terminal */
  MACRO_TMUX_FOCUS_DOWN,	/* */
  MACRO_TMUX_FOCUS_NEXT,
  MACRO_TMUX_FOCUS_PREV,
  MACRO_TMUX_FOCUS_UP,
  MACRO_TMUX_NEW,
  MACRO_TMUX_SPLIT_H,
  MACRO_WIN_1,			/* ace-window: change focus to win 1 */
  MACRO_WIN_2,			/* focus to win 2 */
  MACRO_WIN_3,			/* focus to win 3 */
  MACRO_WIN_4,			/* focus to win 4 */
  MACRO_WIN_JUMP,		/* focus to other window */
};

/*

  KC_ESC,          KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,
  KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,
  KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,

  KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,   KC_PSCR,  KC_SCRL, KC_PAUS,
  KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_INS,   KC_HOME, KC_PGUP,
  KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_DEL,   KC_END,  KC_PGDN,
  KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,
  KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,                     KC_UP,
  KC_RALT, KC_RGUI, MO(1),  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RIGHT),

*/

#define EMACSTKL_LAYER_0 0
#define EMACSTKL_LAYER_1 1
#define EMACSTKL_LAYER_2 2
#define EMACSTKL_LAYER_3 3
/**/
#define EMACSTKL_LAYER_1_LED C0
#define EMACSTKL_LAYER_2_LED C1
#define EMACSTKL_LAYER_3_LED B5

#include "keymap-info.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [EMACSTKL_LAYER_0] = EMACSTKL_INFO_0,
  [EMACSTKL_LAYER_1] = EMACSTKL_INFO_1,
  [EMACSTKL_LAYER_2] = EMACSTKL_INFO_2,
  [EMACSTKL_LAYER_3] = EMACSTKL_INFO_3
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (!record->event.pressed)
    return true;

  switch (keycode) {
  case MACRO_AVY_GOTO_CHAR_TIMER:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "avy-goto-char-timer" SS_TAP (X_ENTER));
    return false;
    break;
  case MACRO_BUFFER_0:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_0));
    return false;
    break;
  case MACRO_BUFFER_1:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_1));
    return false;
    break;
  case MACRO_BUFFER_2:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_2));
    return false;
    break;
  case MACRO_BUFFER_3:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_3));
    return false;
    break;
  case MACRO_BUFFER_SWITCH:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_B));
    return false;
    break;
  case MACRO_COMPILE:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "compile" SS_TAP (X_ENTER));
    return false;
    break;
  case MACRO_COMPILE_AGAIN:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "recompile" SS_TAP (X_ENTER));
    return false;
    break;
  case MACRO_CTL_ALT_DEL:
      SEND_STRING (SS_LCTL(SS_LALT(SS_TAP (X_DELETE))));
      return false;
      break;
  case MACRO_FILE_OPEN:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_LCTL (SS_TAP (X_F)));
    return false;
    break;
  case MACRO_FILE_SAVE:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_LCTL (SS_TAP (X_S)));
    return false;
    break;
  case MACRO_MAGIT:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "magit" SS_TAP (X_ENTER));
    return false;
    break;
  case MACRO_MAKE:
    SEND_STRING ("make");
    return false;
    break;
  case MACRO_MAKE_CLEAN:
    SEND_STRING ("make clean");
    return false;
    break;
  case MACRO_MAKE_J:
    SEND_STRING ("make -j ");
    return false;
    break;
  case MACRO_NEXT_ERROR:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_GRV));
    return false;
    break;
  case MACRO_SHIFT_INSERT:
    SEND_STRING (SS_LSFT (SS_TAP (X_INS)));
    return false;
    break;
  case MACRO_TMUX_FOCUS_DOWN:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_DOWN));
    return false;
    break;
  case MACRO_TMUX_FOCUS_NEXT:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_N));
    return false;
    break;
  case MACRO_TMUX_FOCUS_PREV:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_P));
    return false;
    break;
  case MACRO_TMUX_FOCUS_UP:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_UP));
    return false;
    break;
  case MACRO_TMUX_NEW:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_C));
    return false;
    break;
  case MACRO_TMUX_SPLIT_H:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_LSFT (SS_TAP (X_QUOT)));
    return false;
    break;
  case MACRO_WIN_1:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_1));
    return false;
    break;
  case MACRO_WIN_2:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_2));
    return false;
    break;
  case MACRO_WIN_3:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_3));
    return false;
    break;
  case MACRO_WIN_4:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_4));
    return false;
    break;
  case MACRO_WIN_JUMP:
    SEND_STRING (SS_LALT (SS_TAP (X_O)));
    return false;
    break;
  }

  return true;
}

void keyboard_pre_init_user ()
{
  gpio_set_pin_output (EMACSTKL_LAYER_1_LED);
  gpio_set_pin_output (EMACSTKL_LAYER_2_LED);
  gpio_set_pin_output (EMACSTKL_LAYER_3_LED);
}

layer_state_t layer_state_set_user(layer_state_t state)
{
  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_1))
    gpio_write_pin_high (EMACSTKL_LAYER_1_LED);
  else
    gpio_write_pin_low (EMACSTKL_LAYER_1_LED);

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_2))
    gpio_write_pin_high (EMACSTKL_LAYER_2_LED);
  else
    gpio_write_pin_low (EMACSTKL_LAYER_2_LED);

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_3))
    gpio_write_pin_high (EMACSTKL_LAYER_3_LED);
  else
    gpio_write_pin_low (EMACSTKL_LAYER_3_LED);

  return state;
}

/*end of the file*/
