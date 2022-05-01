#include "layers.h"

enum accent_type {
    ACC_ACUTE = SAFE_RANGE,
    ACC_GRAVE,
    ACC_CIRC,
    ACC_TREM
};



void tap_code_with_mods(uint16_t keycode, uint8_t state){
    uint8_t temp_mods = get_mods();
    set_mods(state);
    tap_code(keycode);
    set_mods(temp_mods);
}

//void tap_code_no_mods(uint16_t keycode){
//    tap_code_with_mods(keycode, 0);
//}

void tap_accent_code(uint16_t accentType){
    switch (accentType) {
        case ACC_ACUTE : tap_code_with_mods(KC_QUOT, 0); break;
        case ACC_GRAVE : tap_code_with_mods(KC_GRV, 0); break;
        case ACC_CIRC : tap_code_with_mods(KC_6, MOD_BIT(KC_LSFT)); break;
        case ACC_TREM : tap_code_with_mods(KC_QUOT, MOD_BIT(KC_LSFT)); break;
    }
}

void tap_code_accented(uint16_t accentType, uint16_t keycode){
    tap_accent_code(accentType);
    tap_code(keycode);
}

void tap_code_undead(uint16_t keycode){
    tap_code(keycode);
    tap_code(KC_SPC);
}

bool process_tap_code_undead(keyrecord_t *record, uint16_t keycode){
    if (record->event.pressed) {
        tap_code_undead(keycode);
    }
    return false;
}

bool process_tap_code_shifted_undead(keyrecord_t *record, uint16_t keycode){
    if (record->event.pressed) {
        uint8_t temp_mods = get_mods();
        set_mods(temp_mods | MOD_BIT(KC_LSFT));
        tap_code_undead(keycode);
        set_mods(temp_mods);
    }
    return false;
}

bool process_tap_code_shifted(keyrecord_t *record, uint16_t keycode){
    if (record->event.pressed) {
        uint8_t temp_mods = get_mods();
        set_mods(temp_mods | MOD_BIT(KC_LSFT));
        tap_code(keycode);
        set_mods(temp_mods);
    }
    return false;
}
bool process_tap_code_with_mods(keyrecord_t *record, uint16_t keycode, uint8_t mods){
    if (record->event.pressed) {
        tap_code_with_mods(keycode, mods);
    }
    return false;
}

bool process_tap_accent_code(keyrecord_t *record, uint16_t accentType){
    if (record->event.pressed) {
        tap_accent_code(accentType);
    }
    return false;
}

bool process_tap_code_altgr_accented_override(keyrecord_t *record, uint16_t keycode, uint16_t accentType, uint16_t algrkeycode){
    if (record->event.pressed) {
        uint8_t temp_mods = get_mods();
        if (temp_mods & MOD_BIT(KC_RALT)) {
            // strip ralt and reset
            set_mods(temp_mods & ~MOD_BIT(KC_RALT));
            tap_code_accented(accentType, algrkeycode);
            set_mods(temp_mods);
        } else{
            tap_code(keycode);
        }

    }
    return false;
}

bool process_tap_code_altgr_cced_override(keyrecord_t *record, uint16_t keycode){
    if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_RALT)) {
            tap_code(KC_COMM);
        } else{
            tap_code(keycode);
        }
    }
    return false;
}

bool process_tap_code_accented(keyrecord_t *record, uint16_t accentType, uint16_t keycode){
    if (record->event.pressed) {
        tap_code_accented(accentType, keycode);
    }
    return false;
}

bool process_tap_code_grave_undead(keyrecord_t *record){
    if (record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_RALT)) {
            uint8_t temp_mods = get_mods();
            set_mods(temp_mods & ~(MOD_BIT(KC_RALT)));
            tap_code(KC_GRV);
            set_mods(temp_mods);
            return false;
        } else {
            return process_tap_code_undead(record, KC_GRV);
        }
    }
    return false;
}

bool process_prev_word(keyrecord_t *record){
    if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
            register_mods(mod_config(MOD_LALT));
            register_code(KC_LEFT);
        } else {
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_LEFT);
        }
    } else {
        if (keymap_config.swap_lctl_lgui) {
            unregister_mods(mod_config(MOD_LALT));
            unregister_code(KC_LEFT);
        } else {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_LEFT);
        }
    }
    return false;
}

bool process_next_word(keyrecord_t *record){
    if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
            register_mods(mod_config(MOD_LALT));
            register_code(KC_RIGHT);
        } else {
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_RIGHT);
        }
    } else {
        if (keymap_config.swap_lctl_lgui) {
            unregister_mods(mod_config(MOD_LALT));
            unregister_code(KC_RIGHT);
        } else {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_RIGHT);
        }
    }
    return false;
}

bool process_line_start(keyrecord_t *record) {
    if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
            // CMD-arrow on Mac, but we have CTL and GUI swapped
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_LEFT);
        } else {
            register_code(KC_HOME);
        }
    } else {
        if (keymap_config.swap_lctl_lgui) {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_LEFT);
        } else {
            unregister_code(KC_HOME);
        }
    }
    return false;
}

bool process_line_end(keyrecord_t *record){
    if (record->event.pressed) {
        if (keymap_config.swap_lctl_lgui) {
            // CMD-arrow on Mac, but we have CTL and GUI swapped
            register_mods(mod_config(MOD_LCTL));
            register_code(KC_RIGHT);
        } else {
            register_code(KC_END);
        }
    } else {
        if (keymap_config.swap_lctl_lgui) {
            unregister_mods(mod_config(MOD_LCTL));
            unregister_code(KC_RIGHT);
        } else {
            unregister_code(KC_END);
        }
    }
    return false;
}

bool process_mod_event(keyrecord_t *record, uint8_t mod, uint16_t keycode){
    if (record->event.pressed) {
        // CMD-c on Mac, but we have CTL and GUI swapped
        register_mods(mod_config(mod));
        register_code(keycode);
    } else {
        unregister_mods(mod_config(mod));
        unregister_code(keycode);
    }
    return false;
}

bool process_grave_escape_undead(keyrecord_t *record){
    if (record->event.pressed) {
        uint8_t temp_mods = get_mods();

        if (temp_mods & MOD_MASK_GUI) {
            // remove mods
            set_mods(temp_mods & ~(MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI)));
            tap_code_undead(KC_GRV);
            set_mods(temp_mods);

        } else {
            tap_code_with_mods(KC_ESC, 0);
        }
    }
    return false;
}