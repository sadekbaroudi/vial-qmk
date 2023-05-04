/* Copyright 2021 Sadek Baroudi
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

#include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

/*
 * The `LAYOUT_stenographobe_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg ALPHA_ALT, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_stenographobe_base( \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
  ) \
  LAYOUT_wrapper( \
        KC_LCTL,  K11,    K12,    K13,    K14,    K15,                                      K16,    K17,    K18,    K19,    K1A,    KC_LGUI, \
        KC_LSFT,  K21,    K22,    K23,    K24,    K25,                                      K26,    K27,    K28,    K29,    K2A,    KC_LALT, \
                             K33, LT(_NAVIGATION,K34), LT(_FUNCTION,K35),      K36,   LT(_SYMBOLS,K37),      K38 \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_stenographobe_base_wrapper(...)       LAYOUT_stenographobe_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ALT] = LAYOUT_stenographobe_base_wrapper(
        _________________ALPHA_ALT_L1_________________,            _________________ALPHA_ALT_R1_________________,
        _________________ALPHA_ALT_L3_________________,            _________________ALPHA_ALT_R3_________________,
                                                  __ALPHA_ALT_THUMBS_6__
    ),

    // http://www.keyboard-layout-editor.com/#/gists/de52870cef1432a165edc0ac2892e725
    [_ALPHA] = LAYOUT_stenographobe_base_wrapper(
        __________________ALPHA_L1____________________,            __________________ALPHA_R1____________________,
        __________________ALPHA_L3____________________,            __________________ALPHA_R3____________________,
                                                    __ALPHA_THUMBS_6__
    ),

    // http://www.keyboard-layout-editor.com/#/gists/3721dd5ddb2c922bc742d13fd558d590
    [_NAVIGATION] = LAYOUT_stenographobe_base_wrapper(
        ________________NAVIGATION_1_______________,        _________________NUMPAD_1__________________,
        ________________NAVIGATION_2_______________,        _________________NUMPAD_3__________________, // NAVIGATION_2 is intentional on this line, see KLE page
                                _______, _______, KC_TAB, KC_BSPC, KC_SPACE, KC_DOT
    ),

    // http://www.keyboard-layout-editor.com/#/gists/b637ddb31dbafb7d9ca245f80c17d551
    [_SYMBOLS] = LAYOUT_stenographobe_base_wrapper(
        ________________SYMBOLS_L1_________________,       ________________SYMBOLS_R1_________________,
        ________________SYMBOLS_L3_________________,       ________________SYMBOLS_R3_________________,
                                _______, KC_ENT, KC_DEL,  KC_BSPC, _______, _______
    ),

    // http://www.keyboard-layout-editor.com/#/gists/e2be4434b0c88c996a9ef36d5d604faf
    [_FUNCTION] = LAYOUT_stenographobe_base_wrapper(
        ________________SHIFTNAV_2_________________,       ________________FUNCTION_1_________________,
        ________________SHIFTNAV_3_________________,       ________________FUNCTION_3_________________,
                             _______, _______, _______, N_DEL_LINE, KC_SPACE, _______
    )
};

// Alllll the combos

enum combo_events {
  UNDO,
  REDO,
  A,
  R,
  S,
  T,
  G,
  M,
  N,
  E,
  I,
  O,
  FSLSH,
  FOUR,
  FIVE,
  SIX,
  PLUS_1,
  F_FOUR,
  F_FIVE,
  F_SIX,
  F_ELEVEN,
  MINUS,
  LBRACKET,
  LCURLY,
  LPAREN,
  LANGLE,
  RANGLE,
  RPAREN,
  RCURLY,
  RBRACKET,
  PLUS_2,
};

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM redo_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM a_combo[] = {KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM r_combo[] = {KC_W, KC_X, COMBO_END};
const uint16_t PROGMEM s_combo[] = {KC_F, KC_C, COMBO_END};
const uint16_t PROGMEM t_combo[] = {KC_P, KC_D, COMBO_END};
const uint16_t PROGMEM g_combo[] = {KC_B, KC_V, COMBO_END};
const uint16_t PROGMEM m_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM n_combo[] = {KC_L, KC_H, COMBO_END};
const uint16_t PROGMEM e_combo[] = {KC_U, KC_COMM, COMBO_END};
const uint16_t PROGMEM i_combo[] = {KC_Y, KC_DOT, COMBO_END};
const uint16_t PROGMEM o_combo[] = {KC_SCLN, KC_SLSH, COMBO_END};
const uint16_t PROGMEM fslsh_combo[] = {KC_ASTR, KC_EQUAL, COMBO_END};
const uint16_t PROGMEM four_combo[] = {KC_7, KC_1, COMBO_END};
const uint16_t PROGMEM five_combo[] = {KC_8, KC_2, COMBO_END};
const uint16_t PROGMEM six_combo[] = {KC_9, KC_3, COMBO_END};
const uint16_t PROGMEM plus_1_combo[] = {KC_MINUS, KC_0, COMBO_END};
const uint16_t PROGMEM f_four_combo[] = {KC_F7, KC_F1, COMBO_END};
const uint16_t PROGMEM f_five_combo[] = {KC_F8, KC_F2, COMBO_END};
const uint16_t PROGMEM f_six_combo[] = {KC_F9, KC_F3, COMBO_END};
const uint16_t PROGMEM f_eleven_combo[] = {KC_F10, KC_F12, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_EXLM, KC_CAPS, COMBO_END};
const uint16_t PROGMEM lbracket_combo[] = {KC_AT, KC_GRV, COMBO_END};
const uint16_t PROGMEM lcurly_combo[] = {KC_HASH, LCTL(LSFT(KC_TAB)), COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {KC_DOLLAR, LCTL(LGUI(KC_LEFT)), COMBO_END};
const uint16_t PROGMEM langle_combo[] = {KC_PERCENT, C_CAPSWORD, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {KC_CIRC, C_UNDERSCORECASE, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_AMPR, LCTL(LGUI(KC_RIGHT)), COMBO_END};
const uint16_t PROGMEM rcurly_combo[] = {KC_ASTR, LCTL(KC_TAB), COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {KC_UNDERSCORE, C_ANYCASE, COMBO_END};
const uint16_t PROGMEM plus_2_combo[] = {KC_EQUAL, KC_BSLS, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
  [A] = COMBO_ACTION(a_combo),
  [R] = COMBO_ACTION(r_combo),
  [S] = COMBO_ACTION(s_combo),
  [T] = COMBO_ACTION(t_combo),
  [G] = COMBO_ACTION(g_combo),
  [M] = COMBO_ACTION(m_combo),
  [N] = COMBO_ACTION(n_combo),
  [E] = COMBO_ACTION(e_combo),
  [I] = COMBO_ACTION(i_combo),
  [O] = COMBO_ACTION(o_combo),
  [FSLSH] = COMBO_ACTION(fslsh_combo),
  [FOUR] = COMBO_ACTION(four_combo),
  [FIVE] = COMBO_ACTION(five_combo),
  [SIX] = COMBO_ACTION(six_combo),
  [PLUS_1] = COMBO_ACTION(plus_1_combo),
  [F_FOUR] = COMBO_ACTION(f_four_combo),
  [F_FIVE] = COMBO_ACTION(f_five_combo),
  [F_SIX] = COMBO_ACTION(f_six_combo),
  [F_ELEVEN] = COMBO_ACTION(f_eleven_combo),
  [MINUS] = COMBO_ACTION(minus_combo),
  [LBRACKET] = COMBO_ACTION(lbracket_combo),
  [LCURLY] = COMBO_ACTION(lcurly_combo),
  [LPAREN] = COMBO_ACTION(lparen_combo),
  [LANGLE] = COMBO_ACTION(langle_combo),
  [RANGLE] = COMBO_ACTION(rangle_combo),
  [RPAREN] = COMBO_ACTION(rparen_combo),
  [RCURLY] = COMBO_ACTION(rcurly_combo),
  [RBRACKET] = COMBO_ACTION(rbracket_combo),
  [PLUS_2] = COMBO_ACTION(plus_2_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  // can comment out if I use the apostrophe below
  //static uint16_t kc;
  switch(combo_index) {
    case UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case REDO:
      if (pressed) {
        tap_code16(LCTL(KC_Y));
      }
      break;
    case A:
      if (pressed) {
        tap_code16(KC_A);
      }
      break;
    case R:
      if (pressed) {
        tap_code16(KC_R);
      }
      break;
    case S:
      if (pressed) {
        tap_code16(KC_S);
      }
      break;
    case T:
      if (pressed) {
        tap_code16(KC_T);
      }
      break;
    case G:
      if (pressed) {
        tap_code16(KC_G);
      }
      break;
    case M:
      if (pressed) {
        tap_code16(KC_M);
      }
      break;
    case N:
      if (pressed) {
        tap_code16(KC_N);
      }
      break;
    case E:
      if (pressed) {
        tap_code16(KC_E);
      }
      break;
    case I:
      if (pressed) {
        tap_code16(KC_I);
      }
      break;
    case O:
      if (pressed) {
        tap_code16(KC_O);
      }
      break;
    case FSLSH:
      if (pressed) {
        tap_code16(KC_SLSH);
      }
      break;
    case FOUR:
      if (pressed) {
        tap_code16(KC_4);
      }
      break;
    case FIVE:
      if (pressed) {
        tap_code16(KC_5);
      }
      break;
    case SIX:
      if (pressed) {
        tap_code16(KC_6);
      }
      break;
    case PLUS_1:
      if (pressed) {
        tap_code16(KC_PLUS);
      }
      break;
    case F_FOUR:
      if (pressed) {
        tap_code16(KC_F4);
      }
      break;
    case F_FIVE:
      if (pressed) {
        tap_code16(KC_F5);
      }
      break;
    case F_SIX:
      if (pressed) {
        tap_code16(KC_F6);
      }
      break;
    case F_ELEVEN:
      if (pressed) {
        tap_code16(KC_F11);
      }
      break;
    case MINUS:
      if (pressed) {
        tap_code16(KC_MINUS);
      }
      break;
    case LBRACKET:
      if (pressed) {
        // NEED TO PRESS SHIFT AND USE KC_LCBR
        tap_code16(LBRACKET);
      }
      break;
    case LCURLY:
      if (pressed) {
        tap_code16(KC_LCBR);
      }
      break;
    case LPAREN:
      if (pressed) {
        tap_code16(KC_LPRN);
      }
      break;
    case LANGLE:
      if (pressed) {
        tap_code16(KC_LABK);
      }
      break;
    case RANGLE:
      if (pressed) {
        tap_code16(KC_RABK);
      }
      break;
    case RPAREN:
      if (pressed) {
        tap_code16(KC_RPRN);
      }
      break;
    case RCURLY:
      if (pressed) {
        tap_code16(KC_RCBR);
      }
      break;
    case RBRACKET:
      if (pressed) {
        // NEED TO PRESS SHIFT AND USE KC_RCBR
        tap_code16(RBRACKET);
      }
      break;
    case PLUS_2:
      if (pressed) {
        tap_code16(KC_PLUS);
      }
      break;
  }
}
// END COMBOS
