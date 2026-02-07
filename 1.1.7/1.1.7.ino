#include <DHT.h>

DHT dht(A0, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature(); 

  if (isnan(hum) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  Temperature: ");
  Serial.print(temp);
  Serial.println("°C");

  delay(1000);
}
