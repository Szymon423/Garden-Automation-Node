#include <Arduino.h>
#include "hardware.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "sensors.h"


OneWire oneWire(sensor_1_pin);
DallasTemperature sensors(&oneWire);

HumiditySensor hs(sensor_2_pin);



void setup() 
{
  USBSerial.begin(9600);
  defineIO();

  sensors.begin();
}

void loop() 
{
  // USBSerial.write("on\n");
  // setOutput(1, 1);
  // setOutput(2, 1);
  // delay(3000);

  // USBSerial.write("off\n");
  // hardware::setOutput(1, 0);
  // hardware::setOutput(2, 0);
  delay(1000); 


  sensors.requestTemperatures(); 
  USBSerial.println("temperature: " + String(sensors.getTempCByIndex(0)));

  // float humidity = analogRead(sensor_2_pin) * 100.0 / 1024.0;
  int humidity = analogRead(sensor_2_pin);
  USBSerial.println("humidity: " + String(hs.readHumidity()) + "\n");
}