#pragma once

#include <Arduino.h>
#include <SPI.h>

enum dac7311_powerdown_t {
  DAC7311_NORMAL = 0b00,
  DAC7311_1K_TO_GND = 0b01,
  DAC7311_100K_TO_GND = 0b10,
  DAC7311_HIGH_IMPEDANCE = 0b11
};

class dac7311 {
public:
  dac7311(int csPin, long clockSpeed = 1000000);
  void begin();
  void write(int value);
  void setPowerDownMode(dac7311_powerdown_t mode);

private:
  SPISettings _mySPISettings;
  int _csPin;
  dac7311_powerdown_t _powerDownMode;
};