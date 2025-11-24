#include <ArduinoBLE.h>

void setup() {
  Serial.begin(9600);
  if (!BLE.begin()) {

    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);

  }

}

void loop() {
  Serial.println("BLE Central scan");
  

  BLE.scan(); 

  delay(4000); // Scan pendant 4s


  BLEDevice peripheral = BLE.available();
  int count = 0;

  // Tant qu'il y a des périphériques disponibles à traiter
  while (peripheral) {
    Serial.print("Device found: ");
    Serial.print(peripheral.address());
    Serial.print(" (RSSI: ");
    Serial.print(peripheral.rssi());
    Serial.println(" dBm)");


    count++;
    peripheral = BLE.available(); 
  }

  BLE.stopScan(); //A mon avis ca effface la liste des périphériques donc faut le mettre après BLE.available()

  if (count == 0) {
    Serial.println("Nothing found.");
  } else {
    Serial.print("Scan is over. Devices found : ");
    Serial.println(count);
  }

  
  delay(5000); 
}