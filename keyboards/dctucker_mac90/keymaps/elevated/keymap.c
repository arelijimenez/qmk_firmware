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
#define KC_HACK MO(1)
#define KC_SLEP KC_SYSTEM_SLEEP

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_FN,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	QMKBEST = SAFE_RANGE,
	QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* layer 0 */
	[_BASE] = KEYMAP(
			F7,   F8,   F9,  GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSPC,  P7 ,   P8,   P9, \
			F4,   F5,   F6,  TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS,  P4 ,   P5,   P6, \
			F1,   F2,   F3,  ESC,          A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,        P1 ,   P2,   P3, \
			F10,  F11,  F12,               Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,              P0 ,   UP, PDOT, \
			F13 , CAPS, HACK,                                           SPC,                                ENT, LEFT, DOWN, RGHT, \
			LCTL, LSFT, LALT, LGUI,                                     RGUI, RALT, RSFT, RCTL                    ),
	/* layer 1 */
	[_FN] = KEYMAP(
			MRWD, MPLY, MFFD, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, PMNS, PPLS, DEL , ____, ____, ____, \
			F16 , MSTP,  F19, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, PEQL, ____, ____, ____, \
			BRID, BRIU,  F20, SLEP,       ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,       ____, ____, ____, \
			MUTE, VOLD, VOLU,             ____, ____, ____, ____, ____, ____, ____, ____, PDOT, PSLS,             ____, PGUP, ____, \
			EJCT, BTN1, ____,                                           ____,                               PENT, HOME, PGDN, END , \
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

