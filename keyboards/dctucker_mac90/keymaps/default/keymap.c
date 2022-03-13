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
#include QMK_KEYBOARD_H

#define KC_____ KC_TRNS
#define KC_FN_0 MO(5)
#define KC_FN_1 MO(1)
#define KC_FN_2 MO(3)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_NUM,
	_FN,
	_FNUM,
	_MOUSE,
	_XTRA
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	QMKBEST = SAFE_RANGE,
	QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* layer 0 */
	[_BASE] = KEYMAP(
			FN_2, FN_1, ESC, GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSPC,  INS, HOME, PGUP, \
			F7,   F8,   F9,  TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS,  DEL,  END, PGDN, \
			F4,   F5,   F6,  ESC,          A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,        F13,  F14,  F15, \
			F1,   F2,   F3,                Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,              F17,   UP,  F18, \
			F10,  F11,  F12,                                            SPC,                                ENT, LEFT, DOWN, RGHT, \
			LCTL, LSFT, LALT, LGUI,                                     RGUI, RALT, RSFT, RCTL                    ),
	/* layer 1 */
	[_NUM] = KEYMAP(
			FN_0, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, PMNS, PPLS, ____, PSLS, PAST, PMNS, \
			____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, PEQL,   P7,   P8,   P9, \
			____, ____, ____, ____,       ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,         P4,   P5,   P6, \
			____, ____, ____,             ____, ____, ____, ____, ____, ____, ____, ____, PDOT, PSLS,               P1,   P2,   P3, \
			____, ____, ____,                                           ____,                               PENT,   P0, PDOT, PPLS, \
			____, ____, ____, ____,                                     ____, BTN2, ____, BTN1                    ),
	/* layer 2 */
	[_FN] = KEYMAP(
			____, ____, ____, EJCT, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
			MRWD, MPLY, MFFD, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
			F16 , MSTP,  F19, ____,       ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,       ____, ____, ____, \
			MAIL, CALC,  F20,             ____, ____, ____, ____, ____, ____, ____, ____, PDOT, PSLS,             ____, ____, ____, \
			MUTE, VOLD, VOLU,                                           ____,                               ____, ____, ____, ____, \
			____, ____, ____, ____,                                     ____, ____, ____, ____                    ),
	/* layer 3 */
	[_FNUM] = KEYMAP(
			____, ____, ____, EJCT, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, PMNS, PPLS, ____, PSLS, PAST, PMNS, \
			MRWD, MPLY, MFFD, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, PEQL,   P7,   P8,   P9, \
			F16 , MSTP,  F19, ____,       ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,         P4,   P5,   P6, \
			MAIL, CALC,  F20,             ____, ____, ____, ____, ____, ____, ____, ____, PDOT, PSLS,               P1,   P2,   P3, \
			MUTE, VOLD, VOLU,                                           ____,                               PENT,   P0, PDOT, PPLS, \
			____, ____, ____, ____,                                     ____, BTN2, ____, BTN1                    ),
	/* layer 4 */
	[_MOUSE] = KEYMAP(
			____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
			____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
			____, ____, ____, ____,       ____, ____, ____, ____, ____, LEFT, DOWN,   UP, RGHT, ____, ____,       ____, ____, ____, \
			____, ____, ____,             ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,             ____, MS_U, ____, \
			____, ____, ____,                                           ____,                                ESC, MS_L, MS_D, MS_R, \
			____, ____, ____, ____,                                     ____, ____, ____, ____                    ),
	/* layer 5 */
	[_XTRA] = KEYMAP(
			____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, MINS,  EQL, ____,  INS, HOME, PGUP, \
			____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, LBRC, RBRC, BSLS,  DEL,  END, PGDN, \
			____, ____, ____, ____,       ____, ____, ____, ____, ____, ____, ____, ____, ____, SCLN, QUOT,        F13,  F14,  F15, \
			____, ____, ____,             ____, ____, ____, ____, ____, ____, ____, ____,  DOT, SLSH,              F17,   UP,  F18, \
			____, ____, ____,                                           ____,                                ENT, LEFT, DOWN, RGHT, \
			____, ____, ____, ____,                                     ____, ____, ____, ____                    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QMKBEST:
			if (record->event.pressed) {
				// when keycode QMKBEST is pressed
				SEND_STRING("QMK is the best thing ever!");
			} else {
				// when keycode QMKBEST is released
			}
			break;
		case QMKURL:
			if (record->event.pressed) {
				// when keycode QMKURL is pressed
				SEND_STRING("https://qmk.fm/\n");
			} else {
				// when keycode QMKURL is released
			}
			break;
	}
	return true;
}
/*
    [0] = ACTION_LAYER_MOMENTARY(5),
    [1] = ACTION_LAYER_TAP_TOGGLE(1),
    [2] = ACTION_LAYER_MOMENTARY(3),
*/

