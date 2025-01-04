// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
	_BASE,
	_SPACE,
	_ALT,
	_CTRL,
	_GAME,
};

#define ZL_SPC LT(_SPACE, KC_SPC)
#define ZL_ALT MO(_ALT)
#define ZL_CTL MO(_CTRL)
#define ZL_GAME TG(_GAME)
#define Z_A LGUI_T(KC_A)
#define Z_S LALT_T(KC_S)
#define Z_D LCTL_T(KC_D)
#define Z_F LSFT_T(KC_F)
#define Z_J RSFT_T(KC_J)
#define Z_K RCTL_T(KC_K)
#define Z_L RALT_T(KC_L)
#define Z_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
// │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ Bspc │
// ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
// │ Tb │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ Ent │
// ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
// │      │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   │
// ├────┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┼───┼───┼───┤
// │CtrL│GaL│AltL│      Space / SpcL      │AlL│Btl│CtL│
// └────┴───┴────┴────────────────────────┴───┴───┴───┘

[_BASE] = LAYOUT_solid_space(
	KC_ESC, KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
	KC_TAB, Z_A,     Z_S,  Z_D,  Z_F,  KC_G, KC_H, Z_J,  Z_K,     Z_L,    Z_SCLN,  KC_ENT,
	KC_NO,  KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
	ZL_CTL, ZL_GAME, ZL_ALT,                ZL_SPC,               ZL_ALT, QK_BOOT, ZL_CTL
),

// ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
// │ ~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │   `  │
// ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
// │    │   │Hom│PgU│PgD│End│Lft│Dwn│AUp│Rgt│   │     │
// ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
// │      │   │   │   │   │   │   │   │   │   │   │   │
// ├────┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┼───┼───┼───┤
// │    │   │    │          Trns          │   │   │   │
// └────┴───┴────┴────────────────────────┴───┴───┴───┘

[_SPACE] = LAYOUT_solid_space(
	KC_TILD, KC_1,  KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,  KC_9,    KC_0,  KC_GRV,
	KC_NO,   KC_NO, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
	KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,
	KC_NO,   KC_NO, KC_NO,                       KC_TRNS,                       KC_NO,   KC_NO, KC_NO
),

// ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
// │ ~ │ % │ $ │ \ │ - │ ! │ = │ + │ * │ _ │   │   `  │
// ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
// │    │   │ [ │ { │ ( │ ' │ " │ ) │ } │ ] │   │     │
// ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
// │      │   │   │ ^ │ @ │ & │ | │ ? │ # │   │   │   │
// ├────┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┼───┼───┼───┤
// │    │   │Trns│         Delete         │Trn│   │   │
// └────┴───┴────┴────────────────────────┴───┴───┴───┘

[_ALT] = LAYOUT_solid_space(
	KC_TILD, KC_PERC, KC_DLR, KC_BSLS, KC_MINS, KC_EXLM, KC_PEQL, KC_PPLS, KC_PAST, KC_UNDS, KC_NO, KC_GRV,
	KC_NO,   KC_NO, KC_LBRC,  KC_LCBR, KC_LPRN, KC_QUOT, KC_DQUO, KC_RPRN, KC_RCBR, KC_RBRC, KC_NO, KC_NO,
	KC_NO,   KC_NO, KC_NO,    KC_CIRC, KC_AT,   KC_AMPR, KC_PIPE, KC_QUES, KC_HASH, KC_NO,   KC_NO, KC_NO,
	KC_NO,   KC_NO, KC_TRNS,                       KC_DELETE,                       KC_TRNS, KC_NO, KC_NO
),

// ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
// │F12│F01│F02│F03│F04│F05│F06│F07│F08│F09│F10│ F11  │
// ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
// │F024│F13│F14│F15│F16│F17│F18│F19│F20│F21│F22│ F23 │
// ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
// │      │   │   │   │   │   │   │   │   │   │   │   │
// ├────┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┼───┼───┼───┤
// │Trns│   │    │                        │   │   │Trn│
// └────┴───┴────┴────────────────────────┴───┴───┴───┘

[_CTRL] = LAYOUT_solid_space(
	KC_F12, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
	KC_F24, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23,
	KC_NO,  KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
	KC_TRNS, KC_NO, KC_NO,                      KC_NO,                      KC_NO,  KC_NO,  KC_TRNS
),

// ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──────┐
// │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ Bspc │
// ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬─────┤
// │ Tb │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ Ent │
// ├────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬───┤
// │ Shft │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Sft│
// ├────┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┼───┼───┼───┤
// │Ctrl│   │LAlt│      Space / SpcL      │AlL│GaL│CtL│
// └────┴───┴────┴────────────────────────┴───┴───┴───┘

[_GAME] = LAYOUT_solid_space(
	KC_ESC,  KC_Q,  KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
	KC_TAB,  KC_A,  KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_ENT,
	KC_LSFT, KC_Z,  KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
	KC_LCTL, KC_NO, KC_LALT,               ZL_SPC,               ZL_ALT, ZL_GAME, ZL_CTL
)

};
