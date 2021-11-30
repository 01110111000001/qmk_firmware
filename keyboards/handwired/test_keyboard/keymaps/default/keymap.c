/* Copyright 2021 01110111000001
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

enum layers {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( //Default layer of the Keymap used by the keyboard
        KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_F21, KC_F22, KC_F20, KC_DELETE,
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_BSPACE, KC_HOME,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_RBRACKET, KC_ENTER,  KC_PGUP,
        KC_F23, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_NONUS_HASH, KC_PGDOWN,
        KC_LSHIFT, KC_NONUS_BSLASH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT, KC_END,
        KC_LCTRL, MO(_FN), KC_LGUI, KC_LALT, KC_SPACE, KC_RALT, KC_APPLICATION, KC_RCTRL, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT( //Layer activated by keeping the FN key pressed
        KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_PAUSE, KC_PSCREEN, KC_NUMLOCK, KC_CAPSLOCK,
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK, KC_MINUS, KC_EQUAL, KC_BSPACE, KC_HOME,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_MINUS, KC_LBRACKET, KC_RBRACKET, KC_ENTER,  KC_PGUP,
        KC_CAPSLOCK, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_PLUS, KC_QUOTE, KC_NONUS_HASH, KC_PGDOWN,
        KC_LSHIFT, KC_NONUS_BSLASH, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_KP_0, KC_KP_ENTER, KC_KP_DOT, KC_KP_SLASH, KC_RSHIFT, KC_END,
        KC_LCTRL, _______, KC_LGUI, KC_LALT, KC_SPACE, KC_RALT, KC_APPLICATION, KC_RCTRL, KC_MEDIA_PREV_TRACK, KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
    )
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_A);
        } else {
            tap_code(KC_B);
        }
    }
    return true;
}

#endif
