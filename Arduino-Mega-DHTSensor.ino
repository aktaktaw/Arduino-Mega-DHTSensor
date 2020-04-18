#include <DHT.h>

#define DHTPIN 7 //Pin Number in your board
#define DHTTYPE DHT11
// #define DHTTTYPE DHT22
// #define DHTTYPE DHT21
DHT dht(DHTPIN, DHTTYPE);

float temperature, humidity, fahreheit, heatIndex;


void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHTxx Reading");
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  fahreheit = dht.readTemperature(true);
  heatIndex = dht.computeHeatIndex(temperature, humidity, false);

  if(isnan(temperature)|| isnan(fahreheit) || isnan(humidity) || isnan(heatIndex) ){
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.println(humidity);
  
  Serial.print("temperature(°C): ");
  Serial.println(temperature);

  Serial.print("temperature(°F): ");
  Serial.println(fahreheit);

  Serial.print("Heat Index: ");
  Serial.println(heatIndex);
  
  delay(3000);

  
}
