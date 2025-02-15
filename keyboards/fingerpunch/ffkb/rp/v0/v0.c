/* Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>
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
#include "v0.h"

#ifdef RGB_MATRIX_ENABLE
// 6 column rgb config
led_config_t g_led_config = { {
    { 3,      2,      8,   14, 9,  15, 26, 27 },
    { 4,      1,      7,   13, 10, 16, 25, 28 },
    { 5,      0,      6,   12, 11, 17, 24, 29 },
    { NO_LED, NO_LED, 31,  33, 35, 37, 36, 39 },
    { NO_LED, NO_LED, 30,  34, 32, 38, 41, 40 },
    { NO_LED, NO_LED, 23,  19, 18, 20, 21, 22 }
}, {
    {0,32},{3,19},{7,5},{25,4},{21,18},{17,31},{35,26},{39,12},{43,0},{60,0},{56,12},{52,26},
    {66,33},{70,20},{74,6},{89,12},{85,25},{81,38},{61,50},{77,55},{93,63},{129,63},{145,55},{161,50},
    {141,38},{137,25},{133,12},{148,6},{152,20},{156,33},{170,26},{166,12},{162,0},{179,0},{183,12},{187,26},
    {205,31},{201,18},{197,4},{215,5},{219,19},{223,32}
}, {
    1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 1, 1
} };

/*
// 5 column rgb config
led_config_t g_led_config = { {
    { 0,      NO_LED,   5,  11,  6,  12,  23,     24 },
    { 1,      NO_LED,   4,  10,  7,  13,  22,     25 },
    { 2,      NO_LED,   3,   9,  8,  14,  21,     26 },
    { NO_LED, NO_LED,  28,  30,  32, 34,  33,     NO_LED },
    { NO_LED, NO_LED,  27,  31,  29, 35,  NO_LED, NO_LED },
    { NO_LED, NO_LED,  20,  16,  15, 17,  18,     19 }
}, {
    {25,4},{21,18},{17,31},{35,26},{39,12},{43,0},{60,0},{56,12},{52,26},
    {66,33},{70,20},{74,6},{89,12},{85,25},{81,38},{61,50},{77,55},{93,63},{129,63},{145,55},{161,50},
    {141,38},{137,25},{133,12},{148,6},{152,20},{156,33},{170,26},{166,12},{162,0},{179,0},{183,12},{187,26},
    {205,31},{201,18},{197,4}
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4
} };
*/

#endif