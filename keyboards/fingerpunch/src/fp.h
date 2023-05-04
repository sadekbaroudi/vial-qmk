/* Copyright 2022 Sadek Baroudi
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.j
 */

#pragma once

#include QMK_KEYBOARD_H

#include "eeprom.h"

bool fp_caps_lock_get(void);
void fp_caps_lock_toggle(void);
void handle_caps_lock_change(void);
void press_super_tab(bool shift);
void press_super_ctrl_tab(bool shift);
#ifdef CONSOLE_ENABLE
void fp_log_eeprom(void);
#endif

#include "keyboards/fingerpunch/src/fp_color.h"
#include "keyboards/fingerpunch/src/fp_keyhandler.h"

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "keyboards/fingerpunch/src/fp_rgb_common.h"
#endif
#ifdef RGBLIGHT_ENABLE
#    include "keyboards/fingerpunch/src/fp_rgblight.h"
#endif
#ifdef RGB_MATRIX_ENABLE
#    include "keyboards/fingerpunch/src/fp_rgb_matrix.h"
#endif
#ifdef ENCODER_ENABLE
#    include "keyboards/fingerpunch/src/fp_encoder.h"
#endif
#ifdef HAPTIC_ENABLE
#    include "keyboards/fingerpunch/src/fp_haptic.h"
#endif
#ifdef AUDIO_ENABLE
#    include "keyboards/fingerpunch/src/fp_audio.h"
#endif
#ifdef POINTING_DEVICE_ENABLE
#    include "keyboards/fingerpunch/src/fp_pointing.h"
#endif

// clang-format off
typedef union {
    uint64_t raw;
    struct {
        uint8_t rgb_mode :8;
        uint8_t rgb_hue :8;
        uint8_t rgb_sat :8;
        uint8_t rgb_val :8;
        uint8_t rgb_speed :8;
        uint8_t pointing_dpi :8;
        uint8_t sniping_dpi :8;
        uint8_t scrolling_dpi :8;
    };
} fp_config_t;
// clang-format on

extern fp_config_t fp_config;
