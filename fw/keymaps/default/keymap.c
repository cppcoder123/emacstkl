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
  MACRO_BUFFER_0 = SAFE_RANGE,
  MACRO_BUFFER_1,
  MACRO_BUFFER_2,
  MACRO_BUFFER_3,
  MACRO_BUFFER_SWITCH,
  /**/
  MACRO_COMPILE,
  MACRO_COMPILE_AGAIN,
  /**/
  MACRO_FILE_OPEN,
  MACRO_FILE_SAVE,
  MACRO_MAGIT,
  MACRO_MAKE,
  MACRO_MAKE_CLEAN,
  MACRO_MAKE_J,			/* parallel make*/
  MACRO_NEXT_ERROR,
  MACRO_SHIFT_INSERT,		/* for terminal */
};

/*
 * Column 0:
 * KC_ESC,
 * KC_GRV,
 * KC_TAB,
 * KC_CAPS,
 * KC_LSFT,
 * KC_LCTL,
 *
 * Column 1:
 *
 * KC_1,
 * KC_Q,
 * KC_A,
 *
 * KC_LGUI,
 *
 * Column 2:
 * KC_F1,
 * KC_2,
 * KC_W,
 * KC_S,
 * KC_Z,
 * KC_LALT,
 *
 * Column 3:
 * KC_F2,
 * KC_3,
 * KC_E,
 * KC_D,
 * KC_X,
 *
 * Column 4:
 * KC_F3,
 * KC_4,
 * KC_R,
 * KC_F,
 * KC_C,
 *
 * Column 5:
 * KC_F4,
 * KC_5,
 * KC_T,
 * KC_G,
 * KC_V,
 *
 * Column 6:
 * KC_F5,
 * KC_6,
 * KC_Y,
 * KC_H,
 * KC_B,
 * KC_SPC,
 *
 * Column 7:
 * KC_F6,
 * KC_7,
 * KC_U,
 * KC_J,
 * KC_N,
 *
 * Column 8:
 * KC_F7,
 * KC_8,
 * KC_I,
 * KC_K,
 * KC_M,
 *
 *
 * Column 9:
 * KC_F8,
 * KC_9,
 * KC_O,
 * KC_L,
 * KC_COMM,
 * KC_RALT,
 *
 * Column 10:
 * KC_F9,
 * KC_0,
 * KC_P,
 * KC_SCLN,
 * KC_DOT,
 * KC_RGUI,
 *
 * Column 11:
 * KC_F10,
 * KC_MIN
 * KC_LBR
 * KC_QUO
 * KC_SLS
 * MO(1),
 *
 * Column 12:
 * KC_F11,
 * KC_EQL
 * KC_RBR
 * KC_ENT
 * KC_RSF
 * C_RCTL,
 *
 * Column 13:
 * KC_F12,
 * KC_BSPC,
 * KC_BSLS,
 *
 * Column 14:
  *KC_PSCR,
 * KC_INS,
 * KC_DEL,
 *
 *KC_LEFT,
 *
 * Column 15:
 * KC_SCRL
 * KC_HOM
 * KC_END
 *
 * KC_UP,
 * KC_DOWN,
 *
 * Column 16:
 * KC_PAUS
 * KC_PGU
 * KC_PGD
 *
 * KC_RIGHT
 *
 *
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_tkl_ansi
  (
   KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,
     KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS,
   KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
     KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP,
   KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
     KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, KC_END, KC_PGDN,
   KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,
     KC_SCLN, KC_QUOT, KC_ENT,
   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,
     KC_SLSH, KC_RSFT, KC_UP,
   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, MO(1), KC_RCTL,
     KC_LEFT, KC_DOWN, KC_RIGHT),

  [1] = LAYOUT_tkl_ansi
  (
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO,
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
     KC_NO, KC_NO, KC_VOLU,
   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD,
     KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (!record->event.pressed)
    return true;

  switch (keycode) {
  case MACRO_BUFFER_0:
    SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_0));
    break;
  case MACRO_BUFFER_1:
    SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_1));
    break;
  case MACRO_BUFFER_2:
    SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_2));
    break;
  case MACRO_BUFFER_3:
    SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_3));
    break;
  case MACRO_BUFFER_SWITCH:
    SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_B));
    break;
  case MACRO_COMPILE:
    SEND_STRING(SS_LALT(SS_TAP(X_X)) "compile" SS_TAP(X_ENTER));
    break;
  case MACRO_COMPILE_AGAIN:
    SEND_STRING(SS_LALT(SS_TAP(X_X)) "recompile" SS_TAP(X_ENTER));
    break;
  case MACRO_FILE_OPEN:
    SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_LCTL(SS_TAP(X_F)));
    break;
  case MACRO_FILE_SAVE:
    SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_LCTL(SS_TAP(X_S)));
    break;
  case MACRO_MAGIT:
    SEND_STRING(SS_LALT(SS_TAP(X_X)) "magit" SS_TAP(X_ENTER));
    break;
  case MACRO_MAKE:
    SEND_STRING ("make");
    break;
  case MACRO_MAKE_CLEAN:
    SEND_STRING ("make clean");
    break;
  case MACRO_MAKE_J:
    SEND_STRING ("make -j ");
    break;
  case MACRO_NEXT_ERROR:
    SEND_STRING (SS_LCTL (SS_TAP (X_X)) SS_TAP (X_GRV));
    break;
  case MACRO_SHIFT_INSERT:
    SEND_STRING (SS_LSFT (SS_TAP (X_INS)));
    break;
  }

  return true;
}



#if 0


#include QMK_KEYBOARD_H
#include "version.h"
#include "split_util.h"

// START-MUGUR-REGION

/* Macros */
enum custom_keycodes {EPRM = SAFE_RANGE,MACRO_18, MACRO_17, MACRO_16, MACRO_15, MACRO_14, MACRO_13, MACRO_12, MACRO_11, MACRO_10, MACRO_9, MACRO_8, MACRO_7, MACRO_6, MACRO_5, MACRO_4, MACRO_3, MACRO_2, MACRO_1};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case MACRO_1: SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_0)); return false;
    case MACRO_2: SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_2)); return false;
    case MACRO_3: SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_3)); return false;
    case MACRO_4: SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_4) SS_TAP(X_T)); return false;
    case MACRO_5: SEND_STRING(SS_LCTL(SS_TAP(X_LALT)) SS_TAP(X_O)); return false;
    case MACRO_6: SEND_STRING(SS_LALT(SS_TAP(X_X)) "gtd" SS_TAP(X_ENTER)); return false;
    case MACRO_7: SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_B)); return false;
    case MACRO_8: SEND_STRING("λ"); return false;
    case MACRO_9: SEND_STRING(SS_LALT(SS_TAP(X_X)) "magit" SS_TAP(X_ENTER)); return false;
    case MACRO_10: SEND_STRING(SS_RCMD(SS_TAP(X_I)) SS_TAP(X_E)); return false;
    case MACRO_11: SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_TAP(X_8)); return false;
    case MACRO_12: SEND_STRING("  - [ ] "); return false;
    case MACRO_13: SEND_STRING(SS_RCMD(SS_TAP(X_I)) SS_TAP(X_O)); return false;
    case MACRO_14: SEND_STRING(SS_RCMD(SS_TAP(X_I)) SS_TAP(X_O)); return false;
    case MACRO_15: SEND_STRING("  - "); return false;
    case MACRO_16: SEND_STRING(SS_RCMD(SS_TAP(X_M)) SS_TAP(X_N)); return false;
    case MACRO_17: SEND_STRING(SS_RCMD(SS_TAP(X_M)) SS_TAP(X_M)); return false;
    case MACRO_18: SEND_STRING(SS_RCMD(SS_TAP(X_M)) SS_TAP(X_S)); return false;}
  }
  return true;
};

/* Layer Codes and Matrix */
enum layer_codes {BASE = 0, NUMERIC = 1, MOVE = 2, EMACS = 3, HYPM = 4, QMIK = 15};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, LT(MOVE, KC_QUOTE), MT(MOD_LSFT, KC_UP), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, LT(HYPM, KC_DOWN), MO(EMACS), KC_LAPO, MT(MOD_LGUI, KC_SPACE), MT(MOD_RGUI, KC_ENTER), KC_RAPC, TT(NUMERIC)),

[NUMERIC] = LAYOUT_split_3x6_3(KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_MINUS, KC_EQUAL, KC_BSPACE, KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, LT(MOVE, KC_ENTER), MT(MOD_LSFT, KC_LEFT), KC_GRAVE, KC_TRNS, KC_BSLASH, KC_LEFT_CURLY_BRACE, KC_LBRACKET, KC_RBRACKET, KC_RIGHT_CURLY_BRACE, KC_COMMA, KC_DOT, KC_PIPE, MT(MOD_RSFT, KC_RIGHT), TG(QMIK), KC_LAPO, KC_TRNS, KC_TRNS, KC_RAPC, KC_TRNS),

[MOVE] = LAYOUT_split_3x6_3(KC_TRNS, LALT(KC_V), KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_A), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_E), KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_NO, KC_TRNS, KC_TRNS, LALT(KC_LEFT_ANGLE_BRACKET), LCTL(KC_V), LALT(KC_RIGHT_ANGLE_BRACKET), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[EMACS] = LAYOUT_split_3x6_3(KC_ESCAPE, KC_TRNS, KC_TRNS, MACRO_1, MACRO_2, MACRO_3, MACRO_4, KC_TRNS, KC_TRNS, MACRO_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_PERCENT), KC_TRNS, KC_TRNS, MACRO_6, MACRO_7, KC_TRNS, KC_TRNS, MACRO_8, KC_TRNS, KC_TRNS, RESET, KC_TRNS, LALT(KC_X), LCTL(KC_C), KC_TRNS, KC_LEFT_PAREN, KC_RIGHT_PAREN, MACRO_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_10, MACRO_11, KC_TRNS, MO(HYPM)),

[HYPM] = LAYOUT_split_3x6_3(KC_X, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_12, KC_TRNS, KC_TRNS, KC_I, MACRO_13, MACRO_14, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_D, KC_TRNS, MACRO_15, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_16, MACRO_17, MACRO_18, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[QMIK] = LAYOUT_split_3x6_3(KC_NO, RGB_TOG, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, RGB_SAD, RGB_VAD, RGB_HUD, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAI, RGB_VAI, RGB_HUI, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

// END-MUGUR-REGION

void keyboard_post_init_user(void) {
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;
}

#endif
