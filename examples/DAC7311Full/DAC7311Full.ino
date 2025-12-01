#include <dac7311.h>

dac7311 myDAC(D7, 4000000);  // CSピンをD7、クロックスピードを4MHzに設定してインスタンス化

void setup() {
  myDAC.begin();                           // DACの初期化
  myDAC.setPowerDownMode(DAC7311_NORMAL);  // パワーダウンモードを設定(write()実行時に反映)
}

void loop() {
  myDAC.write(2048);  // 出力電圧をVrefの半分に設定
  delay(1000);        // 1秒待機
}