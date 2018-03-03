
#include "m6a.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layers {
  _LAYER0
};

enum custom_keycodes {
	MY_CUSTOM_MACRO = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case MY_CUSTOM_MACRO:
				SEND_STRING("QMK is the best thing ever!"); // this is our macro!
				return false;
		}
	}
	return true;
};

// // Fillers to make layering more clear
// #define _______ KC_TRNS
// #define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = KEYMAP(
    MY_CUSTOM_MACRO, KC_B, KC_C,
    KC_D, KC_E, KC_F
  )
};

void matrix_init_user(void) {
  #ifdef BACKLIGHT_ENABLE
    backlight_level(0);
  #endif
}
