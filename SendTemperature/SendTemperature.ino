/*
  First Configuration
  This sketch demonstrates the usage of MKR WAN 1300/1310 LoRa module.
  This example code is in the public domain.
*/

#include <MKRWAN.h>
#include "DHT.h"

LoRaModem modem;

// Uncomment if using the Murata chip as a module
// LoRaModem modem(Serial1);
String appEui = "0000000000000000";
String appKey = "90738B7447E027EC5C275C6F4D03A5D4";
String devAddr;

// Sensor setup
DHT my_dht;
int temperature;
int humidity;

struct sensorData{
  int temperature;
  int humidity;
};

void setup() {
  // put your setup code here, to run once:
  my_dht.setup(A1);
  pinMode(A1, OUTPUT);
  Serial.begin(115200);
  while (!Serial);
  // change this to your regional band (eg. US915, AS923, ...)
  if (!modem.begin(EU868)) {
    Serial.println("Failed to start module");
    while (1) {}
  };
  Serial.print("Your module version is: ");
  Serial.println(modem.version());
  if (modem.version() != ARDUINO_FW_VERSION) {
    Serial.println("Please make sure that the latest modem firmware is installed.");
    Serial.println("To update the firmware upload the 'MKRWANFWUpdate_standalone.ino' sketch.");
  }
  Serial.print("Your device EUI is: ");
  Serial.println(modem.deviceEUI());
  Serial.println("LoRa Modulation informations");
  Serial.print("Data Rate: ");
  Serial.println(modem.getDataRate());
  Serial.println(modem.getADR());
  Serial.println(modem.getChannelMask());
  

  appKey.trim();
  appEui.trim();

  int connected;

  connected = modem.joinOTAA(appEui, appKey);
  

  if (!connected) {
    Serial.println("Something went wrong; are you indoor? Move near a window and retry");
    while (1) {}
  }

  delay(3000);
}

void loop() {
  analogRead(A1); //Read the value returned by the sensor
  temperature = my_dht.getTemperature();
  humidity = my_dht.getHumidity();
  
  byte payload[2];
  payload[0] = temperature;
  payload[1] = humidity;

  int err;
  modem.setPort(3);
  modem.beginPacket();
  modem.write(payload, sizeof(payload));
  err = modem.endPacket(true);
  if (err > 0) {
    Serial.println("Message sent correctly!");
  } else {
    Serial.println("Error sending message :(");
  }
  delay(10000);
}

