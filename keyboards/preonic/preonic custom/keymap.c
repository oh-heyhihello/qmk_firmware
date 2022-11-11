/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _STANDARD,
  _TWO,
  _THREE,
  _FOUR,
  _FIVE,
  _SIX
};

enum preonic_keycodes {
  STANDARD = SAFE_RANGE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  BACKLIT
};

#define _STANDARD 0
#define _TWO 1
#define _THREE 2
#define _FOUR 3
#define _FIVE 4
#define _SIX 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* STANDARD
 * ,-----------------------------------------------------------------------------------.
 * | Caps |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | - _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; : |  ' " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |   UP | / ?  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Gui  | FOUR |THREE |    Space    |TWO   | Enter| Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_STANDARD] = LAYOUT_preonic_grid(
  KC_CAPS, KC_1,    KC_2,    KC_3,      KC_4,         KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_ESC,  KC_Q,    KC_W,    KC_E,      KC_R,         KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,     KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,      KC_F,         KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,      KC_V,         KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_UP,    KC_SLSH,
  KC_LCTL, KC_LALT, KC_LGUI, MO(_FOUR), MO(_THREE),   KC_SPC,  KC_SPC,  MO(_TWO),  KC_ENT,  KC_LEFT, KC_DOWN,  KC_RGHT
),

/* TWO : Right Diamon Modifier Key
 * ,-----------------------------------------------------------------------------------.
 * | Mute |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | = +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ` ~  |      |      |      |      |      |      |      |      |      |  [ { | ] }  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |      | \ |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     | TRNS |      |      |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_TWO] = LAYOUT_preonic_grid(
  KC_MUTE,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_F7,     KC_F8,   KC_F9,    KC_F10,   KC_EQL,
  KC_TRNS,  KC_F11,   KC_F12,  KC_F13,  KC_F14,  KC_F15,   KC_F16,   KC_F17,    KC_F18,  KC_F19,   KC_F20,   KC_DEL,
  KC_GRV,   _______,  _______, _______, _______, _______,  _______,  _______,   _______, _______,  KC_LBRC,  KC_RBRC,
  KC_TRNS,  _______,  _______, _______, _______, _______,  _______,  _______,   _______, _______,  _______,  KC_BSLS,
  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   _______, _______,  _______,   KC_ENT
),

/* THREE : Left Blank Modifier Key
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | = +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ` ~  |      |      |      |      |      |      |      |      |      |  - _ | = +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      | Home |  END | NEXT |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS |    TRNS     |      | TRNS | STOP | PREV |PLAY  |
 * `-----------------------------------------------------------------------------------'
 */
[_THREE] = LAYOUT_preonic_grid(
  _______, KC_EXLM, KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_EQL,
  KC_TRNS, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL,
  KC_GRV,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MINS,  KC_EQL,
  KC_TRNS, _______, _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_END,   KC_MNXT,  KC_RSFT,
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  _______,  KC_TRNS,  KC_MSTP,  KC_MPRV,  KC_MPLY
),

/* FOUR : Left Diamond Modifier Key
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | = +  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  [ { | ] }  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | TRNS |      |      |      | FIVE |      |      |      | PGUP | PGDN | Vol+ | \ |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | SIX  |    TRNS     |      | TRNS | MUTE | Vol- |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FOUR] = LAYOUT_preonic_grid(
  _______, _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, _______, KC_EQL,
  KC_TRNS, _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, _______, KC_DEL,
  _______, _______, _______,   _______,   _______,  _______, _______,  _______, _______, _______, KC_LBRC, KC_RBRC,
  KC_TRNS, _______, _______,   MO(_FIVE), _______,  _______, _______,  _______, KC_PGUP, KC_PGDN, KC_VOLU, KC_BSLS,
  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   MO(_SIX), KC_TRNS, KC_TRNS,  _______, KC_TRNS, KC_MUTE, KC_VOLD, _______
),

/* FIVE : FOUR (L Diamond) + V
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |Num / |Num * |Num - |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS |   1  |   2  |   3  |   4  |Num 7 |Num 8 |Num 9 |Num + |      |      | BSPC |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TRNS |  F1  |  F2  |  F3  |  F4  |Num 4 |Num 5 |Num 6 |  ,   |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | TRNS |  F7  |  F8  |  F9  |  F10 |Num 1 |Num 2 |Num 3 |Num = |      | Home |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TRNS | TRNS | TRNS | TRNS | TRNS |    NUM 0    |Num . |NumENT|      | End  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FIVE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, KC_DEL,
  KC_TRNS, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______, _______, KC_BSPC,
  KC_TRNS, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_COMM, _______, _______, _______,
  KC_TRNS, _______, _______, KC_TRNS, _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______, KC_HOME, _______,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_ENT,  _______, KC_END,  _______
),

/* SIX : FOUR (L Diamond) + THREE (L Blank)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |SysSlp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |RGBTOG|Mode +|Hue + |Sat + |Brite+|      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |Mode -|Hue - |Sat - |Brite-|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SIX] = LAYOUT_preonic_grid(
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_SYSTEM_SLEEP,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______,
  _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

  /* Encoder: No Modifiers: Cursor Move, Caps Lock Press 
   * Encoder: Layer TWO (R Diamond) : Volume Control, Mute Press
   *
   */

bool encoder_update_user(uint8_t index, bool clockwise) {
 if (IS_LAYER_ON(_TWO)) {
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    } else {
      if (clockwise) {
        tap_code(KC_RIGHT);
      } else {
        tap_code(KC_LEFT);
      }
  }
    return false;
}