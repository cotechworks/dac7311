#include <dac7311.h>

dac7311::dac7311(int csPin, long clockSpeed){
    _csPin = csPin;
    _powerDownMode = DAC7311_NORMAL;

    if(clockSpeed < 0) clockSpeed = 1000000;
    if(clockSpeed > 50000000) clockSpeed = 50000000;
    _mySPISettings = SPISettings(clockSpeed, MSBFIRST, SPI_MODE2);
}

void dac7311::begin(){
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
    SPI.begin();
}

void dac7311::setPowerDownMode(dac7311_powerdown_t mode) {
    _powerDownMode = mode;
}

void dac7311::write(int value){
    if(value < 0) value = 0;
    if(value > 4095) value = 4095;
    uint16_t data = (static_cast<uint16_t>(_powerDownMode) << 14) | (static_cast<uint16_t>(value) << 2);

    digitalWrite(_csPin, LOW);
    SPI.beginTransaction(_mySPISettings);
    SPI.transfer16(data);
    SPI.endTransaction();
    digitalWrite(_csPin, HIGH);
}