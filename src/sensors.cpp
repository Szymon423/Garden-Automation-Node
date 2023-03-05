#include "sensors.h"


HumiditySensor::HumiditySensor(uint8_t sensorPin)
{
    HumiditySensor::sensorPin = sensorPin;
}

HumiditySensor::~HumiditySensor()
{}

float HumiditySensor::readHumidity()
{
    HumiditySensor::readSensorValue();
    return HumiditySensor::humidityValue;
}

void HumiditySensor::readSensorValue()
{
    int valueFromSensor = analogRead(HumiditySensor::sensorPin);
    HumiditySensor::humidityValue = map(valueFromSensor, HumiditySensor::airHumidityValue, HumiditySensor::waterHumidityValue, 0., 100.);
}