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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include QMK_KEYBOARD_H
#include "keyboards/fingerpunch/src/fp.h"

#ifdef RGB_MATRIX_ENABLE
#    ifndef FP_LAYER_LIGHTING_MODE
#        define FP_LAYER_LIGHTING_MODE RGB_MATRIX_SOLID_COLOR
#    endif
#endif

layer_state_t fp_layer_state_set_rgb_matrix(layer_state_t state);
bool fp_process_record_rgb_matrix(uint16_t keycode, keyrecord_t *record);
void fp_post_init_rgb_matrix(void);
