#include <ArduinoBLE.h>

void setup() {
  Serial.begin(9600);
  BLEService service("12345678-1234-1234-1234-1234567890ab");

  if (!BLE.begin()) {

    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);

  }

  BLE.setAdvertisedService(service); 
  BLE.advertise();
}



void loop() {
  // put your main code here, to run repeatedly:

}
