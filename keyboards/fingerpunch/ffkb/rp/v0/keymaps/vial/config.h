/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID {0x77, 0xCC, 0x1B, 0x87, 0xC1, 0xA9, 0xB5, 0x04}

#if defined(ENCODER_ENABLE) && defined(VIAL_ENCODERS_ENABLE)
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, C(KC_LEFT), C(KC_RIGHT), \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS }
#endif

#ifndef VIAL_INSECURE
#define VIAL_UNLOCK_COMBO_ROWS { 0, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }
#endif

// For via/vial only
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
