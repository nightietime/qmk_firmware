
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
  GIT_ADD = SAFE_RANGE,
  GIT_COMMIT,
  GIT_PUSH,
  FORTUNE,
  DISCORD
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case GIT_ADD:
				SEND_STRING("git add ."SS_TAP(X_ENTER));
        break;
      case GIT_COMMIT:
        SEND_STRING("git commit -m ");
        break;
      case GIT_PUSH:
        SEND_STRING("git push"SS_TAP(X_ENTER));
        break;
      case FORTUNE:
        SEND_STRING("/fortune"SS_TAP(X_ENTER));
        break;
      case DISCORD:
        SEND_STRING("/discord"SS_TAP(X_ENTER));
        break;
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
    GIT_ADD, GIT_COMMIT, GIT_PUSH,
    FORTUNE, DISCORD,    KC_ENT
  )
};

void matrix_init_user(void) {
  #ifdef BACKLIGHT_ENABLE
    backlight_level(0);
  #endif
}
