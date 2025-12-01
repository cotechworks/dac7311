#include <dac7311.h>

dac7311 myDAC(D7);  // CSピンをD7に設定してインスタンス化

void setup() {
  myDAC.begin();  // DACの初期化
}

void loop() {
  myDAC.write(2048);  // 出力電圧をVrefの半分に設定
  delay(1000);        // 1秒待機
}