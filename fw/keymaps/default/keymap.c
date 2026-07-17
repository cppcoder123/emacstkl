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
  M_EMACS_AVY_GOTO_CHAR_TIMER = SAFE_RANGE,
  /**/
  M_EMACS_BUFFER_0,
  M_EMACS_BUFFER_1,
  M_EMACS_BUFFER_2,
  M_EMACS_BUFFER_3,
  M_EMACS_BUFFER_SWITCH,
  /**/
  M_EMACS_COMPILE,
  M_EMACS_COMPILE_AGAIN,
  /**/
  M_EMACS_DYNAMIC_EXPAND,
  M_EMACS_FILE_OPEN,
  M_EMACS_FILE_SAVE,
  M_EMACS_HIPPIE_EXPAND,
  M_EMACS_MAGIT,
  M_EMACS_NEXT_ERROR,
  M_EMACS_WIN_1,               /* ace-window: change focus to win 1 */
  M_EMACS_WIN_2,               /* focus to win 2 */
  M_EMACS_WIN_3,               /* focus to win 3 */
  M_EMACS_WIN_4,               /* focus to win 4 */
  M_EMACS_WIN_JUMP,            /* focus to other window */
  /**/
  M_TMUX_CTL_ALT_DEL,		/* for M$ */
  M_TMUX_MAKE,
  M_TMUX_MAKE_CLEAN,
  M_TMUX_MAKE_J,                /* parallel make*/
  M_TMUX_COPY_MODE,             /* */
  M_TMUX_PANE_FOCUS_DOWN,       /* */
  M_TMUX_PANE_FOCUS_LEFT,       /* */
  M_TMUX_PANE_FOCUS_RIGHT,      /* */
  M_TMUX_PANE_FOCUS_UP,
  M_TMUX_PANE_KILL,
  M_TMUX_PANE_MOVE_LEFT,
  M_TMUX_PANE_MOVE_RIGHT,
  M_TMUX_PANE_SPLIT_H,
  M_TMUX_PANE_SPLIT_V,
  M_TMUX_PANE_TO_WIN,
  M_TMUX_SHIFT_INSERT,          /* for terminal */
  M_TMUX_TIME,                  /* show the time */
  M_TMUX_WIN_0,                 /*select by number*/
  M_TMUX_WIN_1,
  M_TMUX_WIN_2,
  M_TMUX_WIN_3,
  M_TMUX_WIN_4,
  M_TMUX_WIN_5,
  M_TMUX_WIN_6,
  M_TMUX_WIN_7,
  M_TMUX_WIN_8,
  M_TMUX_WIN_9,
  M_TMUX_WIN_FIND,
  M_TMUX_WIN_LIST,
  M_TMUX_WIN_NAME,
  M_TMUX_WIN_NEXT,
  M_TMUX_WIN_NEW,
  M_TMUX_WIN_NUMBER,            /* change window number */
  M_TMUX_WIN_PREV,
  M_TMUX_WIN_SELECT,            /* by name */
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

#define EMACSTKL_LAYER_BASE 0
#define EMACSTKL_LAYER_HOME_ROW 1
#define EMACSTKL_LAYER_EMACS 2
#define EMACSTKL_LAYER_TMUX 3
/**/
#define EMACSTKL_LED_HOME_ROW C0
#define EMACSTKL_LED_EMACS C1
#define EMACSTKL_LED_TMUX B5

#include "keymap-info.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [EMACSTKL_LAYER_BASE] = EMACSTKL_INFO_BASE,
  [EMACSTKL_LAYER_HOME_ROW] = EMACSTKL_INFO_HOME_ROW,
  [EMACSTKL_LAYER_EMACS] = EMACSTKL_INFO_EMACS,
  [EMACSTKL_LAYER_TMUX] = EMACSTKL_INFO_TMUX
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (!record->event.pressed)
    return true;

  switch (keycode) {
  case M_EMACS_AVY_GOTO_CHAR_TIMER:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "avy-goto-char-timer" SS_TAP (X_ENTER));
    return false;
    break;
  case M_EMACS_BUFFER_0:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_0));
    return false;
    break;
  case M_EMACS_BUFFER_1:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_1));
    return false;
    break;
  case M_EMACS_BUFFER_2:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_2));
    return false;
    break;
  case M_EMACS_BUFFER_3:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_3));
    return false;
    break;
  case M_EMACS_BUFFER_SWITCH:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_B));
    return false;
    break;
  case M_EMACS_COMPILE:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "compile" SS_TAP (X_ENTER));
    return false;
    break;
  case M_EMACS_COMPILE_AGAIN:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "recompile" SS_TAP (X_ENTER));
    return false;
    break;
  case M_EMACS_DYNAMIC_EXPAND:
    SEND_STRING (SS_LALT (SS_TAP (X_SLSH)));
    return false;
    break;
  case M_EMACS_FILE_OPEN:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_LCTL (SS_TAP (X_F)));
    return false;
    break;
  case M_EMACS_FILE_SAVE:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_LCTL (SS_TAP (X_S)));
    return false;
    break;
  case M_EMACS_HIPPIE_EXPAND:
    SEND_STRING (SS_LALT (SS_TAP (X_SPC)));
    return false;
    break;
  case M_EMACS_MAGIT:
    SEND_STRING (SS_LALT (SS_TAP (X_X)) "magit" SS_TAP (X_ENTER));
    return false;
    break;
  case M_EMACS_NEXT_ERROR:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_GRV));
    return false;
    break;
  case M_EMACS_WIN_1:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_1));
    return false;
    break;
  case M_EMACS_WIN_2:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_2));
    return false;
    break;
  case M_EMACS_WIN_3:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_3));
    return false;
    break;
  case M_EMACS_WIN_4:
    SEND_STRING (SS_LALT (SS_TAP (X_O)) SS_TAP (X_4));
    return false;
    break;
  case M_EMACS_WIN_JUMP:
    SEND_STRING (SS_LALT (SS_TAP (X_O)));
    return false;
    break;
    /* */
  case M_TMUX_COPY_MODE:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_LBRC));
    return false;
    break;
  case M_TMUX_CTL_ALT_DEL:
    SEND_STRING (SS_LCTL(SS_LALT(SS_TAP (X_DELETE))));
    return false;
    break;
  case M_TMUX_MAKE:
    SEND_STRING ("make");
    return false;
    break;
  case M_TMUX_MAKE_CLEAN:
    SEND_STRING ("make clean");
    return false;
    break;
  case M_TMUX_MAKE_J:
    SEND_STRING ("make -j ");
    return false;
    break;
  case M_TMUX_PANE_FOCUS_DOWN:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_DOWN));
    return false;
    break;
  case M_TMUX_PANE_FOCUS_LEFT:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_LEFT));
    return false;
    break;
  case M_TMUX_PANE_FOCUS_RIGHT:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_RIGHT));
    return false;
    break;
  case M_TMUX_PANE_FOCUS_UP:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_UP));
    return false;
    break;
  case M_TMUX_PANE_KILL:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_X));
    return false;
    break;
  case M_TMUX_PANE_MOVE_LEFT:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_LSFT (SS_TAP (X_LBRC)));
    return false;
    break;
  case M_TMUX_PANE_MOVE_RIGHT:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_LSFT (SS_TAP (X_RBRC)));
    return false;
    break;
  case M_TMUX_PANE_SPLIT_H:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_LSFT (SS_TAP (X_QUOT)));
    return false;
    break;
  case M_TMUX_PANE_SPLIT_V:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_LSFT (SS_TAP (X_5)));
    return false;
    break;
  case M_TMUX_PANE_TO_WIN:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_LSFT (SS_TAP (X_1)));
    return false;
    break;
  case M_TMUX_SHIFT_INSERT:
    SEND_STRING (SS_LSFT (SS_TAP (X_INS)));
    return false;
    break;
  case M_TMUX_TIME:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_T));
    return false;
    break;
  case M_TMUX_WIN_0:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_0));
    return false;
    break;
  case M_TMUX_WIN_1:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_1));
    return false;
    break;
  case M_TMUX_WIN_2:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_2));
    return false;
    break;
  case M_TMUX_WIN_3:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_3));
    return false;
    break;
  case M_TMUX_WIN_4:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_4));
    return false;
    break;
  case M_TMUX_WIN_5:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_5));
    return false;
    break;
  case M_TMUX_WIN_6:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_6));
    return false;
    break;
  case M_TMUX_WIN_7:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_7));
    return false;
    break;
  case M_TMUX_WIN_8:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_8));
    return false;
    break;
  case M_TMUX_WIN_9:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_9));
    return false;
    break;
  case M_TMUX_WIN_FIND:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_F));
    return false;
    break;
  case M_TMUX_WIN_LIST:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_W));
    return false;
    break;
  case M_TMUX_WIN_NAME:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_COMM));
    return false;
    break;
  case M_TMUX_WIN_NEXT:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_N));
    return false;
    break;
  case M_TMUX_WIN_NEW:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_C));
    return false;
    break;
  case M_TMUX_WIN_NUMBER:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_DOT));
    return false;
    break;
  case M_TMUX_WIN_PREV:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_P));
    return false;
    break;
  case M_TMUX_WIN_SELECT:
    SEND_STRING (SS_LCTL (SS_TAP (X_B)) SS_TAP (X_QUOT));
    return false;
    break;
  }

  return true;
}

void keyboard_pre_init_user ()
{
  gpio_set_pin_output (EMACSTKL_LED_HOME_ROW);
  gpio_set_pin_output (EMACSTKL_LED_EMACS);
  gpio_set_pin_output (EMACSTKL_LED_TMUX);
}

layer_state_t layer_state_set_user(layer_state_t state)
{
  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_HOME_ROW))
    gpio_write_pin_high (EMACSTKL_LED_HOME_ROW);
  else
    gpio_write_pin_low (EMACSTKL_LED_HOME_ROW);

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_EMACS))
    gpio_write_pin_high (EMACSTKL_LED_EMACS);
  else
    gpio_write_pin_low (EMACSTKL_LED_EMACS);

  if (IS_LAYER_ON_STATE (state, EMACSTKL_LAYER_TMUX))
    gpio_write_pin_high (EMACSTKL_LED_TMUX);
  else
    gpio_write_pin_low (EMACSTKL_LED_TMUX);

  return state;
}

/*end of the file*/
