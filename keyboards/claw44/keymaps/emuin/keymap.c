#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
    _BASE = 0,
    _NUMBER,
    _SUPPORT,
};

// Win & Mac Lang
enum custom_keycodes {
    _JP_LANG,
    _EN_LANG,
};


// layer toggle
#define KC_L_SPC LT(_NUMBER, KC_SPC)
#define KC_R_ENT LT(_SUPPORT, KC_ENT)

// Lang
#define KC_JP_LANG _JP_LANG
#define KC_EN_LANG _EN_LANG

// hold key
#define KC_C_TAB LCTL_T(KC_TAB)      // ctrl
#define KC_C_BS LCTL_T(KC_BSPC)      // ctrl
#define KC_A_DEL ALT_T(KC_DEL)       // alt

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT( \
    //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
        KC_ESC , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_LBRC,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
        KC_C_TAB, KC_A  , KC_S    , KC_D   , KC_F    , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_QUOT,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
        KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, KC_RSFT,
    //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                          KC_LCTL, _EN_LANG, KC_L_SPC, KC_A_DEL,   KC_C_BS, KC_R_ENT, _JP_LANG, KC_RGUI 
    //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
    ),

    [_NUMBER] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0  , KC_MINS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_LSFT, _______, _______, _______, _______, KC_HOME,     KC_END , _______, KC_COMM, KC_DOT , KC_SLSH, KC_RSFT ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          RESET  , _______, _______, _______,     _______, KC_RCTL, _______, _______
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_SUPPORT] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, KC_RCBR, KC_RBRC,    KC_BSLS , KC_PIPE, _______, _______, _______, KC_EQL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, KC_PGUP, KC_PSCR,     KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_LSFT, _______, _______, _______, KC_PGDN, KC_HOME,     KC_END , _______, _______, _______, KC_JYEN, KC_RO  ,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          _______, _______, _______, _______,     _______, _______, _______, _______
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),
};

#ifdef OLED_ENABLE

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Layer: BASE"), false);
            break;
        case _NUMBER:
            oled_write_ln_P(PSTR("Layer: NUMBER"), false);
            break;
        case _SUPPORT:
            oled_write_ln_P(PSTR("Layer: SUPPORT"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Layer: Undefined"), false);
    }
}

void render_logo(void) {
    static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(logo, false);
}

char keylog_str[24]  = {};
char keylogs_str[21] = {};
int  keylogs_str_idx = 0;

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
            keylogs_str[i] = ' ';
        }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
}

const char *read_keylog(void) { return keylog_str; }
const char *read_keylogs(void) { return keylogs_str; }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
    } else {
        render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    switch (keycode) {
        case _EN_LANG:
            if (record->event.pressed) {
                register_code(KC_MHEN);
                register_code(KC_LANG1);
            } else {
                unregister_code(KC_MHEN);
                unregister_code(KC_LANG1);
            }
            break;
        case _JP_LANG:
            if (record->event.pressed) {
                register_code(KC_HENK);
                register_code(KC_LANG2);
            } else {
                unregister_code(KC_HENK);
                unregister_code(KC_LANG2);
            }
            break;
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return rotation;
}

#endif
