// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

enum custom_keycodes { LAYER0 = SAFE_RANGE, LAYER1, LAYER2, LAYER3, LAYER4, RGB_EE_ON, RGB_EE_OFF, SP_ALT, SP_GUI, SP_WIN, SP_MAC };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, MO(3), SP_GUI, SP_ALT, MO(1), KC_SPC, KC_RGUI, MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    [_LAYER1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TAB, KC_TAB, KC_TAB, KC_TAB, KC_TAB, KC_NO, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_LAYER2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_GRV, KC_TILD, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL, KC_PIPE, KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_DEL, KC_TRNS, KC_LT, KC_GT, KC_LPRN, KC_RPRN, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_LAYER3] = LAYOUT(KC_NO, SP_WIN, SP_MAC, RGB_TOG, RGB_MOD, RGB_RMOD, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRIU, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

    [_LAYER4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_NO, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// eeprom struct
typedef union {
    uint32_t raw;
    struct { // 32 bits
        bool win_layout : 1;
    };
} user_config_t;

user_config_t user_config;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case DFWIN:
        //     if (record->event.pressed) {
        //         persistent_default_layer_set(1UL << _LAYER0);
        //     }
        //     return false;
        //     break;
        // case DFMAC:
        //     if (record->event.pressed) {
        //         persistent_default_layer_set(1UL << _LAYER1);
        //     }
        //     return false;
        //     break;
        case RGB_EE_ON:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                // eeconfig_update_kb not needed, saved to ee as docs say
                rgblight_enable();
#endif
            }
            return false;
            break;
        case RGB_EE_OFF:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_disable();
#endif
            }
            return false;
            break;
        case SP_ALT:
            if (record->event.pressed) {
                register_code(user_config.win_layout ? KC_LALT : KC_LGUI);
            } else {
                unregister_code(user_config.win_layout ? KC_LALT : KC_LGUI);
            }
            return false;
        case SP_GUI:
            if (record->event.pressed) {
                register_code(user_config.win_layout ? KC_LGUI : KC_LALT);
            } else {
                unregister_code(user_config.win_layout ? KC_LGUI : KC_LALT);
            }
            return false;
        case SP_WIN:
            if (record->event.pressed) {
                user_config.win_layout = 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case SP_MAC:
            if (record->event.pressed) {
                user_config.win_layout = 0;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

// this code runs anytime the keyboard is plugged in
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    // rgblight_enable();

    // eeconfig_update_kb(0);
    // eeconfig_init_user();
#endif
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
}

#ifdef RGBLIGHT_TIMEOUT
static uint32_t key_timer;               // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static void     refresh_rgb(void);       // refreshes the activity timer and RGB, invoke whenever any activity happens
static void     check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool            is_rgb_timeout = false;  // store if RGB has timed out or not in a boolean

void refresh_rgb(void) {
    key_timer = timer_read32(); // store time of last refresh
    if (is_rgb_timeout) {
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
}
void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) // check if RGB has already timeout and if enough time has passed
    {
        rgblight_suspend();
        is_rgb_timeout = true;
        is_rgb_timeout = is_rgb_timeout;
    }
}
#endif

/* Then, call the above functions from QMK's built in post processing functions like so */
/* Runs at the end of each scan loop, check if RGB timeout has occured or not */

void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
#endif
}
/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed) refresh_rgb();
#endif
}
/* Runs after each encoder tick, check if activity occurred */
void post_encoder_update_user(uint8_t index, bool clockwise) {
#ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
#endif
}

// VVV this method appears to disable MO(3) as a key
// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, 1, 2, 3);
// }
