 /* Copyright 2022 Brian Low
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
#include "keymap_us_international.h"
#include "helpers.h"

 enum custom_keycodes {
    KC_LOWER = SAFE_RANGE,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,

    BL_GRV,
    BL_GRVU,
    BL_GRVUESC,
    BL_CIRC,
    BL_CIRCU,
    BL_TREM,
    BL_ACU,
    BL_APOS,
    BL_TILDU,
    BL_UNDS,
    BL_SCLN,
    BL_COLN,

    BL_LBRC,
    BL_RBRC,
    BL_LCBR,
    BL_RCBR,

    BL_AGRV,
    BL_EGRV,
    BL_EACU,
    BL_QUOT,
    BL_EQL,
    BL_LT,
    BL_GT,

    // altgr overrides
    BL_7,
    BL_W,
    BL_E,
    BL_R,
    BL_T,
    BL_Y,
    BL_U,
    BL_I,
    BL_O,
    BL_P,
    BL_A,
    BL_S,
    BL_D,
    BL_J,
    BL_K,
    BL_C
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL |  WIN | LALT |LOWER | /Space  /       \Enter \   |RAISE | RALT |  WIN | RCTL |
 *            |      |      |      |      |/        /         \      \ |      |      |      |      |
 *            `----------------------------------'             '------''---------------------------'
 */
[_QWERTY] = LAYOUT( \
    BL_GRVU,    KC_1,   KC_2,     KC_3,    KC_4,    KC_5,                         KC_6,     BL_7,     KC_8,     KC_9,    KC_0,    KC_BSLS,
    KC_ESC,     KC_Q,   BL_W,     BL_E,    BL_R,    BL_T,                         BL_Y,     BL_U,     BL_I,     BL_O,    BL_P,    KC_BSPC,
    KC_TAB,     BL_A,   BL_S,     BL_D,    KC_F,    KC_G,                         KC_H,     BL_J,     BL_K,     KC_L,    KC_SCLN, BL_QUOT,
    KC_LSFT,    KC_Z,   KC_X,     BL_C,    KC_V,    KC_B,     KC_MUTE,   KC_MPLY, KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LCTRL, KC_LGUI, KC_LALT, KC_LOWER, KC_SPC,    KC_ENT,  KC_RAISE, KC_RALT,  KC_RGUI,  KC_RCTRL
),
/* LOWER
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Break| RnTo | Attch|                    |  <<  |  >>  | <(-) | (-)> |  Del |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps | New  | Save | Open | Run  | Dbg  |-------.    ,-------|  P↑  | Dline|  ←W  |  ↑   |  W→  | Shift|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |Shift | Undo | Redo | Copy | Paste| Cut  |       |    |-------|  P↓  |  ←L  |  ←   |  ↓   |   →  |  L→  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | Shift|      |      | /       /       \      \  |      |      |     |      |
 *            |      | +Alt |      |      |/       /         \      \ |      |      |     |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
    KC_F1,    KC_F2,      KC_F3,        KC_F4,         KC_F5,       KC_F6,                             KC_F7,    KC_F8,    KC_F9,         KC_F10,              KC_F11,        KC_F12,
    _______,  KC_INS,     KC_PSCR,      KC_BRK,        LCTL(KC_F10),LCTL(LALT(KC_P)),                  KC_WBAK,  KC_WFWD,  RCTL(KC_MINS), RCTL(RSFT(KC_MINS)), KC_DEL,        _______,
    KC_CAPS,  LCTL(KC_N), LCTL(KC_S),   LCTL(KC_O),    LCTL(KC_F5), KC_F5,                             KC_PGUP,  KC_DLINE, KC_PRVWD,      KC_UP,               KC_NXTWD,      KC_RSFT,
    _______,  LCTL(KC_Z), LCTL(KC_Y),   KC_COPY,       KC_PASTE,    KC_CUT,   _______,       _______,  KC_PGDN,  KC_LSTRT, KC_LEFT,       KC_DOWN,             KC_RGHT,       KC_LEND,
                          _______,      LSFT(KC_LALT), _______,     _______,  _______,       _______,  _______,  _______,  _______,       _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   ´  |   ¨  |   ^  |   ~  |   _  |                    |   =  |   ^  |   7  |   8  |   9  | Calc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   -  |   +  |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Menu |   [  |   ]  |   ;  |   :  |   &  |-------.    ,-------|   /  |   *  |   1  |   2  |   3  | Enter|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   |  |-------|    |-------|   <  |   >  |   0  |   .  |  Del | Esc  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
      BL_GRV,  BL_ACU,   BL_TREM, BL_CIRC, BL_TILDU, BL_UNDS,                         BL_EQL, BL_CIRCU, KC_7,   KC_8,    KC_9,   KC_CALC,
      _______, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,   KC_PERC,                         KC_PMNS, KC_PPLS, KC_4,   KC_5,    KC_6,   _______,
      KC_APP,  BL_LBRC,  BL_RBRC, BL_SCLN, BL_COLN,  KC_AMPR,                         KC_PSLS, KC_PAST, KC_1,   KC_2,    KC_3,   KC_ENT,
      _______, BL_LCBR,  BL_RCBR, KC_LPRN, KC_RPRN,  KC_PIPE, _______,       _______, BL_LT,   BL_GT,   KC_0,   KC_DOT,  KC_DEL, KC_ESC,
                         _______, _______, _______,  _______, _______,       _______, _______, _______,  _______, _______
      ),
 /* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET| Spd+ | Val+ | Sat+ | Hue+ |Mode+ |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Spd- | Val- | Sat- | Hue- |Mode- |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |MacWin|      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MODE_FORWARD,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MODE_REVERSE,                        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,     _______, _______,  _______, _______, _______
)
};

uint16_t rgb_timer;
uint8_t rgb_timer_minutes = 0;
bool rgb_on = false;


// keyboard initialization
void matrix_init_user(void) {
    init_layer_lock_states();
    rgb_timer = timer_read();
}

void matrix_scan_user(void) {
    validate_layers_for_keycode();

    if (rgb_on) {
        if (timer_elapsed(rgb_timer) >= 60000) {
            rgb_timer_minutes += 1;
            rgb_timer = timer_read();
        }
        if (rgb_timer_minutes >= 3) {
            rgblight_disable();
            rgb_on = false;
            rgb_timer_minutes = 0;
        }
    }
 }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    rgb_timer = timer_read();

    if (!rgb_on) {
        rgblight_enable();
        rgb_on = true;
    }

    switch (keycode) {

        // undead keys
        case BL_GRVU : return process_tap_code_grave_undead(record);
        case BL_GRVUESC : return process_grave_escape_undead(record);
        case BL_QUOT : return process_tap_code_undead(record, KC_QUOT);
        case BL_APOS : return process_tap_code_undead(record, ACC_ACUTE);
        case BL_CIRCU : return process_tap_code_shifted_undead(record, KC_6);

        // shift / no shift keys
        case BL_TILDU : return process_tap_code_shifted_undead(record, KC_GRV);
        case BL_UNDS : return process_tap_code_shifted(record, KC_MINS);
        case BL_SCLN : return process_tap_code_with_mods(record, KC_COLN, 0);
        case BL_COLN : return process_tap_code_shifted(record, KC_COLN);
        case BL_LBRC : return process_tap_code_with_mods(record, KC_LBRC, 0);
        case BL_RBRC : return process_tap_code_with_mods(record, KC_RBRC, 0);
        case BL_LCBR : return process_tap_code_shifted(record, KC_LBRC);
        case BL_RCBR : return process_tap_code_shifted(record, KC_RBRC);
        case BL_EQL : return process_tap_code_with_mods(record, KC_EQL, 0);
        case BL_LT : return process_tap_code_shifted(record, KC_COMM);
        case BL_GT : return process_tap_code_shifted(record, KC_DOT);

        // accents keys (dead)
        case BL_GRV : return process_tap_accent_code(record, ACC_GRAVE);
        case BL_CIRC : return process_tap_accent_code(record, ACC_CIRC);

        case BL_TREM : return process_tap_accent_code(record, ACC_TREM);
        case BL_ACU : return process_tap_accent_code(record, ACC_ACUTE);

        // accented keys
        case BL_AGRV : return process_tap_code_accented(record, ACC_GRAVE, KC_A);
        case BL_EGRV : return process_tap_code_accented(record, ACC_GRAVE, KC_E);
        case BL_EACU : return process_tap_code_accented(record, ACC_ACUTE, KC_E);

        // layers keys
        case KC_LOWER: return process_layer_event(record, _LOWER, true, KC_SPC);
        case KC_RAISE: return process_layer_event(record, _RAISE, true, KC_ENT);
        case KC_ADJUST: return process_layer_event(record, _ADJUST, false, 0);

        // word navigation
        case KC_PRVWD: return process_prev_word(record);
        case KC_NXTWD: return process_next_word(record);

        // line navigation
        case KC_LSTRT: return process_line_start(record);
        case KC_LEND: return process_line_end(record);
        case KC_DLINE: return process_mod_event(record, MOD_LCTL, KC_BSPC);

        // copy, paste, cut, undo
        case KC_COPY: return process_mod_event(record, MOD_LCTL, KC_C);
        case KC_PASTE: return process_mod_event(record, MOD_LCTL, KC_V);
        case KC_CUT: return process_mod_event(record, MOD_LCTL, KC_X);
        case KC_UNDO: return process_mod_event(record, MOD_LCTL, KC_Z);

        // altgr overrides
        case BL_7: return process_tap_code_altgr_accented_override(record, KC_7, ACC_CIRC, KC_U);
        case BL_W: return process_tap_code_altgr_accented_override(record, KC_W, ACC_GRAVE, KC_E);
        case BL_E: return process_tap_code_altgr_accented_override(record, KC_E, ACC_ACUTE, KC_E);
        case BL_R: return process_tap_code_altgr_accented_override(record, KC_R, ACC_CIRC, KC_E);
        case BL_T: return process_tap_code_altgr_accented_override(record, KC_T, ACC_TREM, KC_E);
        case BL_Y: return process_tap_code_altgr_accented_override(record, KC_Y, ACC_TREM, KC_Y);
        case BL_U: return process_tap_code_altgr_accented_override(record, KC_U, ACC_CIRC, KC_U);
        case BL_I: return process_tap_code_altgr_accented_override(record, KC_I, ACC_CIRC, KC_I);
        case BL_O: return process_tap_code_altgr_accented_override(record, KC_O, ACC_CIRC, KC_O);
        case BL_P: return process_tap_code_altgr_accented_override(record, KC_P, ACC_TREM, KC_O);
        case BL_A: return process_tap_code_altgr_accented_override(record, KC_A, ACC_GRAVE, KC_A);
        case BL_S: return process_tap_code_altgr_accented_override(record, KC_S, ACC_CIRC, KC_A);
        case BL_D: return process_tap_code_altgr_accented_override(record, KC_D, ACC_TREM, KC_A);
        case BL_J: return process_tap_code_altgr_accented_override(record, KC_J, ACC_TREM, KC_U);
        case BL_K: return process_tap_code_altgr_accented_override(record, KC_K, ACC_ACUTE, KC_I);
        case BL_C: return process_tap_code_altgr_cced_override(record, KC_C);
        default:
            return true;
    }
}

#ifdef ENCODER_ENABLE

void tap_code_if_else(bool is_true, uint16_t trueKeyCode, uint16_t falseKeyCode, uint16_t mods) {

    uint8_t temp_mods = get_mods();

    if (mods != 255) {
        set_mods(mods);
    }

    if (is_true) {
        tap_code(trueKeyCode);
    } else {
        tap_code(falseKeyCode);
    }

    if (mods != 255) {
        set_mods(temp_mods);
    }
}

enum encoder_action {
    TAP_RIGHT_LEFT,
    TAP_UP_DOWN,
    VOLUME_UP_DOWN,
    PAGE_UP_DOWN,
    MOUSE_UP_DOWN,
    TAP_PLUS_MINUS
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }

    uint8_t mod_state = get_mods();
    uint8_t temp_mod = 255;
    uint16_t action;

    switch (index) {
        case 0 :
            action = VOLUME_UP_DOWN;

            // only alt
            if ((mod_state & MOD_MASK_ALT) == MOD_MASK_ALT) {
                action = TAP_RIGHT_LEFT;

                // remove alt mod if lower or raise layer
                if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)){
                    temp_mod = mod_state & ~MOD_BIT(KC_RALT) & ~MOD_BIT(KC_LALT);
                }
            }
            // any mods
            else if (mod_state & MOD_MASK_CSAG) {
                action = TAP_UP_DOWN;
            }
            // any layer is on
            else if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
                action = PAGE_UP_DOWN;
            }
            break;
        default:
            action = MOUSE_UP_DOWN;

            // only alt
            if ((mod_state & MOD_MASK_ALT) && !(mod_state & MOD_MASK_CSG)) {
                action = TAP_UP_DOWN;

                // remove alt mod if lower or raise layer
                if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)){
                    temp_mod = mod_state & ~MOD_BIT(KC_RALT) & ~MOD_BIT(KC_LALT);
                }
            }
            // alt and shift only
            else if ((mod_state & MOD_MASK_ALT) && (mod_state & MOD_MASK_SHIFT) && !(mod_state & MOD_MASK_CG)) {
                action = TAP_PLUS_MINUS;
            }
            // any modifier
            else if (mod_state & MOD_MASK_CSAG) {
                action = TAP_RIGHT_LEFT;
            }
            // any layer is on
            else if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
                action = TAP_RIGHT_LEFT;
            }
            break;
    }

    switch(action)    {
        case TAP_RIGHT_LEFT : tap_code_if_else(clockwise, KC_RGHT, KC_LEFT, temp_mod); break;
        case TAP_UP_DOWN : tap_code_if_else(clockwise, KC_DOWN, KC_UP, temp_mod); break;
        case VOLUME_UP_DOWN : tap_code_if_else(clockwise, KC_VOLU, KC_VOLD, temp_mod); break;
        case PAGE_UP_DOWN : tap_code_if_else(clockwise, KC_PGDN, KC_PGUP, temp_mod); break;
        case MOUSE_UP_DOWN : tap_code_if_else(clockwise, KC_WH_D, KC_WH_U, temp_mod); break;
        case TAP_PLUS_MINUS : tap_code_if_else(clockwise, KC_PLUS, KC_MINS, temp_mod); break;
    }

    return false;
}

#endif






#include "oled.h"

