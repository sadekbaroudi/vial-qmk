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


#include "keyboards/fingerpunch/src/fp_rgblight.h"

#ifdef RGBLIGHT_ENABLE

void fp_rgb_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
    xprintf("fp_rgb_set_hsv_and_mode: hue: %d, sat: %d, val: %d, mode: %d\n", hue, sat, val, mode);
    rgblight_sethsv_noeeprom(hue, sat, val);
    rgblight_mode_noeeprom(mode);
}

void fp_post_init_rgblight(void) {

}

layer_state_t fp_layer_state_set_rgblight(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            // default to layer 0 behavior
            break;
    }
    return state;
}

bool fp_process_record_rgblight(uint16_t keycode, keyrecord_t *record) {
#   ifndef FP_DISABLE_CUSTOM_KEYCODES
    switch (keycode) {
        default:
            break;
    }
#   endif // FP_DISABLE_CUSTOM_KEYCODES

    return true;
}

#endif
