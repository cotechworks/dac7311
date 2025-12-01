#include <dac7311.h>

dac7311 myDAC(D7);

void setup() {
  myDAC.begin();
  myDAC.write(1024);
}

void loop() {
}