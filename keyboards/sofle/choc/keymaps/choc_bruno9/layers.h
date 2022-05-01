enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

typedef struct {
    uint16_t pressedTimer;
    uint16_t lockReleasedTimer;
    bool locked;
    uint16_t keycode;
    uint16_t keycodeTimer;
} layerLockState;

layerLockState raise_lock_state = { .pressedTimer = 2000, .lockReleasedTimer = 0, .locked = false, .keycode = 0 };
layerLockState lower_lock_state = { .pressedTimer = 2000, .lockReleasedTimer = 0, .locked = false, .keycode = 0 };
layerLockState adjst_lock_state = { .pressedTimer = 2000, .lockReleasedTimer = 0, .locked = false, .keycode = 0 };

layerLockState* layer_lock_states[3] = {&lower_lock_state, &raise_lock_state, &adjst_lock_state};

void init_layer_lock_states(void) {
    raise_lock_state.lockReleasedTimer = timer_read();
    lower_lock_state.lockReleasedTimer = timer_read();
    adjst_lock_state.lockReleasedTimer = timer_read();
}

void validate_layers_for_keycode(void) {
    for (int i = 0; i < 2; i++) {
        layerLockState *state = layer_lock_states[i];
        uint16_t keycode = state->keycode;
        if (keycode != 0 && timer_elapsed(state->keycodeTimer) > 150) {
            state->keycode = 0;
            tap_code(keycode);
        }
    }
}

bool process_layer_event(keyrecord_t *record, uint16_t layer, bool update, uint16_t tapKeyCode) {

    layerLockState *state = layer_lock_states[layer-1];

    if (record->event.pressed) {
        // if layer was locked, unlock it and set a timer to differentiate it
        // from tapping event on an unlocked layer trigger
        if (state->locked) {
            state->locked = false;
            state->lockReleasedTimer = timer_read();
        }
        // lock the layer and disable keycode tapping on double tap
        // this will disable the possibility for layer to be set off
        // of the key release event.
        else {
            if (timer_elapsed(state->pressedTimer) < 200){
                state->locked = true;
            }
            state->keycode = 0;
        }

        // if state is not already locked, set at timer to verify
        // on next execution if trigger
        if (!state->locked) {
            state->pressedTimer = timer_read();
        }

        // put layer on
        layer_on(layer);
    }
    else if (!state->locked) {

        // put layer off
        layer_off(layer);

        // upon release, if the release was not triggered by a layer unlocking,
        // considers that this is for a tap event and set the keycode to be sent
        // if the key is not pressed back right away to lock it
        if (tapKeyCode != 0 &&
            timer_elapsed(state->pressedTimer) < 150 &&
            timer_elapsed(state->lockReleasedTimer) > 200 ) {
            state->keycode = tapKeyCode;
            state->keycodeTimer = timer_read();
        }
    }

    if (update) {
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }

    return false;
}



