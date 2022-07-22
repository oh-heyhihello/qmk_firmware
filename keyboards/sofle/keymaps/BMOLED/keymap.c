#include QMK_KEYBOARD_H

enum sofle_layers {
    _ONE,
    _TWO,
    _THREE,
    _FOUR,
    _FIVE,
};

enum custom_keycodes {
    KC_ONE = SAFE_RANGE,
    KC_TWO,
    KC_THREE,
    KC_FOUR,
    KC_FIVE,
    KC_SIX,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ONE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |St(Tb)|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Caps  |    | Mute  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  UP  | ,    | .    |Sft (?|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LAlt | TWO  | Bcsp | /Space  /       \Space \  |Enter | Left | Down |Right |
 *            |      |      |Enter | LGui |/       /         \      \ |RGUI  |      |      |      |
 *             `----------------------------------'           '------''---------------------------'
 */

[_ONE] = LAYOUT( 
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  LSFT_T(KC_TAB),   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_CAPS,    KC_MUTE, KC_N,    KC_M,    KC_UP, KC_COMM,  KC_DOT,  RSFT_T(KC_SLSH),
                 KC_LCTL,KC_LALT,LT(_TWO,KC_ENT), LGUI_T(KC_BSPC),  KC_SPC,     KC_SPC,  RGUI_T(KC_ENT), KC_LEFT, KC_DOWN, KC_RIGHT
),
/*
 * TWO (LEFT DIAMOND)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Sleep |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | FIVE | PGUP |  UP  | PGDW | Home |      |                    |      |      |      |  F11 | F12  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | FOUR | LEFT | DOWN |RIGHT | End  |      |-------.    ,-------|      |      |      |      |   [  |  ]   |
 * |------+------+------+------+------+------|  Caps |    |       |------+------+------+------+------+------|
 * |THREE |      |      |      |      |      |-------|    |-------|      |      |      |      |   `  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | Trns |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_TWO] = LAYOUT(
  KC_SYSTEM_SLEEP, KC_F1,     KC_F2,    KC_F3,      KC_F4,     KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_EQL,
  LT(_FIVE,KC_BSPC),          KC_PGUP,   KC_UP,    KC_PGDOWN,  KC_HOME,   XXXXXXX,                    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F11,  KC_F12,  KC_DEL,
  LT(_FOUR,KC_ENT),       KC_LEFT,   KC_DOWN,  KC_RIGHT,   KC_END,    XXXXXXX,                    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LBRC,  KC_RBRC,
  MO(_THREE),      XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX, KC_CAPS,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_GRV,  KC_BSLS,
                 XXXXXXX,XXXXXXX,KC_TRNS,XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* THREE (L DIA + L SHIFT)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |   +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |BWR BC|CTL UP|BWR FW|BRW RF|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |CTL LF|CTL DN|CTL RT|      |      |-------.    ,-------|      |      |      |      |   {  |   }  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |   ~  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | Trns |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_THREE] = LAYOUT(
  XXXXXXX, XXXXXXX,        XXXXXXX,       XXXXXXX,         XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         LSFT_T(KC_EQL),
  XXXXXXX, KC_WBAK,        LCTL(KC_UP),   KC_WFWD,         KC_WREF, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,
  XXXXXXX, LCTL(KC_LEFT),  LCTL(KC_DOWN), LCTL(KC_RIGHT),  XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT_T(KC_LBRC), LSFT_T(KC_RBRC),
  XXXXXXX, XXXXXXX,        XXXXXXX,       XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT_T(KC_GRV),  LSFT_T(KC_BSLS),
                           XXXXXXX,       XXXXXXX,         KC_TRNS, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* FOUR (L DIA + TAB)
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Mute |Vol Up| Play |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Prev |Vol Dn| Next |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |Brt Up|Brt Dn|      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | Trns |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FOUR] = LAYOUT(
  XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,                           XXXXXXX,  XXXXXXX  , XXXXXXX,  XXXXXXX ,  XXXXXXX ,XXXXXXX,
  XXXXXXX,  KC_MUTE,  KC_VOLU,   KC_MPLY,  XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  XXXXXXX, KC_MPRV,  KC_VOLD,  KC_MNXT,  XXXXXXX, XXXXXXX,                       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX,XXXXXXX, KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                         XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* FIVE (L DIA + ESC)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |Light |Mode +|Hue + |Sat + |Brite+|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TRNS |      |Mode -|Hue - |Sat - |Brite-|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | Trns |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_FIVE] = LAYOUT(
  XXXXXXX , RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAD,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_TRNS , XXXXXXX, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAI,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

// clang-format on

#ifdef OLED_ENABLE

/* logo */
static void render_logo(void) {
    static const char PROGMEM bmo_logo[] = {
// 'bmo logo', 32x126px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0x00, 0x01, 0x01, 0x01, 0x00, 0xe0, 
        0xe0, 0xe0, 0x00, 0x01, 0x01, 0x01, 0x00, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x70, 0x70, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x70, 0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xcf, 0xcf, 0xdf, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xcf, 0xcf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x03, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf1, 0xf1, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf1, 0xf0, 
        0xf0, 0xf1, 0xf1, 0xf3, 0xf3, 0xf3, 0xf3, 0xf1, 0xf1, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x9c, 0xbc, 0xfe, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe3, 0xc1, 0x81, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x87, 0x87, 0xc7, 0xc7, 0xc7, 0xe7, 0xe7, 0xe7, 
        0xe7, 0xe7, 0xe7, 0xc7, 0xc7, 0xc7, 0x87, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0x80, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 
        0xf1, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
        0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(bmo_logo, sizeof(bmo_logo));
}

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 500  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_bmo(int bmo_X, int bmo_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sitting_1', 32x22px */
                                                   {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x20, 0xe0, 0x20, 0x20, 0xa0, 0x20, 0x20, 0x20, 0x20, 
        0xa0, 0x20, 0x20, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0, 0xff, 0x30, 0x30, 0xb0, 0x32, 0x34, 0x74, 0x70, 
        0x70, 0x30, 0x30, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x13, 0x1f, 0x10, 0x11, 0x13, 0x11, 0x10, 0x10, 0x15, 
        0x10, 0x12, 0x10, 0x1f, 0x13, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                   },

                                                   /* 'sitting_2', 32x22px */
                                                   {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
        0x40, 0x40, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x05, 0x02, 0x00, 0xff, 0xe0, 0xff, 0x30, 0x31, 0xb1, 0x31, 0x34, 0x74, 0x71, 
        0x71, 0x31, 0x30, 0xff, 0xc0, 0x02, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x13, 0x1f, 0x10, 0x11, 0x13, 0x11, 0x10, 0x10, 0x15, 
        0x10, 0x12, 0x10, 0x1f, 0x13, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                    }};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'standing_waving_1', 32x22px */
                                                    {
        0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0xfe, 0x02, 0xfe, 0x02, 0x02, 0x0a, 0x22, 0x42, 0x42, 0x22, 
        0x0a, 0x02, 0x02, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xff, 0x02, 0xff, 0x03, 0x13, 0x3b, 0x13, 0x03, 0x07, 0x57, 
        0x07, 0x23, 0x03, 0xff, 0x02, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f, 0x01, 0x01, 0x01, 0x01, 
        0x1f, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                    },

                                                    /* 'standing_waving_2', 32x22px */
                                                    {
        0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0xfe, 0x02, 0xfe, 0x02, 0x02, 0x0a, 0x22, 0x42, 0x42, 0x22, 
        0x0a, 0x02, 0x02, 0xfe, 0x00, 0x11, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xff, 0x02, 0xff, 0x03, 0x13, 0x3b, 0x13, 0x03, 0x07, 0x57, 
        0x07, 0x23, 0x03, 0xff, 0x12, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f, 0x01, 0x01, 0x01, 0x01, 
        0x1f, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'dancing_1', 32x22px */
                                                   {
        0x00, 0x00, 0x20, 0x40, 0x80, 0x00, 0xfe, 0x02, 0xfe, 0x02, 0x02, 0x2a, 0x42, 0x42, 0x42, 0x2a, 
        0x02, 0x02, 0x02, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x02, 0xff, 0x03, 0x13, 0x3b, 0x13, 0x03, 0x07, 0x57, 
        0x07, 0x23, 0x03, 0xff, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f, 0x01, 0x01, 0x01, 0x01, 
        0x03, 0x05, 0x09, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                   },

                                                   /* 'dancing_2', 32x22px */
                                                   {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x02, 0x2a, 0x42, 0x42, 0x42, 0x2a, 
        0x02, 0x02, 0x02, 0xfe, 0x02, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x02, 0x02, 0x06, 0x04, 0x06, 0x02, 0xff, 0x03, 0x13, 0x3b, 0x13, 0x03, 0x07, 0x57, 
        0x07, 0x23, 0x03, 0xff, 0x02, 0xff, 0x02, 0x06, 0x04, 0x06, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x09, 0x05, 0x03, 0x01, 0x01, 0x01, 0x01, 
        0x1f, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'caps_1', 32x22px */
                                                    {
        0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0xfd, 0x04, 0xfc, 0x04, 0x04, 0x14, 0x14, 0x04, 0x04, 0x14, 
        0xd4, 0xc4, 0x04, 0xfc, 0x00, 0xa0, 0x50, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x10, 0x08, 0x04, 0xff, 0x04, 0xff, 0x06, 0x26, 0x76, 0x26, 0x06, 0x0e, 0xae, 
        0x0e, 0x46, 0x06, 0xff, 0x04, 0x08, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x03, 0x02, 0x02, 0x16, 0x0a, 0x02, 0x02, 0x02, 
        0x16, 0x0a, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                    },

                                                    /* 'caps_1', 32x22px */
                                                    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0xfe, 0x02, 0x02, 0x0a, 0x02, 0x02, 0x02, 0x0a, 
        0x62, 0x62, 0x02, 0xfe, 0x00, 0x50, 0xa8, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0xff, 0x02, 0xff, 0x03, 0x13, 0x3b, 0x13, 0x03, 0x07, 0x57, 
        0x07, 0x23, 0x03, 0xff, 0x04, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f, 0x01, 0x01, 0x01, 0x01, 
        0x1f, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'standing_concerned_2', 32x22px */
                                                     {
        0x00, 0x00, 0x00, 0xc1, 0x02, 0x00, 0xfe, 0x02, 0xfe, 0x02, 0x02, 0x0a, 0x02, 0x62, 0x62, 0x02, 
        0x0a, 0x02, 0x02, 0xfe, 0x00, 0x02, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xff, 0x02, 0xff, 0x03, 0x13, 0x3b, 0x13, 0x03, 0x07, 0x57, 
        0x07, 0x23, 0x03, 0xff, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0b, 0x05, 0x01, 0x01, 0x01, 
        0x0b, 0x05, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                     },

                                                     /* 'standing_concerned_2', 32x22px */
                                                     {
        0x00, 0x00, 0x00, 0x80, 0x05, 0x00, 0xfd, 0x04, 0xfc, 0x04, 0x04, 0x14, 0x04, 0xc4, 0xc4, 0x04, 
        0x14, 0x04, 0x04, 0xfc, 0x01, 0x00, 0x85, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0xff, 0x04, 0xff, 0x06, 0x26, 0x76, 0x26, 0x06, 0x0e, 0xae, 
        0x0e, 0x46, 0x06, 0xff, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x03, 0x02, 0x02, 0x16, 0x0a, 0x02, 0x02, 0x02, 
        0x16, 0x0a, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                                     }};

    /* animation */
    void animate_bmo(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(bmo_X, bmo_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(bmo_X, bmo_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(bmo_X, bmo_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(bmo_X, bmo_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_bmo();
    }

    /* this fixes the screen on and off bug */
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();
}

static void print_status_narrow(void) {

    switch (get_highest_layer(layer_state)) {
        case _ONE:
            oled_set_cursor(0,0);
            oled_write("ONE", false);
            oled_set_cursor(0,2);
            oled_write("two", false);
            oled_set_cursor(0,4);
            oled_write("three", false);
            oled_set_cursor(0,6);
            oled_write("four", false);
            oled_set_cursor(0,8);
            oled_write("five", false);
            break;
        case _TWO:
            oled_set_cursor(0,0);
            oled_write("one", false);
            oled_set_cursor(0,2);
            oled_write("TWO", false);
            oled_set_cursor(0,4);
            oled_write("three", false);
            oled_set_cursor(0,6);
            oled_write("four", false);
            oled_set_cursor(0,8);
            oled_write("five", false);
            break;
        case _THREE:
            oled_set_cursor(0,0);
            oled_write("one", false);
            oled_set_cursor(0,2);
            oled_write("two", false);
            oled_set_cursor(0,4);
            oled_write("THREE", false);
            oled_set_cursor(0,6);
            oled_write("four", false);
            oled_set_cursor(0,8);
            oled_write("five", false);
            break;
        case _FOUR:
            oled_set_cursor(0,0);
            oled_write("one", false);
            oled_set_cursor(0,2);
            oled_write("two", false);
            oled_set_cursor(0,4);
            oled_write("three", false);
            oled_set_cursor(0,6);
            oled_write("FOUR", false);
            oled_set_cursor(0,8);
            oled_write("five", false);
            break;
        case _FIVE:
            oled_set_cursor(0,0);
            oled_write("one", false);
            oled_set_cursor(0,2);
            oled_write("two", false);
            oled_set_cursor(0,4);
            oled_write("three", false);
            oled_set_cursor(0,6);
            oled_write("four", false);
            oled_set_cursor(0,8);
            oled_write("FIVE", false);
            break;
        default:
            oled_set_cursor(0,1);
            oled_write("?", false);
    }


    /* KEYBOARD PET RENDER START */

    render_bmo(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ONE:
            if (record->event.pressed) {
                layer_on(_ONE);
            } else {
                layer_off(_ONE);
            }
            return false;
        case KC_TWO:
            if (record->event.pressed) {
                layer_on(_TWO);
            } else {
                layer_off(_TWO);
            }
            return false;
        case KC_THREE:
            if (record->event.pressed) {
                layer_on(_THREE);
            } else {
                layer_off(_THREE);
            }
            return false;
        case KC_FOUR:
            if (record->event.pressed) {
                layer_on(_FOUR);
            } else {
                layer_off(_FOUR);
            }
            return false;
        case KC_FIVE:
            if (record->event.pressed) {
                layer_on(_FIVE);
            } else {
                layer_off(_FIVE);
            }
            return false;

        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
        case KC_LGUI:
        case LGUI_T(KC_BSPC):
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

            /* KEYBOARD PET STATUS END */
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
         case _ONE:
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
            break;
         case _TWO:
           if (clockwise) {
                    tap_code(KC_UP);
                } else {
                     tap_code(KC_DOWN);
                }
            }
    } else if (index == 1) {
        switch(biton32(layer_state)) {
         case _ONE:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
         case _TWO:
           if (clockwise) {
                    tap_code(KC_BRIU);
                } else {
                    tap_code(KC_BRID);
                }
            break;
        }
    }
    return true;
}

#endif
