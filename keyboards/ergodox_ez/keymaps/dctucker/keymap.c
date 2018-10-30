#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

#define ________ KC_TRANSPARENT

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  XTRA,
  ARROW,
  EARROW,
  COMMENT,
  OCCURLY,
  OCBRACK,
  BACKN,
  BARS,
  MONEYQ,
  DASHIFT,
  BCARET,
  
};


#define ZOOMKEY LALT(LCTL(LGUI(KC_Z)))
#define LT1G    LT(1, KC_GRAVE)
#define LT1S    LT(1, KC_SCOLON)
#define LT2EQ   LT(2, KC_EQUAL)
#define ALTEQ   ALT_T(KC_EQUAL)
#define ALTMN   ALGR_T(KC_MINUS)
#define CTLESC  CTL_T(KC_ESCAPE)
#define CTLDEL  CTL_T(KC_DELETE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_ergodox_pretty(
		KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,  LT2EQ  , KC_7   , KC_8   , KC_9   , KC_0   , BCARET , KC_BSPC,
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , ALTEQ  ,  ALTMN  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , MONEYQ ,
		CTLESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J   , KC_K   , KC_L   , LT1S   , KC_QUOT,
		KC_LSFT, KC_Z   , XTRA   , KC_X   , KC_C   , KC_V   , KC_B   ,  KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
		CTLDEL , KC_F1  , LT1G   , KC_BTN1, KC_LGUI,                                      KC_RGUI, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
		                                             KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR,
		                                                      KC_HOME,  KC_PGUP,
		                                      KC_SPC , BARS , KC_END ,  KC_PGDN, RCTL_T(KC_ENTER), KC_SPC
	),

	[1] = LAYOUT_ergodox(
		_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,  _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_DEL ,
		_______, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE, _______,  _______, KC_UP  , KC_P7  , KC_P8  , KC_P9  , KC_PAST, KC_F12 ,
		_______, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV ,                    KC_DOWN, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_F13 ,
		_______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,  _______, KC_PMNS, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, _______,
		_______, _______, _______, _______, _______,                                      KC_P0  , KC_PDOT, KC_PDOT, KC_PENT, KC_F15 ,
		                                            RGB_MOD,  _______,  RGB_TOG,  RGB_SLD,
		                                                      _______,  _______,
		                                  RGB_VAD,  RGB_VAI,  _______,  _______,  RGB_HUD,  RGB_HUI

		
	),

	[2] = LAYOUT_ergodox_pretty(
		_______, KC_F20 , KC_F21 , _______, _______, _______, _______,  _______, KC_VOLD, KC_VOLU, _______, _______, _______, KC_DEL ,
		_______, _______, _______, KC_MS_U, _______, _______, _______,  KC_MUTE, _______, _______, _______, _______, _______, _______,
		KC_CAPS, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                    _______, _______, _______, _______, KC_MPLY,
		KC_CAPS, ZOOMKEY, _______, _______, _______, _______, _______,  _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
		RESET  , _______, _______, KC_BTN1, KC_BTN2,                                      KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
		                                             _______, _______,  _______, _______,
		                                                      _______,  _______,
		                                    _______, _______, _______,  _______, _______, KC_WBAK
	),

	[3] = LAYOUT_ergodox_pretty(
		_______, _______, _______, _______, _______, _______, _______,  _______, KC_AMPR, KC_PAST, KC_LBRC, KC_RBRC, KC_CIRC, _______,
		_______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_DOLLAR,
		_______, _______, _______, _______, _______, _______,                    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_EQL , _______,
		_______, _______, _______, _______, _______, _______, _______,  _______, BACKN  , KC_MINS, EARROW , ARROW  , COMMENT, _______,
		_______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______,
		                                             _______, _______,   _______, _______,
		                                                      _______,   _______,
		                                    _______, _______, _______,   _______, _______, _______
	),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool xtra_sent = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		// dynamically generate these.
		case EPRM:
			if (record->event.pressed) {
				eeconfig_init();
			}
			return false;
			break;
		case RGB_SLD:
			if (record->event.pressed) {
				rgblight_mode(1);
			}
			return false;
			break;
		case BARS:
			if( record->event.pressed ){
				xtra_sent = false;
				layer_state_set(0x00000008);
			} else {
				layer_state_set(0x00000001);
				if( ! xtra_sent ){
					int mods = get_mods();
					if( mods & MOD_BIT(KC_RSHIFT) ){
						send_string("|");
					} else {
						send_string("_");
					}
					xtra_sent = true;
				}
			}
			/*
			if( record->event.pressed ){
				int mods = get_mods();
				if( mods & MOD_BIT(KC_RSHIFT) ){
					add_key(KC_BSLASH);
				} else {
					add_key(KC_LSHIFT);
					send_keyboard_report();
					add_key(KC_MINUS);
				}
			} else {
				del_key(KC_LSHIFT);
				del_key(KC_BSLASH);
				del_key(KC_MINUS);
			}
			send_keyboard_report();
			*/
			return false;
			break;
		case MONEYQ:
			xtra_sent = true;
			if( record->event.pressed ){
				int mods = get_mods();
				add_key(KC_RSHIFT);
				send_keyboard_report();
				if( mods & MOD_BIT(KC_LSHIFT) ){
					add_key(KC_4);
				} else {
					add_key(KC_QUOTE);
				}
				send_keyboard_report();
			} else {
				del_key(KC_RSHIFT);
				del_key(KC_4);
				del_key(KC_QUOTE);
				send_keyboard_report();
			}
			return false;
			break;
		case BCARET:
			xtra_sent = true;
			if( record->event.pressed ){
				int mods = get_mods();
				if( mods & MOD_BIT(KC_LSHIFT) ){
					add_key(KC_RSHIFT);
					send_keyboard_report();
					add_key(KC_6);
				} else {
					add_key(KC_BSLASH);
				}
				send_keyboard_report();
			} else {
				del_key(KC_6);
				del_key(KC_BSLASH);
				del_key(KC_RSHIFT);
			}
			send_keyboard_report();
			return false;
			break;
		case XTRA:
			if( record->event.pressed) {
				xtra_sent = false;
				layer_state_set(0x00000008);
			} else {
				layer_state_set(0x00000001);
				if( ! xtra_sent ){
					int mods = get_mods();
					if( mods & MOD_BIT(KC_RSHIFT) ){
						send_string("=");
					} else {
						send_string(":");
					}
					xtra_sent = true;
				}
			}
			return false;
			break;
		case ARROW:
			if( record->event.pressed ){
				xtra_sent = true;
				send_string("->");
			}
			return false;
			break;
		case EARROW:
			if( record->event.pressed ){
				xtra_sent = true;
				send_string("=>");
			}
			return false;
			break;
		case COMMENT:
			xtra_sent = true;
			if( record->event.pressed ){
				if( get_mods() & MOD_BIT(KC_LSHIFT) ){
					send_string("*/");
				} else {
					send_string("/*");
				}
			}
			return false;
			break;
		case OCCURLY:
			xtra_sent = true;
			if( record->event.pressed ){
				send_string("{");
			} else {
				SEND_STRING("\n}"SS_TAP(X_LEFT)"\n"SS_TAP(X_UP)"\t");
			}
			return false;
			break;
		case OCBRACK:
			xtra_sent = true;
			if( record->event.pressed ){
				send_string("[");
			} else {
				send_string("]");
			}
			return false;
			break;
		case BACKN:
			xtra_sent = true;
			if( record->event.pressed ){
				send_string("\\");
			} else {
				send_string("n");
			}
			return false;
			break;
		case DASHIFT:
			if( record->event.pressed ){
				xtra_sent = false;
				add_key(KC_RSHIFT);
				add_mods(MOD_BIT(KC_RSHIFT));
				send_keyboard_report();
			} else {
				del_key(KC_RSHIFT);
				del_mods(MOD_BIT(KC_RSHIFT));
				send_keyboard_report();
				if( ! xtra_sent ){
					send_string("-");
				}
				xtra_sent = true;
			}
			return false;
			break;
	}
	xtra_sent = true;
	return true;
}

void led_set_user(uint8_t usb_led)
{
	if( usb_led & (1<<USB_LED_CAPS_LOCK) ){
		ergodox_right_led_3_on();
	} else {
		ergodox_right_led_3_off();
	}
}


uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    //ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        //ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
