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

#include "keyboards/fingerpunch/src/fp_pointing.h"
#include "keyboards/fingerpunch/src/fp_keyhandler.h"
#include "math.h"
// is_keyboard_master()

#ifdef POINTING_DEVICE_ENABLE

#ifdef FP_POINTING_ACCELERATION_ENABLE
static bool acceleration_enabled = true;
#endif
static bool scrolling_enabled = false;
static bool scrolling_layer_enabled = false;
static bool sniping_enabled = false;
static bool sniping_layer_enabled = false;
static bool zooming_enabled = false;
static bool zooming_layer_enabled = false;
static bool zooming_hold = false;

void fp_set_cpi(uint8_t value) {
    pointing_device_set_cpi((uint16_t)value * FP_POINTING_DPI_MULTIPLIER);
}

void fp_point_dpi_update(uint8_t action) {
    xprintf("Pointing DPI update, action %u, before value: %u\n", action, fp_config.pointing_dpi);
    switch (action) {
        case FP_DPI_UP:
            if (fp_config.pointing_dpi >= FP_POINTING_MAX_DPI) {
                fp_config.pointing_dpi = FP_POINTING_MAX_DPI;
            } else {
                fp_config.pointing_dpi += 1;
            }
            break;
        case FP_DPI_DOWN:
            if (fp_config.pointing_dpi <= 1) {
                fp_config.pointing_dpi = 1;
            } else {
                fp_config.pointing_dpi -= 1;
            }
            break;
        case FP_DPI_RESET:
            fp_config.pointing_dpi = FP_POINTING_DEFAULT_DPI;
            break;
        default:
            break;
    }

    eeconfig_update_kb_datablock(&fp_config.raw);
    #ifdef CONSOLE_ENABLE
    fp_log_eeprom();
    #endif
    // This may be a bad decision, but use this function to apply the changes, since it covers sniping, scrolling, or regular cpi, based on what is active
    fp_scroll_apply_dpi();
    xprintf("Pointing DPI update, action %u, after value: %u\n", action, fp_config.pointing_dpi);
}

void fp_scroll_layer_set(bool scroll_value) {
    scrolling_layer_enabled = scroll_value;
    fp_scroll_apply_dpi();
}

void fp_scroll_keycode_set(bool scroll_value) {
    scrolling_enabled = scroll_value;
    fp_scroll_apply_dpi();
}

void fp_scroll_keycode_toggle(void) {
    scrolling_enabled = !scrolling_enabled;
    fp_scroll_apply_dpi();
}

bool fp_scroll_get(void) {
    return (scrolling_enabled || scrolling_layer_enabled);
}

void fp_scroll_apply_dpi(void) {
    // We don't want to apply the dpi change if sniping mode is enabled, since that will win!
    if(!fp_snipe_get()) {
        if(fp_scroll_get()) {
            fp_set_cpi(fp_config.scrolling_dpi);
        } else {
#ifdef POINTING_DEVICE_COMBINED
            fp_set_cpi_combined_defaults();
#else
            fp_set_cpi(fp_config.pointing_dpi);
#endif
        }
    }
}

void fp_scroll_dpi_update(uint8_t action) {
    xprintf("Scrolling DPI update, action %u, before value: %u\n", action, fp_config.scrolling_dpi);
    switch (action) {
        case FP_DPI_UP:
            if (fp_config.scrolling_dpi >= FP_POINTING_SCROLLING_MAX_DPI) {
                fp_config.scrolling_dpi = FP_POINTING_SCROLLING_MAX_DPI;
            } else {
                fp_config.scrolling_dpi += 1;
            }
            break;
        case FP_DPI_DOWN:
            if (fp_config.scrolling_dpi <= 1) {
                fp_config.scrolling_dpi = 1;
            } else {
                fp_config.scrolling_dpi -= 1;
            }
            break;
        case FP_DPI_RESET:
            fp_config.scrolling_dpi = FP_POINTING_SCROLLING_DPI;
            break;
        default:
            break;
    }

    eeconfig_update_kb_datablock(&fp_config.raw);
    // This may be a bad decision, but use this function to apply the changes, since it covers sniping, scrolling, or regular cpi, based on what is active
    fp_scroll_apply_dpi();
    xprintf("Scrolling DPI update, action %u, after value: %u\n", action, fp_config.scrolling_dpi);
}

void fp_snipe_layer_set(bool snipe_value) {
    sniping_layer_enabled = snipe_value;
    fp_snipe_apply_dpi();
}

void fp_snipe_keycode_set(bool snipe_value) {
    sniping_enabled = snipe_value;
    fp_snipe_apply_dpi();
}

void fp_snipe_keycode_toggle(void) {
    sniping_enabled = !sniping_enabled;
    fp_snipe_apply_dpi();
}

bool fp_snipe_get(void) {
    return (sniping_enabled || sniping_layer_enabled);
}

void fp_snipe_apply_dpi(void) {
    if(fp_snipe_get()) {
        fp_set_cpi(fp_config.sniping_dpi);
    } else {
        fp_set_cpi(fp_config.pointing_dpi);
    }
}

void fp_snipe_dpi_update(uint8_t action) {
    xprintf("Sniping DPI update, action %u, before value: %u\n", action, fp_config.sniping_dpi);
    switch (action) {
        case FP_DPI_UP:
            if (fp_config.sniping_dpi >= FP_POINTING_SNIPING_MAX_DPI) {
                fp_config.sniping_dpi = FP_POINTING_SNIPING_MAX_DPI;
            } else {
                fp_config.sniping_dpi += 1;
            }
            break;
        case FP_DPI_DOWN:
            if (fp_config.sniping_dpi <= 1) {
                fp_config.sniping_dpi = 1;
            } else {
                fp_config.sniping_dpi -= 1;
            }
            break;
        case FP_DPI_RESET:
            fp_config.sniping_dpi = FP_POINTING_SNIPING_DPI;
            break;
        default:
            break;
    }

    eeconfig_update_kb_datablock(&fp_config.raw);
    // This may be a bad decision, but use this function to apply the changes, since it covers sniping, scrolling, or regular cpi, based on what is active
    fp_scroll_apply_dpi();
    xprintf("Sniping DPI update, action %u, after value: %u\n", action, fp_config.sniping_dpi);
}

void fp_zoom_layer_set(bool zoom_value) {
    zooming_layer_enabled = zoom_value;
}

void fp_zoom_keycode_set(bool zoom_value) {
    zooming_enabled = zoom_value;
}

void fp_zoom_keycode_toggle(void) {
    zooming_enabled = !zooming_enabled;
}

bool fp_zoom_get(void) {
    return (zooming_enabled || zooming_layer_enabled);
}

uint32_t fp_zoom_unset_hold(uint32_t triger_time, void *cb_arg) {
    zooming_hold = false;
    return 0;
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    if (fp_scroll_get()) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else if (fp_zoom_get()) {
        bool zoom_in = false;
        mouse_xy_report_t zoom_value = mouse_report.y;
        if (zoom_value < 0) {
            zoom_in = true;
            zoom_value = -zoom_value;
        }

        // Set timer to prevent mass zoom and set threshold for zoom value, otherwise too sensitive
        if (!zooming_hold && zoom_value > 1) {
#ifdef FP_MAC_PREFERRED
            register_code(KC_LGUI);
#else
            register_code(KC_LCTL);
#endif
            zooming_hold = true;
            defer_exec(50, fp_zoom_unset_hold, NULL);
            if (zoom_in) {
                register_code(KC_LSFT);
                tap_code(KC_EQUAL);
                unregister_code(KC_LSFT);
            } else {
                tap_code(KC_MINUS);
            }
#ifdef FP_MAC_PREFERRED
            unregister_code(KC_LGUI);
#else
            unregister_code(KC_LCTL);
#endif
        }

        mouse_report.h = 0;
        mouse_report.v = 0;
        mouse_report.x = 0;
        mouse_report.y = 0;

    }
#ifdef FP_POINTING_ACCELERATION_ENABLE
    // Don't run acceleration unless you're in regular mousing mode, and acceleration is explicitly enabled
    if (!fp_scroll_get() && !fp_snipe_get() && !fp_zoom_get() && acceleration_enabled) {
        mouse_xy_report_t x = mouse_report.x, y = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;

        x = (mouse_xy_report_t)(x > 0 ? x * x / 16 + x : -x * x / 16 + x);
        y = (mouse_xy_report_t)(y > 0 ? y * y / 16 + y : -y * y / 16 + y);

        mouse_report.x = x;
        mouse_report.y = y;
    }
#endif
    mouse_report = pointing_device_task_user(mouse_report);
    return mouse_report;
}

layer_state_t fp_layer_state_set_pointing(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case FP_POINTING_SCROLLING_LAYER:
#ifdef FP_POINTING_SCROLLING_LAYER_ENABLE
            fp_scroll_layer_set(true);
#endif
            break;
        case FP_POINTING_SNIPING_LAYER:
#ifdef FP_POINTING_SNIPING_LAYER_ENABLE
            fp_snipe_layer_set(true);
#endif
            break;
        case FP_POINTING_ZOOMING_LAYER:
#ifdef FP_POINTING_ZOOMING_LAYER_ENABLE
            fp_zoom_layer_set(true);
#endif
            break;
        default:
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
            // If we hit one of the FP_POINTING_X_LAYERS, and then trigger auto mouse layer, we don't want to
            // disable the scroll/snipe adjustments because we used the pointing device
            // Problem happens when POINTING_DEVICE_AUTO_MOUSE_ENABLE and FP_POINTING_X_LAYER_ENABLE
            // are enabled at the samet time
            if (get_highest_layer(state) == AUTO_MOUSE_DEFAULT_LAYER) {
                break;
            }
#endif
            if (scrolling_layer_enabled) {
#ifdef FP_POINTING_SCROLLING_LAYER_ENABLE
                fp_scroll_layer_set(false);
#endif
            }
            if (sniping_layer_enabled) {
#ifdef FP_POINTING_SNIPING_LAYER_ENABLE
                fp_snipe_layer_set(false);
#endif
            }
            if (zooming_layer_enabled) {
#ifdef FP_POINTING_ZOOMING_LAYER_ENABLE
                fp_zoom_layer_set(false);
#endif
            }
            break;
    }
    return state;
}

#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {
    if (FP_POINTING_COMBINED_SCROLLING_LEFT) {
        left_report.h = left_report.x;
        left_report.v = -left_report.y;
        left_report.x = 0;
        left_report.y = 0;
    }

    if (FP_POINTING_COMBINED_SCROLLING_RIGHT) {
        right_report.h = right_report.x;
        right_report.v = -right_report.y;
        right_report.x = 0;
        right_report.y = 0;
    }

    return pointing_device_task_combined_user(left_report, right_report);
}

void fp_set_cpi_combined_defaults(void) {
    if (FP_POINTING_COMBINED_SCROLLING_LEFT) {
        pointing_device_set_cpi_on_side(true, (uint16_t)fp_config.scrolling_dpi * FP_POINTING_DPI_MULTIPLIER); //Set cpi on left side to a low value for slower scrolling.
    } else {
        pointing_device_set_cpi_on_side(true, (uint16_t)fp_config.pointing_dpi * FP_POINTING_DPI_MULTIPLIER); //Set cpi on left side to a reasonable value for mousing.
    }

    if (FP_POINTING_COMBINED_SCROLLING_RIGHT) {
        pointing_device_set_cpi_on_side(false, (uint16_t)fp_config.scrolling_dpi * FP_POINTING_DPI_MULTIPLIER); //Set cpi on right side to a low value for slower scrolling.
    } else {
        pointing_device_set_cpi_on_side(false, (uint16_t)fp_config.pointing_dpi * FP_POINTING_DPI_MULTIPLIER); //Set cpi on right side to a reasonable value for mousing.
    }
}
#endif

void pointing_device_init_kb(void) {
#   ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
#   endif

    pointing_device_init_user();
}

#ifdef FP_TRACKBALL_ENABLE
// Override when using a trackball so that you can account for acciental triggers due to a sensitive sensor
bool auto_mouse_activation(report_mouse_t mouse_report) {
    // If we're in sniping mode, lower the threshold, otherwise give it some room to move for accidental triggers of auto mouse layer
    if (fp_snipe_get()) {
        return fabs(mouse_report.x) >= 0.5 || fabs(mouse_report.y) >= 0.5 || fabs(mouse_report.h) >= 0.5 || fabs(mouse_report.v) >= 0.5 || mouse_report.buttons;
    } else {
        return fabs(mouse_report.x) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               fabs(mouse_report.y) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               fabs(mouse_report.h) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               fabs(mouse_report.v) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               mouse_report.buttons;
    }
}
#endif

bool fp_process_record_pointing(uint16_t keycode, keyrecord_t *record) {
#   ifndef FP_DISABLE_CUSTOM_KEYCODES
    switch (keycode) {
        case FP_ACCEL_TOG:
#       ifdef FP_POINTING_ACCELERATION_ENABLE
            acceleration_enabled = !acceleration_enabled;
#       endif
            break;
        case FP_SCROLL_MOMENT:
            if (record->event.pressed) {
                fp_scroll_keycode_set(true);
            } else {
                fp_scroll_keycode_set(false);
            }
            break;
        case FP_SCROLL_TOG:
            if (record->event.pressed) {
                fp_scroll_keycode_toggle();
            }
            break;
        case FP_SCROLL_ON:
            if (record->event.pressed) {
                fp_scroll_keycode_set(true);
            }
            break;
        case FP_SCROLL_OFF:
            if (record->event.pressed) {
                fp_scroll_keycode_set(false);
            }
            break;
        case FP_SNIPE_MOMENT:
            if (record->event.pressed) {
                fp_snipe_keycode_set(true);
            } else {
                fp_snipe_keycode_set(false);
            }
            break;
        case FP_SNIPE_TOG:
            if (record->event.pressed) {
                fp_snipe_keycode_toggle();
            }
            break;
        case FP_SNIPE_ON:
            if (record->event.pressed) {
                fp_snipe_keycode_set(true);
            }
            break;
        case FP_SNIPE_OFF:
            if (record->event.pressed) {
                fp_snipe_keycode_set(false);
            }
            break;
        case FP_ZOOM_MOMENT:
            if (record->event.pressed) {
                fp_zoom_keycode_set(true);
            } else {
                fp_zoom_keycode_set(false);
            }
            break;
        case FP_ZOOM_TOG:
            if (record->event.pressed) {
                fp_zoom_keycode_toggle();
            }
            break;
        case FP_ZOOM_ON:
            if (record->event.pressed) {
                fp_zoom_keycode_set(true);
            }
            break;
        case FP_ZOOM_OFF:
            if (record->event.pressed) {
                fp_zoom_keycode_set(false);
            }
            break;
        case FP_POINT_DPI_UP:
            if (record->event.pressed) {
                fp_point_dpi_update(FP_DPI_UP);
            }
            break;
        case FP_POINT_DPI_DN:
            if (record->event.pressed) {
                fp_point_dpi_update(FP_DPI_DOWN);
            }
            break;
        case FP_POINT_DPI_RESET:
            if (record->event.pressed) {
                fp_point_dpi_update(FP_DPI_RESET);
            }
            break;
        case FP_SCROLL_DPI_UP:
            if (record->event.pressed) {
                fp_scroll_dpi_update(FP_DPI_UP);
            }
            break;
        case FP_SCROLL_DPI_DN:
            if (record->event.pressed) {
                fp_scroll_dpi_update(FP_DPI_DOWN);
            }
            break;
        case FP_SCROLL_DPI_RESET:
            if (record->event.pressed) {
                fp_scroll_dpi_update(FP_DPI_RESET);
            }
            break;
        case FP_SNIPE_DPI_UP:
            if (record->event.pressed) {
                fp_snipe_dpi_update(FP_DPI_UP);
            }
            break;
        case FP_SNIPE_DPI_DN:
            if (record->event.pressed) {
                fp_snipe_dpi_update(FP_DPI_DOWN);
            }
            break;
        case FP_SNIPE_DPI_RESET:
            if (record->event.pressed) {
                fp_snipe_dpi_update(FP_DPI_RESET);
            }
            break;
        default:
            break;
    }
#   endif // FP_DISABLE_CUSTOM_KEYCODES

    return true;
}

#endif
