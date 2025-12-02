#include <ArduinoBLE.h>
#include <SPI.h>
#include <WiFi.h>

void setup() {
  Serial.begin(9600);
  if (!BLE.begin()) {

    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1);

  }

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

}

void loop() {
  Serial.println("BLE Central scan");
  

  BLE.scan(); 

  delay(5000); // Scan pendant 4s


  BLEDevice peripheral = BLE.available();
  int count = 0;

  // Tant qu'il y a des périphériques disponibles à traiter
  Serial.print(peripheral.serviceCount());
  Serial.println();
  while (peripheral) {
    Serial.print("Device found: ");
    Serial.print(peripheral.address());
    Serial.print(" (RSSI: ");
    Serial.print(peripheral.rssi());
    Serial.print(" dBm)");
    if (peripheral.hasLocalName()) {
      Serial.print(" Local Name: ");
      Serial.print(peripheral.localName());
    }
    Serial.println();
    


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

  delay(2000);

   // scan for existing networks:
  Serial.println("Scanning available networks...");
  listNetworks();
  delay(3000);

  

}


void listNetworks() {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tBSSID ");
    Serial.print(WiFi.BSSIDstr(thisNet));
    Serial.print("\t");
  }
  Serial.println();
}