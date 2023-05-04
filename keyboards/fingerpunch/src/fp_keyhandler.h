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
#include "quantum.h"
#include QMK_KEYBOARD_H

#ifndef FP_DISABLE_CUSTOM_KEYCODES
enum fp_keycodes {
#   ifdef VIA_ENABLE
    FP_SCROLL_TOG = USER00,
#   else
    FP_SCROLL_TOG = SAFE_RANGE,
#   endif // VIA_ENABLE
    FP_ACCEL_TOG,
    FP_POINT_DPI_UP,
    FP_POINT_DPI_DN,
    FP_POINT_DPI_RESET,
    FP_SCROLL_ON,
    FP_SCROLL_OFF,
    FP_SCROLL_MOMENT,
    FP_SCROLL_DPI_UP,
    FP_SCROLL_DPI_DN,
    FP_SCROLL_DPI_RESET,
    FP_SNIPE_TOG,
    FP_SNIPE_ON,
    FP_SNIPE_OFF,
    FP_SNIPE_MOMENT,
    FP_SNIPE_DPI_UP,
    FP_SNIPE_DPI_DN,
    FP_SNIPE_DPI_RESET,
    FP_ZOOM_TOG,
    FP_ZOOM_ON,
    FP_ZOOM_OFF,
    FP_ZOOM_MOMENT,
    FP_SUPER_TAB,
    FP_SUPER_CTRL_TAB,
    FP_SAFE_RANGE
};
#endif // FP_DISABLE_CUSTOM_KEYCODES
