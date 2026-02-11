#pragma once

// ---- Vial 識別子（8バイト）
// 例：適当に作らず、後で固定の値にしてください（同じ値を使い続ける）
#define VIAL_KEYBOARD_UID {0x10, 0x32, 0x54, 0x76, 0x98, 0xBA, 0xDC, 0xFE}

// まずは動作確認優先（セキュリティ弱）
// 動いたら VIAL_INSECURE を消して、unlock combo を設定するのがおすすめ :contentReference[oaicite:8]{index=8}
#define VIAL_INSECURE

// ---- 必要機能（EEPROM節約：枠を減らす）
// レイヤー数（今 5 → まず 4、厳しければ 3） :contentReference[oaicite:9]{index=9}
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// マクロ枠（必要最小限に。例：16）
#define DYNAMIC_KEYMAP_MACRO_COUNT 16

// タップダンス枠（例：8〜16。必要数に合わせる） :contentReference[oaicite:10]{index=10}
#define VIAL_TAP_DANCE_ENTRIES 12

// Key Overrides / Combos などは使わないなら枠0相当で節約（切るなら rules.mk でも no） :contentReference[oaicite:11]{index=11}
#define VIAL_COMBO_ENTRIES 0
#define VIAL_KEY_OVERRIDE_ENTRIES 0

// ---- あなたの既存設定（必要なら移植）
#define TAP_CODE_DELAY 5
#define TAPPING_TERM 170
#define HOLD_ON_OTHER_KEY_PRESS
