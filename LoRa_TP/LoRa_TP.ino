#include "DHT.h"

DHT my_dht;
int temperature;

void setup() {
  my_dht.setup(A1);
  pinMode(A1, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  analogRead(A1); //Read the value returned by the sensor
  temperature = my_dht.getTemperature();
  delay(1500); //Add a delay between consecutive readings
  Serial.print("Température ");
  Serial.println(temperature);

}
