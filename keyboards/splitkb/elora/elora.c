/* Copyright 2023 splitkb.com <support@splitkb.com>
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

#include "elora.h"

// BEGIN SADEK
// RGB Matrix definition for Elora
#ifdef RGB_MATRIX_ENABLE

#define NLD NO_LED

// Layout
//     2                          1                            0                  6                            7                          8
//     ┌───────────────────────────────────────────┐                                          ┌───────────────────────────────────────────┐
//     │ MX101, MX105, MX109, MX113, MX117, MX121, │                                          │ MX221, MX217, MX213, MX209, MX205, MX201, │
//     ├───────────────────────────────────────────┤                                          ├───────────────────────────────────────────┤
//     │ MX102, MX106, MX110, MX114, MX118, MX122, │                                          │ MX222, MX218, MX214, MX210, MX206, MX202, │
//     ├───────────────────────────────────────────┤                                          ├───────────────────────────────────────────┤
//     │ MX103, MX107, MX111, MX115, MX119, MX123, │                                          │ MX223, MX219, MX215, MX211, MX207, MX203, │
//     ├───────────────────────────────────────────┴─────────────┐              ┌─────────────┴───────────────────────────────────────────┤
//     │ MX104, MX108, MX112, MX116, MX120, MX124, MX131, MX130, │              │ MX230, MX231, MX224, MX220, MX216, MX212, MX208, MX204, │
//     └────────────────────┬────────────────────────────────────┤              ├───────────────────────────────────┬─────────────────────┘
//     3                    │ MX125, MX126, MX127, MX128, MX129, │              │ MX229, MX228, MX227, MX226, MX225 │                     9
//                          └────────────────────────────────────┘              └───────────────────────────────────┘
//                                4                            5                 11                           10

// #define LAYOUT_myr(
//     2 2 2 1 1 0        NLD NLD         6  7  7 8 8 8
//     2 2 2 1 1 0        NLD NLD         6  7  7 8 8 8
//     3 3 3 4 4 0        NLD NLD         6 10 10 9 9 9
//     3 3 3 4 4 4 5 5             11 11 10 10 10 9 9 9
//             3 4 4 5 5        11 11 10 10  9
//     NLD NLD NLD NLD NLD          NLD NLD NLD NLD NLD
// )


led_config_t g_led_config = { {
//COL  01   02   03   04   05   011   010   09    ROW
    {   5, NLD, NLD, NLD,   5,   5, NLD, NLD }, // 00
    { NLD, NLD, NLD, NLD,   5,   4,   4,   3 }, // 01
    {   1,   1,   0,   0,   0,   4,   4,   4 }, // 02
    {   2,   2,   1,   1,   4,   4,   3,   3 }, // 03
    {   2,   2,   2,   2,   3,   3,   3,   3 }, // 04
    { NLD, NLD, NLD, NLD, NLD, NLD, NLD, NLD }, // 05

    { NLD, NLD,  11,  11, NLD, NLD, NLD,  11 }, // 06
    {   9,  10,  10,  11, NLD, NLD, NLD, NLD }, // 07
    {   10, 10,  10,   6,   6,   6,   7,   7,}, // 08
    {   9,   9,  10,  10,   7,   7,   8,   8 }, // 09
    {   9,   9,   9,   9,   8,   8,   8,   8 }, // 10
    { NLD, NLD, NLD, NLD, NLD, NLD, NLD, NLD }, // 11
}, {
    // { 112, 32 } is the center
    {90 , 0},  // 0
    {45 , 0},  // 1
    {0  , 0},  // 2
    {0  , 64}, // 3
    {45 , 64}, // 4
    {90 , 64}, // 5
    {134, 0},  // 6
    {179, 0},  // 7
    {224, 0},  // 8
    {224, 64}, // 9
    {179, 64}, // 10
    {134, 64}   // 11
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
} };
#endif
// END SADEK