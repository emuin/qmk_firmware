参考
- https://kbd.dailycraft.jp/keyboard/firmware/build/
- https://docs.qmk.fm/#/ja/newbs_getting_started

# Windwos

1. run QMK MSYS
2. edit ./keyboards/claw44/keymaps/emuin
3. build
   ```
   cd qmk_firmware/
   git checkout emuin
   git branch
   
   qmk compile -kb claw44 -km emuin
   (or)
   make claw44:emuin
   ```
4. .build/ に .hexファイルが生成される
5. QMK Toolbox で書き込み  
   https://kbd.dailycraft.jp/keyboard/firmware/toolbox/