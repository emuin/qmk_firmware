# キーマップ要件

## 全体

- 3レイヤー
- Win/Mac 両対応

## レイヤー1: Base
- 右下 Winキー
- 左下 Ctrl
- かな、英数
## レイヤー2: Number
- スペース押下中
- 最上段 Fn， 上から2段目: 数字
- Home/End
## レイヤー3: Suport
- Enter押下中
- 矢印=vi配列
- Home/End

# ソースメモ

参考: 
- https://leico.github.io/TechnicalNote/QMK/key-customize
- https://qiita.com/rai_suta/items/0376ed4ce6498bb85770  
- 公式キーコード: https://docs.qmk.fm/#/keycodes  
- Win Mac 変換両対応 https://qiita.com/ryohey/items/94e4102957d1d4bbb78f  

LT(layer, kc): タップした場合はキーコードを入力し、ホールドした場合はレイヤー切り替えを行うキーを設定できます。  
CTL_T(kc) 	長押しで Ctrl 、タップで kc  
SFT_T(kc) 	長押しで Shift 、タップで kc  
ALT_T(kc) 	長押しで Alt 、タップで kc  
GUI_T(kc) 	長押しで Gui 、タップで kc  