#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _BASE 0
#define _NUMBERS 1
#define _SYMBOLS 2
#define _NAVIGATION 3
#define _FUNCTIONS 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ + │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ Ü │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ = │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ Ö │ Ä │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ - │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │ ß │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤DEL│
      *               └───┤SPC├───┐   ┌───┤BSP├───┘
      *                   └───┤TAB│   │ENT├───┘FUN
      *                    NAV└───┘   └───┘NUM
      *                                SYM
      */
    [_BASE] = LAYOUT_split_3x6_3(
        DE_PLUS,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   DE_UDIA,

        KC_KP_EQUAL, MT(MOD_LGUI,KC_A),  MT(MOD_LCTL,KC_S),   MT(MOD_LALT,KC_D),   MT(MOD_LSFT,KC_F),    KC_G,
        KC_H,       MT(MOD_RSFT,KC_J),  MT(MOD_RALT,KC_K),   MT(MOD_RCTL,KC_L),   MT(MOD_RGUI,DE_ODIA), DE_ADIA,

        DE_MINS,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,   KC_M,   DE_COMM,DE_DOT, DE_SLSH,    DE_SS,

        KC_ESC,                 LT(_NAVIGATION,KC_SPC), KC_TAB,
        LT(_SYMBOLS,KC_ENT),    LT(_NUMBERS,KC_BSPC),   LT(_FUNCTIONS,KC_DELETE)
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ + │   │ 7 │ 5 │ 9 │ * │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ = │   │ 4 │ 5 │ 6 │   │       │   │SFT│ALT│CTL│GUI│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ - │   │ 1 │ 2 │ 3 │   │       │   │ : │ , │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤DEL│
      *               └───┤ 0 ├───┐   ┌───┤   ├───┘
      *                   └───┤TAB│   │ENT├───┘
      *                       └───┘   └───┘
      */
    [_NUMBERS] = LAYOUT_split_3x6_3(
        DE_PLUS, KC_NO,KC_7,    KC_8,    KC_9,    KC_KP_ASTERISK,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_KP_EQUAL,KC_NO,KC_4,    KC_5,    KC_6,    KC_NO,             KC_NO,  KC_RSFT, KC_RALT, KC_RCTL, KC_RGUI, KC_NO,
        DE_MINS,KC_NO,KC_1,    KC_2,    KC_3,    KC_NO,             KC_NO,  DE_COLN,  DE_COMM,DE_DOT, DE_SLSH,    KC_NO,
        KC_ESC,     KC_0,    KC_TAB,             KC_ENT, KC_NO,  KC_DELETE
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ + │ ! │ § │ { │ } │ % │       │ ` │ & │ ? │ \ │ ° │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ = │ # │ $ │ ( │ ) │ ~ │       │ ' │ " │ ; │ | │ _ │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ - │ < │ > │ [ │ ] │ € │       │ ^ │ @ │ : │ / │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤DEL│
      *               └───┤SPC├───┐   ┌───┤BSP├───┘
      *                   └───┤TAB│   │   ├───┘
      *                       └───┘   └───┘
      */
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        DE_PLUS,  DE_EXLM,DE_SECT,DE_LCBR,DE_RCBR,DE_PERC,        DE_GRV, DE_AMPR,DE_QUES,DE_BSLS,DE_DEG, KC_NO,
        KC_KP_EQUAL, DE_HASH,DE_DLR, DE_LPRN,DE_RPRN,DE_TILD,        DE_QUOT,DE_DQUO,DE_SCLN,DE_PIPE,DE_UNDS,KC_NO,
        DE_MINS, DE_LABK,DE_RABK,DE_LBRC,DE_RBRC,DE_EURO,        DE_CIRC,DE_AT,  DE_COLN,DE_SLSH,KC_NO,  KC_NO,
                                KC_ESC, KC_BSPC,KC_TAB,         KC_NO,  KC_BSPC,KC_DELETE
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │GUI│CTL│ALT│SFT│   │       │ ← │ ↓ │ ↑ │ → │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │HOM│PDN│PUP│END│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤DEL│
      *               └───┤   ├───┐   ┌───┤BSP├───┘
      *                   └───┤TAB│   │ENT├───┘
      *                       └───┘   └───┘
      */
    [_NAVIGATION] = LAYOUT_split_3x6_3(
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_LGUI,KC_LCTL,KC_LALT,KC_LSFT,KC_NO,      KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_NO,  KC_NO,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_HOME,KC_PGDN,KC_PGUP,KC_END, KC_NO,  KC_NO,
                                KC_ESC, KC_NO,  KC_TAB,     KC_ENT, KC_BSPC,KC_DELETE
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │F12│F7 │F5 │F9 │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F11│F4 │F5 │F6 │   │       │   │SFT│ALT│CTL│GUI│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F10│F1 │F2 │F3 │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤   │
      *               └───┤SPC├───┐   ┌───┤BSP├───┘
      *                   └───┤TAB│   │ENT├───┘
      *                       └───┘   └───┘
      */
    [_FUNCTIONS] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F12,  KC_F7,  KC_F8,  KC_F9,  KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_F11,  KC_F4,  KC_F5,  KC_F6,  KC_NO,     KC_NO,  KC_RSFT,KC_RALT,KC_RCTL,KC_RGUI,KC_NO,
        KC_NO,  KC_F10,  KC_F1,  KC_F2,  KC_F3,  KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                KC_ESC, KC_BSPC,KC_TAB,     KC_ENT, KC_BSPC,KC_NO
    )
};


// Empty keymaps

        // KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        // KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        // KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        //                         KC_ESC, KC_BSPC,KC_TAB,     KC_ENT, KC_BSPC,KC_DELETE
