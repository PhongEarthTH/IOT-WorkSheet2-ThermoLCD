#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f, 16, 2);

float temperature;
float humidity;
DHT dht14(D4,DHT11);

void setup() 
{
  temperature = 0;
  humidity = 0;
  Serial.begin(9600);
  dht14.begin();
  lcd.begin();
}

void loop() 
{
  humidity = dht14.readHumidity();
  temperature = dht14.readTemperature();
  Serial.print("Temperature :");
  Serial.print(temperature);
  Serial.print("  Humidity: ");
  Serial.println(humidity);

  lcd.setCursor(0, 0);
  lcd.print("Hum: " + String(humidity) + " %");
  lcd.setCursor(0, 1); // Change to the second line.
  lcd.print("Temp: " + String(temperature) + " C");

  delay(1000);
}
