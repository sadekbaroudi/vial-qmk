/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID {0xE6, 0x4D, 0xC2, 0xCE, 0x28, 0x64, 0x3A, 0xCA}

#if defined(ENCODER_ENABLE) && defined(VIAL_ENCODERS_ENABLE)
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
#endif

#ifndef VIAL_INSECURE
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 1, 2 }
#endif

// For via/vial only
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
