#include "Arduino.h"

class HumiditySensor 
{
private:
    uint8_t sensorPin;
    float humidityValue;
    void readSensorValue();
    int waterHumidityValue = 660;
    int airHumidityValue = 4000;
    
public:
    float readHumidity();
    HumiditySensor(uint8_t);
    ~HumiditySensor();
    void update();
};
