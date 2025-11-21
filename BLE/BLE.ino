#include <ArduinoBLE.h>

void setup() {
  Serial.begin(9600);
  if (!BLE.begin()) {

    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);

  }

}

void loop() {
  // begin initialization

  Serial.println("BLE Central scan");

  // start scanning for peripheral

  BLE.scan();

  BLEDevice peripheral = BLE.available();

  if (peripheral) {
    Serial.println(peripheral.address());


  } else {
    Serial.println("Found none");
  }
  delay(5000);
  BLE.stopScan();
}

