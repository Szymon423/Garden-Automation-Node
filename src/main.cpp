#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "hardware.h"
#include "sensors.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


const char* ssid = ""; 
const char* password = "";  
const char* mqtt_server = "192.168.0.122"; 
const char* deviceName = "ESP32_OLED"; 
// const char* deviceName = "ESP32_NO_OLED"; 
IPAddress staticIP(192, 168, 0, 46);

const char* humidityTopic = "humidity";
const char* temperatureTopic = "temperature";

WiFiClient espClient;
PubSubClient client(espClient);


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


OneWire oneWire(sensor_1_pin);
DallasTemperature sensors(&oneWire);

HumiditySensor hs(sensor_2_pin);

void reconnect()
{
  bool ctd = false;
  //funkcja jest wywolywana jesli utracono polaczenie z serwerem
  USBSerial.println("Rozlaczono!");
  while(!ctd)
  {
    USBSerial.print("Laczenie z serwerem...");
    if(client.connect(deviceName))
    {
      ctd = true;
      USBSerial.println("Polaczono!");
    }
    else
    {
      USBSerial.print(".");
      delay(1000);
    }
  }
}

void ustawienieWifi()
{
  delay(10);
  USBSerial.println();
  USBSerial.print("Laczenie z ");
  USBSerial.println(ssid);
  WiFi.begin(ssid, password);

  


  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    USBSerial.print(".");
  }

  USBSerial.println("");
  USBSerial.print("Polaczona z wifi.\nESP otrzymalo adres IP: ");
  USBSerial.println(WiFi.localIP());
}

void setup() 
{
  USBSerial.begin(9600);
  defineIO();
  ustawienieWifi();

  client.setServer(mqtt_server, 1883); 
  client.connect(deviceName);
  sensors.begin();
}

void loop() 
{
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  float humidity = hs.readHumidity();

  String temperature_str = String(temperature);
  String humidity_str = String(humidity);
  
  // USBSerial.write("on\n");
  // setOutput(1, 1);
  // setOutput(2, 1);
  // delay(3000);

  // USBSerial.write("off\n");
  // hardware::setOutput(1, 0);
  // hardware::setOutput(2, 0);
  delay(100); 
  
  USBSerial.println("temperature: " + temperature_str);
  USBSerial.println("humidity: " + humidity_str);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    USBSerial.println(F("SSD1306 allocation failed"));
    for(;;);
  }


  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 10);
  display.println("IP: " + WiFi.localIP().toString());

  display.setCursor(0, 20);
  display.println("humidity: " + humidity_str);

  display.setCursor(0, 30);
  display.println("temperature: " + temperature_str);

  display.display(); 

  char hum[10];
  strcpy(hum, humidity_str.c_str());
  // dtostrf(hs.readHumidity(), 4, 2, hum);

  char temp[10];
  strcpy(temp, temperature_str.c_str());
  // dtostrf(sensors.getTempCByIndex(0), 4, 2, temp);

  if (!client.connected()) 
  {
    reconnect(); 
  }

  if(!client.loop())
  {
    client.connect(deviceName);
  }

  // client.publish(humidityTopic, hum);
  client.publish(temperatureTopic, temp);
}
