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
#include "barobord_byomcu.h"
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
                         { 0, 6, 7,13,14,25,26,32,33},//,39},
                         { 1, 5, 8,12,15,24,27,31,34},//,38},
                         { 2, 4, 9,11,16,23,28,30,35},//,37},
                        { 3, 10,17,18,19,20,21,22,29},//,36},
    { NO_LED,NO_LED,NO_LED,NO_LED,NO_LED,39,38,37,36} //,36}
}, {
    {16,8},   {8,16},   {0,24},   {12,32},  {20,16},  {28,8},   {36,0},   {56,0},   {48,8},   {40,24},
    {32,32},  {56,32},  {64,16},  {72,8},   {88,16},  {80,24},  {72,48},  {40,48},  {64,56},  {80,64},
    {120,64}, {136,56}, {160,48}, {128,48}, {120,24}, {112,16}, {128,8},  {136,6},  {144,32}, {168,32},
    {160,24}, {152,8},  {144,0},  {164,0},  {172,8},  {180,16}, {188,32}, {200,24}, {192,16}, {184,8}
}, {
    4, 12, 4,      // col 1 - top down
    4, 4,  12, 4,  // col 2 - bottom up
    4, 12, 4,  4,  // col 3 - top down
    4, 12, 4,      // col 4 - bottom up
    4, 4,  4,      // col 5 - top down
    1, 9,  1,      // thumb left - left right
    1, 9,  1,      // thumb right - left right
    4, 4,  4,      // col 6 - bottom up
    4, 12, 4,      // col 7 - top down
    4, 4,  12, 4,  // col 8 - bottom up
    4, 12, 4,  4,  // col 9 - top down
    4, 12, 4       // col 10 - bottom up
} };
#endif


/*
letters:    q, a, z, 1,  x,  s,  w,  e,  d,  c,  2,  v,  f,  r,  t,  g,  b,  del, up, tab,| bs,  spc, ',   n,   h,   y,   u,   j,   m,   3,   ,,   k,   i,   o,   l,   .,   4,   /,   ;,   p
25 center:  4, 2, 0, 3,  5,  7,  9,  14, 12, 10, 8,  14, 16, 18, 22, 20, 18, 10,  16, 20, | 30,  34,  40,  32,  30,  28,  32,  34,  36,  42,  40,  38,  36,  41,  43,  45,  47,  50,  48,  46
100 center: 16 8, 0, 12, 20, 28, 36, 56, 48, 40, 32, 56, 64, 72, 88, 80, 72, 40,  64, 80, | 120, 136, 160, 128, 120, 112, 128, 136, 144, 168, 160, 152, 144, 164, 172, 180, 188, 200, 192, 184
*/
