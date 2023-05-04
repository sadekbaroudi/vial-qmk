// check to see if we are using the stenographobe, and skip if so... it has its own whole combo scheme
// see keyboards/fingerpunch/stenographobe/keymaps/*/keymap.c
#ifndef KEYBOARD_fingerpunch_stenographobe
#include "combos.h"
#include "sadekbaroudi.h"

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
#ifdef KEYBOARD_fingerpunch_arachnophobe
const uint16_t PROGMEM q_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM p_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM l_combo[] = {LT(_MOUSE, KC_M), RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM lbracket_combo[] = {LGUI_T(KC_R), KC_X, COMBO_END};
const uint16_t PROGMEM lcurly_combo[] = {LALT_T(KC_S), KC_C, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END};
const uint16_t PROGMEM langle_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {LT(_MOUSE, KC_M), KC_K, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {RSFT_T(KC_N), KC_H, COMBO_END};
const uint16_t PROGMEM rcurly_combo[] = {RALT_T(KC_E), KC_COMMA, COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {RGUI_T(KC_I), KC_DOT, COMBO_END};
#endif

combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
#ifdef KEYBOARD_fingerpunch_arachnophobe
  [Q] = COMBO_ACTION(q_combo),
  [P] = COMBO_ACTION(p_combo),
  [B] = COMBO_ACTION(b_combo),
  [J] = COMBO_ACTION(j_combo),
  [L] = COMBO_ACTION(l_combo),
  [SEMICOLON] = COMBO_ACTION(semicolon_combo),
  [LBRACKET] = COMBO_ACTION(lbracket_combo),
  [LCURLY] = COMBO_ACTION(lcurly_combo),
  [LPAREN] = COMBO_ACTION(lparen_combo),
  [LANGLE] = COMBO_ACTION(langle_combo),
  [RANGLE] = COMBO_ACTION(rangle_combo),
  [RPAREN] = COMBO_ACTION(rparen_combo),
  [RCURLY] = COMBO_ACTION(rcurly_combo),
  [RBRACKET] = COMBO_ACTION(rbracket_combo),
#endif
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
#ifdef KEYBOARD_fingerpunch_arachnophobe
    case Q:
      if (pressed) {
        tap_code16(KC_Q);
      }
      break;
    case P:
      if (pressed) {
        tap_code16(KC_P);
      }
      break;
    case B:
      if (pressed) {
        tap_code16(KC_B);
      }
      break;
    case J:
      if (pressed) {
        tap_code16(KC_J);
      }
      break;
    case L:
      if (pressed) {
        tap_code16(KC_L);
      }
      break;
    case SEMICOLON:
      if (pressed) {
        tap_code16(KC_COLON);
      }
      break;
    case LBRACKET:
      if (pressed) {
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
        tap_code16(RBRACKET);
      }
      break;
#endif
  }
}
// END COMBOS
#endif // stenographobe exclusion
