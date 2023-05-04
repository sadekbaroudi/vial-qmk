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

layer_state_t fp_layer_state_set_rgb(layer_state_t state);
void fp_rgb_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode);
void fp_rgblight_step(void);
void fp_rgblight_step_reverse(void);
void fp_rgblight_increase_hue(void);
void fp_rgblight_decrease_hue(void);
void fp_rgblight_increase_sat(void);
void fp_rgblight_decrease_sat(void);
void fp_rgblight_increase_val(void);
void fp_rgblight_decrease_val(void);
void fp_post_init_rgb_common(void);
bool fp_process_record_rgb_common(uint16_t keycode, keyrecord_t *record);
void fp_rgb_set_config_from_current_values(void);
uint32_t fp_rgb_set_config_from_current_values_deferred(uint32_t triger_time, void *cb_arg);
uint8_t fp_rgb_get_element_from_hsv(uint8_t hue, uint8_t sat, uint8_t val, uint8_t whichOne);

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    ifndef FP_LAYER_LIGHTING_HUE_0
#        define FP_LAYER_LIGHTING_HUE_0 HSV_BLUE
#    endif // FP_LAYER_LIGHTING_HUE_0

#    ifndef FP_LAYER_LIGHTING_HUE_1
#        define FP_LAYER_LIGHTING_HUE_1 HSV_WHITE
#    endif // FP_LAYER_LIGHTING_HUE_1

#    ifndef FP_LAYER_LIGHTING_HUE_2
#        define FP_LAYER_LIGHTING_HUE_2 HSV_GREEN
#    endif // FP_LAYER_LIGHTING_HUE_2

#    ifndef FP_LAYER_LIGHTING_HUE_3
#        define FP_LAYER_LIGHTING_HUE_3 HSV_PURPLE
#    endif // FP_LAYER_LIGHTING_HUE_3

#    ifndef FP_LAYER_LIGHTING_HUE_4
#        define FP_LAYER_LIGHTING_HUE_4 HSV_YELLOW
#    endif // FP_LAYER_LIGHTING_HUE_4

#    ifndef FP_LAYER_LIGHTING_HUE_5
#        define FP_LAYER_LIGHTING_HUE_5 FP_HSV_MELON
#    endif // FP_LAYER_LIGHTING_HUE_5

#    ifndef FP_LAYER_LIGHTING_HUE_6
#        define FP_LAYER_LIGHTING_HUE_6 HSV_CYAN
#    endif // FP_LAYER_LIGHTING_HUE_6

#    ifndef FP_LAYER_LIGHTING_HUE_7
#        define FP_LAYER_LIGHTING_HUE_7 HSV_SPRINGGREEN
#    endif // FP_LAYER_LIGHTING_HUE_7

#    ifndef FP_LAYER_LIGHTING_MODE_0
#        define FP_LAYER_LIGHTING_MODE_0 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_0

#    ifndef FP_LAYER_LIGHTING_MODE_1
#        define FP_LAYER_LIGHTING_MODE_1 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_1

#    ifndef FP_LAYER_LIGHTING_MODE_2
#        define FP_LAYER_LIGHTING_MODE_2 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_2

#    ifndef FP_LAYER_LIGHTING_MODE_3
#        define FP_LAYER_LIGHTING_MODE_3 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_3

#    ifndef FP_LAYER_LIGHTING_MODE_4
#        define FP_LAYER_LIGHTING_MODE_4 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_4

#    ifndef FP_LAYER_LIGHTING_MODE_5
#        define FP_LAYER_LIGHTING_MODE_5 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_5

#    ifndef FP_LAYER_LIGHTING_MODE_6
#        define FP_LAYER_LIGHTING_MODE_6 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_6

#    ifndef FP_LAYER_LIGHTING_MODE_7
#        define FP_LAYER_LIGHTING_MODE_7 FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_MODE_7

#    ifndef FP_LAYER_LIGHTING_AUTO_MOUSE_HUE
#        define FP_LAYER_LIGHTING_AUTO_MOUSE_HUE HSV_ORANGE
#    endif // FP_LAYER_LIGHTING_AUTO_MOUSE_HUE

#    ifndef FP_LAYER_LIGHTING_AUTO_MOUSE_MODE
#        define FP_LAYER_LIGHTING_AUTO_MOUSE_MODE FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_AUTO_MOUSE_HUE

#    ifndef FP_LAYER_LIGHTING_CAPS_LOCK_HUE
#        define FP_LAYER_LIGHTING_CAPS_LOCK_HUE HSV_RED
#    endif // FP_LAYER_LIGHTING_AUTO_MOUSE_HUE

#    ifndef FP_LAYER_LIGHTING_CAPS_LOCK_MODE
#        define FP_LAYER_LIGHTING_CAPS_LOCK_MODE FP_LAYER_LIGHTING_MODE
#    endif // FP_LAYER_LIGHTING_AUTO_MOUSE_HUE
#endif
