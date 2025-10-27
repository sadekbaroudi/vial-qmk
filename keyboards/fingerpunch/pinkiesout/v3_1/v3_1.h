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
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define ___ KC_NO

#define LAYOUT_pinkiesout( \
    K50, K00, K01, K02, K03, K04, K62,           K65, K05, K06, K07, K80, K53, K86, \
    K60, K10, K11, K12, K13, K14, K72,           K75, K15, K16, K17, K81, K55, K87, \
    K70, K20, K21, K22, K23, K24, K63,           K66, K25, K26, K27, K82, K56, K67, \
    K71, K30, K31, K32, K33, K34, K51,           K52, K35, K36, K37, K83, K57, K77, \
              K40, K41, K42, K43, K44, K76, K73, K45, K46, K47, K84, K85 \
) \
{ \
    { K00, K07, K02, K04, K05, K06, K03, K01 }, \
    { K10, K17, K12, K14, K15, K16, K13, K11 }, \
    { K20, K27, K22, K24, K25, K26, K23, K21 }, \
    { K30, K37, K32, K34, K35, K36, K33, K31 }, \
    { K40, K47, K42, K44, K45, K46, K43, K41 }, \
    { K50, K57, K52, ___, K55, K56, K53, K51 }, \
    { K60, K67, K62, ___, K65, K66, K63, ___ }, \
    { K70, K77, K72, ___, K75, K76, K73, K71 }, \
    { K80, K87, K82, K84, K85, K86, K83, K81 } \
}
