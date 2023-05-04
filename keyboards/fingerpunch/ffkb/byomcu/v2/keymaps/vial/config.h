/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID {0x5F, 0xC8, 0xB9, 0x79, 0x18, 0x72, 0x56, 0xF2}

#if defined(ENCODER_ENABLE) && defined(VIAL_ENCODERS_ENABLE)
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, C(KC_LEFT), C(KC_RIGHT), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,            KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,            KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,            KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,            KC_TRNS }
#endif

#ifndef VIAL_INSECURE
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
#endif

// For via/vial only
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
