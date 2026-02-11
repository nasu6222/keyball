# --- Vial ---
VIAL_ENABLE = yes
VIA_ENABLE  = no    # 両対応にしたい場合。容量が厳しければ no にしてOK

# --- 必要機能 ---
TAP_DANCE_ENABLE = yes   # タップダンス（QMK機能） :contentReference[oaicite:4]{index=4}
EXTRAKEY_ENABLE  = yes   # 音量などが要るなら。不要なら no にして容量節約

# --- Keyball（トラックボール） ---
POINTING_DEVICE_ENABLE = yes

# --- 不要機能（あなたの要望） ---
RGBLIGHT_ENABLE = no
OLED_ENABLE     = no

# --- 容量削減 ---
LTO_ENABLE      = yes    # リンク時最適化（容量削減の定番）
CONSOLE_ENABLE  = no
COMMAND_ENABLE  = no
MOUSEKEY_ENABLE = no     # 「マウスキー（キーでマウス操作）」不要なら切る（トラックボールは別物）
QMK_SETTINGS    = no     # Vialの “QMK設定” 画面を切って容量・EEPROM節約 :contentReference[oaicite:5]{index=5}
