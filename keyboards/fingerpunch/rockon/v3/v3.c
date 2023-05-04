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

#include "v3.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 65, 3, 5, 63, 64, 4, 2, 1 },
    { 58, 10, 8, 60, 59, 9, 11, 12 },
    { 51, 17, 19, 49, 50, 18, 16, 15 },
    { 44, 24, 22, 46, 45, 23, 25, 26 },
    { 38, 30, 32, 36, 37, 31, 29, 28 },
    { 42, 47, 34, 56, 53, 67, 21, 0 },
    { 54, 6, 35, 62, 48, 20, 33, 13 },
    { 41, 7, NO_LED, 61, NO_LED, NO_LED, 27, 14 },
    { 55, 52, 39, 40, 68, 43, 57, 66 }
}, {
    {7,1},       {21,1},       {36,2},       {51,1},       {65,5},       {79,10},       {93,14},
    {90,21},     {76,20},      {62,16},      {48,12},      {33,12},      {19,12},       {4,10},
    {2,20},      {16,22},      {31,23},      {46,23},      {60,27},      {74,31},       {88,35},
    {87,50},     {71,42},      {57,38},      {43,33},      {28,34},      {14,33},       {0,31},
    {25,46},     {40,48},      {56,51},      {70,56},      {84,63},
    {99,64},     {112,64},     {125,64},
    {138,63},    {152,56},     {166,51},     {182,48},     {197,46},     {223,31},      {209,33},
    {200,34},    {179,33},     {165,38},     {151,42},     {135,50},     {134,35},      {148,31},
    {162,27},    {176,23},     {191,23},     {206,22},     {220,20},     {218,9},       {203,12},
    {189,12},    {174,12},     {160,16},     {146,20},     {132,24},     {129,14},      {143,10},
    {157,5},     {171,1},      {186,2},      {201,1},      {215,0}
}, {
    1, 4,  4,  4,  4,  4,  1,   // left half - row 1 - left to right
    1, 4,  4,  4,  4,  4,  1,   // left half - row 2 - right to left
    1, 12, 12, 12, 12, 4,  1,   // left half - row 3 - left to right
    1, 4,  4,  4,  4,  4,  1,   // left half - row 4 - right to left
    1, 1,  1,  9,  1,           // left thumbs - left to right
    1, 1,  1,                   // center thumbs - left to right
    1, 9,  1,  1,  1,           // right thumbs - left to right
    1, 4,  4,  4,  4,  4,  1,   // right half - row 4 - right to left
    1, 4,  12, 12, 12, 12, 1,   // right half - row 3 - left to right
    1, 4,  4,  4,  4,  4,  1,   // right half - row 2 - right to left
    1, 4,  4,  4,  4,  4,  1    // right half - row 1 - left to right
} };
#endif

#ifdef AUDIO_ENABLE
// TODO: This is incorrect, see https://github.com/qmk/qmk_firmware/blob/master/docs/feature_audio.md#music-map
const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_rockon(
     58,  59,  60,  61,  62,  63,  64,                 65,  66,  67,  68,  69,  70,  71,
     44,  45,  46,  47,  48,  49,  50,                 51,  52,  53,  54,  55,  56,  57,
     30,  31,  32,  33,  34,  35,  36,                 37,  38,  39,  40,  41,  42,  43,
     16,  17,  18,  19,  20,  21,  22,                 23,  24,  25,  26,  27,  28,  29,
           1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,
                                            0
);
#endif
