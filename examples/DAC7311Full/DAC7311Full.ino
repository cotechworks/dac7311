#include <dac7311.h>

dac7311 myDAC(D7, 4000000);  // CSピンをD7、クロックスピードを4MHzに設定してインスタンス化

void setup() {
  Serial.begin(115200);

  myDAC.begin();                           // DACの初期化
  myDAC.setPowerDownMode(DAC7311_NORMAL);  // パワーダウンモードを設定(write()実行時に反映)
  myDAC.write(0);                          // 電圧を0Vに設定
}

void loop() {
  if (Serial.available() > 0) {  //受信データがある場合
    delay(10);
    int val = Serial.parseInt();  // 文字列データを数値に変換

    while (Serial.available() > 0) {  // 受信バッファクリア
      char t = Serial.read();
    }

    myDAC.write(val);  // 出力電圧を設定}
  }
}