/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID \
    { 0x9A, 0xFD, 0x4E, 0x1B, 0xD8, 0x97, 0x4F, 0x92 }

#ifndef VIAL_INSECURE
#    define VIAL_UNLOCK_COMBO_ROWS \
        { 5, 0 }
#    define VIAL_UNLOCK_COMBO_COLS \
        { 0, 0 }
#endif

#if defined(ENCODER_ENABLE) && defined(VIAL_ENCODERS_ENABLE)
#    define VIAL_ENCODER_DEFAULT \
        { KC_VOLD, KC_VOLU, C(KC_LEFT), C(KC_RIGHT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 10
#define VIAL_TAP_DANCE_ENTRIES 15
#define TAP_CODE_DELAY 25
#define VIAL_COMBO_ENTRIES 50
#define TAPPING_FORCE_HOLD
#define DYNAMIC_KEYMAP_MACRO_COUNT 15
