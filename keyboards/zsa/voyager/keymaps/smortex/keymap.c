#include QMK_KEYBOARD_H

// Mome row mods
// ___ GUI Alt Ctl Sft ___    ___ Sft Ctl Alt GUI ___
#define GACS_A LGUI_T(KC_A)
#define GACS_O LALT_T(KC_O)
#define GACS_E LCTL_T(KC_E)
#define GACS_U LSFT_T(KC_U)

#define GACS_H RSFT_T(KC_H)
#define GACS_T RCTL_T(KC_T)
#define GACS_N RALT_T(KC_N)
#define GACS_S RGUI_T(KC_S)

// Thumbs keys
// Keys 1 are the bigger inward buttons:
//       LTH2 LTH1    RTH1 RTH2
#define LTH1 LT(LAYER_NAVIGATION, KC_ESC)
#define LTH2 LT(LAYER_FUNC, KC_SPC)
#define RTH1 LT(LAYER_MOUSE, KC_ENTER)
#define RTH2 LT(LAYER_SYMBOLS, KC_RALT)

enum {
    LAYER_BASE,
    LAYER_FUNC,
    LAYER_NAVIGATION,
    LAYER_MOUSE,
    LAYER_SYMBOLS,
    LAYER_RGB,
    LAYER_RESET,
};

enum {
    GC_BSPC,
    CR_DEL,
    TT_OSL_RESET,
};

const uint16_t PROGMEM gc_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM cr_combo[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM tt_combo[] = {LTH1, RTH1, COMBO_END};

combo_t key_combos[] = {
    [GC_BSPC]      = COMBO(gc_combo, KC_BSPC),
    [CR_DEL]       = COMBO(cr_combo, KC_DEL),
    [TT_OSL_RESET] = COMBO(tt_combo, OSL(LAYER_RESET)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    LT(LAYER_RGB, KC_EQL),
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        CW_TOGG, GACS_A,  GACS_O,  GACS_E,  GACS_U,  KC_I,                         KC_D,    GACS_H,  GACS_T,  GACS_N,  GACS_S,  KC_MINS,
        XXXXXXX, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_BSLS,
                                                     LTH2,    LTH1,       RTH1,    RTH2
    ),
    [LAYER_FUNC] = LAYOUT(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [LAYER_NAVIGATION] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_LLCK, XXXXXXX,                      XXXXXXX, C(KC_PGUP), XXXXXXX, C(KC_PGDN), XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [LAYER_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, MS_WHLU, MS_UP  , MS_WHLD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, QK_LLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     MS_BTN2, MS_BTN1,    XXXXXXX, XXXXXXX
    ),
    [LAYER_SYMBOLS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [LAYER_RGB] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RM_HUEU, RM_SATU, RM_VALU, RM_PREV, LM_SPDU,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RM_TOGG, RM_HUED, RM_SATD, RM_VALD, RM_NEXT, LM_SPDD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
    [LAYER_RESET] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
    ),
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    if (layer == LAYER_BASE)
        return false;

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                switch (keymap_key_to_keycode(layer, (keypos_t){col,row})) {
                case QK_BOOT:
                    rgb_matrix_set_color(index, RGB_RED);
                    break;
                case XXXXXXX:
                    rgb_matrix_set_color(index, RGB_OFF);
                    break;
                case RM_HUEU:
                    {
                        hsv_t hsv = rgb_matrix_get_hsv();
                        hsv.h += 60;
                        hsv.s = 255;
                        hsv.v = 255;
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                    }
                    break;
                case RM_HUED:
                    {
                        hsv_t hsv = rgb_matrix_get_hsv();
                        hsv.h -= 60;
                        hsv.s = 255;
                        hsv.v = 255;
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                    }
                    break;
                case RM_SATU:
                case RM_VALU:
                    {
                        hsv_t hsv = rgb_matrix_get_hsv();
                        hsv.s = 255;
                        hsv.v = 255;
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                    }
                    break;
                case RM_SATD:
                    {
                        hsv_t hsv = rgb_matrix_get_hsv();
                        hsv.s = 0;
                        hsv.v = 255;
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                    }
                    break;
                case RM_VALD:
                    {
                        hsv_t hsv = rgb_matrix_get_hsv();
                        hsv.s = 255;
                        hsv.v = 0;
                        rgb_t rgb = hsv_to_rgb(hsv);
                        rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
                    }
                    break;
                default:
                    // Keep default color
                    break;
                }
            }
        }
    }
    return false;
}
