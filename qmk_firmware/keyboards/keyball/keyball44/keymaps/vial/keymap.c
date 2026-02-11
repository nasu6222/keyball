#include QMK_KEYBOARD_H
#include "pointing_device.h"

// 重要：TAP_DANCE_ENABLE を yes にした場合、
// “コードで tap_dance_actions を定義しない運用（Vial GUIで設定）” をするなら
// Vial側の実装で吸収される構成が多いですが、環境によっては空定義が必要になる場合があります。
// もしリンクエラーが出たら教えてください（エラー文で分岐します）。

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_DEL   ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
              KC_LALT,KC_LGUI,LCTL_T(KC_LNG2)     ,LT(1,KC_SPC),LT(3,KC_LNG1),                  KC_BSPC,LT(2,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  ),

  // マウス層（あなたの運用に合わせて残す）
  [1] = LAYOUT_universal(
    SSNP_FRE ,  KC_F1   , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,                                         KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    SSNP_VRT ,  _________ , _________  , KC_UP   , KC_ENT   , KC_DEL   ,                                         KC_PGUP  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_BTN3  , KC_F12   ,
    SSNP_HOR ,  _________ , KC_LEFT  , KC_DOWN , KC_RGHT  , KC_BSPC  ,                                         KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _________  , _________  ,
                  _________  , _________ , _________  ,         _________  , _________  ,                   _________  , _________  , _________       , _________  , _________
  ),

  [2] = LAYOUT_universal(
    _________  ,S(KC_QUOT), KC_7     , KC_8    , KC_9     , S(KC_8)  ,                                         S(KC_9)  , S(KC_1)  , S(KC_6)  , KC_LBRC  , S(KC_4)  , _________  ,
    _________  ,S(KC_SCLN), KC_4     , KC_5    , KC_6     , KC_RBRC  ,                                         KC_NUHS  , KC_MINS  , S(KC_EQL), S(KC_3)  , KC_QUOT  , S(KC_2)  ,
    _________  ,S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_RBRC),                                        S(KC_NUHS),S(KC_INT1), KC_EQL   ,S(KC_LBRC),S(KC_SLSH),S(KC_INT3),
                  KC_0     , KC_DOT  , _________  ,         _________  , _________  ,                   KC_DEL   , _________  , _________       , _________  , _________
  ),

  // 旧 Layer3 は RGB/OLED が多いので “スクロール/CPI/保存/ブート” に寄せる
  [3] = LAYOUT_universal(
    _________  , TG(1)    , _________  , _________  , _________  , _________  ,                                        _________  , _________  , _________  , _________  , _________  , _________  ,
    _________  , _________  , _________  , _________  , _________  , SCRL_DVI ,                                        _________  , _______
__  , _________  , _________  , _________  , _________  ,
    _________  , _________  , _________  , _________  , _________  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _________  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _________  ,        _________  , _________  ,                   _________  , _________  , _________       , KBC_RST  , QK_BOOT
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // 最高レイヤーが3のときスクロールモード
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // マウスレイヤー（1）のときだけトラックボール移動を有効
    if (layer_state_is(1)) {
        return mouse_report;
    }
    mouse_report.x = 0;
    mouse_report.y = 0;
    mouse_report.h = 0;
    mouse_report.v = 0;
    return mouse_report;
}
