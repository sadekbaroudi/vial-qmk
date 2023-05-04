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

layer_state_t fp_layer_state_set_encoder(layer_state_t state);
bool fp_process_record_encoder(uint16_t keycode, keyrecord_t *record);

#ifdef ENCODER_ENABLE

#   ifndef FP_ENC_0_LAYER_VOLUME
#       define FP_ENC_0_LAYER_VOLUME 0
#   endif
#   ifndef FP_ENC_0_LAYER_PGUP_PGDN
#       define FP_ENC_0_LAYER_PGUP_PGDN 1
#   endif
#   ifndef FP_ENC_0_LAYER_ZOOM
#       define FP_ENC_0_LAYER_ZOOM 2
#   endif
#   ifndef FP_ENC_0_LAYER_DPI_POINTING
#       define FP_ENC_0_LAYER_DPI_POINTING 3
#   endif
#   ifndef FP_ENC_0_LAYER_SUPER_TAB
#       define FP_ENC_0_LAYER_SUPER_TAB 4
#   endif
#   ifndef FP_ENC_0_LAYER_SUPER_CTRL_TAB
#       define FP_ENC_0_LAYER_SUPER_CTRL_TAB 5
#   endif
#   ifndef FP_ENC_0_LAYER_SCROLL_WHEEL
#       define FP_ENC_0_LAYER_SCROLL_WHEEL 6
#   endif
#   ifndef FP_ENC_0_LAYER_RGB_MODE
#       define FP_ENC_0_LAYER_RGB_MODE 7
#   endif
#   ifndef FP_ENC_0_LAYER_RGB_HUE
#       define FP_ENC_0_LAYER_RGB_HUE 8
#   endif
#   ifndef FP_ENC_0_LAYER_RGB_SAT
#       define FP_ENC_0_LAYER_RGB_SAT 9
#   endif
#   ifndef FP_ENC_0_LAYER_RGB_VAL
#       define FP_ENC_0_LAYER_RGB_VAL 10
#   endif

#   ifndef FP_ENC_1_LAYER_SUPER_TAB
#       define FP_ENC_1_LAYER_SUPER_TAB 0
#   endif
#   ifndef FP_ENC_1_LAYER_PGUP_PGDN
#       define FP_ENC_1_LAYER_PGUP_PGDN 1
#   endif
#   ifndef FP_ENC_1_LAYER_ZOOM
#       define FP_ENC_1_LAYER_ZOOM 2
#   endif
#   ifndef FP_ENC_1_LAYER_DPI_POINTING
#       define FP_ENC_1_LAYER_DPI_POINTING 3
#   endif
#   ifndef FP_ENC_1_LAYER_SUPER_CTRL_TAB
#       define FP_ENC_1_LAYER_SUPER_CTRL_TAB 4
#   endif
#   ifndef FP_ENC_1_LAYER_SCROLL_WHEEL
#       define FP_ENC_1_LAYER_SCROLL_WHEEL 5
#   endif
#   ifndef FP_ENC_1_LAYER_VOLUME
#       define FP_ENC_1_LAYER_VOLUME 6
#   endif
#   ifndef FP_ENC_1_LAYER_RGB_MODE
#       define FP_ENC_1_LAYER_RGB_MODE 7
#   endif
#   ifndef FP_ENC_1_LAYER_RGB_HUE
#       define FP_ENC_1_LAYER_RGB_HUE 8
#   endif
#   ifndef FP_ENC_1_LAYER_RGB_SAT
#       define FP_ENC_1_LAYER_RGB_SAT 9
#   endif
#   ifndef FP_ENC_1_LAYER_RGB_VAL
#       define FP_ENC_1_LAYER_RGB_VAL 10
#   endif

#endif