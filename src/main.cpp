#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>

#define DHTPIN 22
#define DHTTYPE    DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);

volatile float temp;
volatile float hum;

void setup(){
  Serial.begin(115200);

  dht.begin();
}

void loop(){
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  temp = event.temperature;
  Serial.print("\nTemperature = ");
  Serial.print(temp);
  Serial.println(F("°C\n"));
  
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  hum = event.relative_humidity;
  Serial.print("Humidity = ");
  Serial.print(hum);
  Serial.println(F("%\n"));
  delay(1000);
}