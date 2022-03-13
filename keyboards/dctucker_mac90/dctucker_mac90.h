/* Copyright 2022 Casey Tucker
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

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, K018, K019, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, \
    K200, K201, K202, K203,       K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215,       K217, K218, K219, \
    K300, K301, K302,             K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,             K317, K318, K319, \
    K400, K401, K402,                                           K410,                               K416, K417, K418, K419, \
                      K503, K504, K505, K506,                                     K513, K514, K515, K516                    \
) { \
    { KC_##K000, KC_##K001, KC_##K002, KC_##K003, KC_##K004, KC_##K005, KC_##K006, KC_##K007, KC_##K008, KC_##K009, KC_##K010, KC_##K011, KC_##K012, KC_##K013, KC_##K014, KC_##K015, KC_##K016, KC_##K017, KC_##K018, KC_##K019, }, \
    { KC_##K100, KC_##K101, KC_##K102, KC_##K103, KC_##K104, KC_##K105, KC_##K106, KC_##K107, KC_##K108, KC_##K109, KC_##K110, KC_##K111, KC_##K112, KC_##K113, KC_##K114, KC_##K115, KC_##K116, KC_##K117, KC_##K118, KC_##K119, }, \
    { KC_##K200, KC_##K201, KC_##K202, KC_##K203, KC_NO,     KC_##K205, KC_##K206, KC_##K207, KC_##K208, KC_##K209, KC_##K210, KC_##K211, KC_##K212, KC_##K213, KC_##K214, KC_##K215, KC_NO,     KC_##K217, KC_##K218, KC_##K219, }, \
    { KC_##K300, KC_##K301, KC_##K302, KC_NO,     KC_NO,     KC_##K305, KC_##K306, KC_##K307, KC_##K308, KC_##K309, KC_##K310, KC_##K311, KC_##K312, KC_##K313, KC_##K314, KC_NO,     KC_NO,     KC_##K317, KC_##K318, KC_##K319, }, \
    { KC_##K400, KC_##K401, KC_##K402, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_##K410, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_##K416, KC_##K417, KC_##K418, KC_##K419, }, \
    { KC_NO,     KC_NO,     KC_NO,     KC_##K503, KC_##K504, KC_##K505, KC_##K506, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_##K513, KC_##K514, KC_##K515, KC_##K516, KC_NO,     KC_NO,     KC_NO,     }, \
}
