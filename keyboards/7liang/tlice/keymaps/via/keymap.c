/* Copyright 2022 7Liang(@skyjun)
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _L1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_via_4x13(
    // ,-KC_ESC---------------------------------------------------------------------------KC_WH_U-------------------------------------------------------------------------------.
                        KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                 KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_DEL,    KC_BSPC,
    // |-KC_GRV---|---|----------|----------|----------|----------|----------|----------|-KC_WH_D--|----------|----------|----------|----------|----------|----------|----------|
                        KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                 KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_WH_U,   KC_ENT,
    // |----------|---|----------|----------|----------|----------|----------|----------|---BTN2---|----------|----------|----------|----------|----------|----------|----------|
                        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                 KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
    // |----------|---|----------|----------|----------|----------|----------|----------|---BTN1---|----------|----------|----------|----------|----------|----------|----------|
                        KC_LCTL,   KC_LGUI,   KC_LALT,   KC_ESC,    KC_GRV,    KC_SPC,               KC_SPC,    KC_BTN1,   KC_BTN2,   KC_RALT,   KC_WH_D,   KC_RGUI,   KC_RCTL
    // `------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
    ),

    [_L1] = LAYOUT_via_4x13(
    // ,-KC_ESC---------------------------------------------------------------------------KC_WH_U-------------------------------------------------------------------------------.
                        _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,
    // |-KC_GRV---|---|----------|----------|----------|----------|----------|----------|-KC_WH_D--|----------|----------|----------|----------|----------|----------|----------|
                        _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,
    // |----------|---|----------|----------|----------|----------|----------|----------|---BTN2---|----------|----------|----------|----------|----------|----------|----------|
                        _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,
    // |----------|---|----------|----------|----------|----------|----------|----------|---BTN1---|----------|----------|----------|----------|----------|----------|----------|
                        _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______
    // `------------------------------------------------------------------------------------------------------------------------------------------------------------------------'
    )
};

bool encoder_update_user(uint8_t index, bool clockwise)
{
    switch (index)
    {
        case 0:
            if (clockwise) {
                tap_code16(dynamic_keymap_get_keycode(biton32(layer_state), 1, 11));
            } else {
                tap_code16(dynamic_keymap_get_keycode(biton32(layer_state), 3, 10));
            }
            break;

        default: break;
    }

    return true;
}
