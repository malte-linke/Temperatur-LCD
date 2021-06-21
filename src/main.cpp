#include <Arduino.h>
#include <../.pio/libdeps/uno/LiquidCrystal/src/LiquidCrystal.h>
#include <../.pio/libdeps/uno/SimpleDHT/SimpleDHT.h>

#define SensorPin 7

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
SimpleDHT11 dht11(SensorPin);

float temperature = 0;
float humidity = 0;
float temperature_old = 0;
float humidity_old = 0;


void setup()
{
  lcd.begin(16, 2);

  // wait to allow the DHT module to initialize fully
  lcd.print("Lade...");
  delay(2000);
}

void loop() 
{
  delay(1000);
  
  // get temperatrue and humidity
  // also ignore all errors
  dht11.read2(&temperature, &humidity, NULL);

  if (humidity == humidity_old && temperature == temperature_old) return; // only update screen if needed
  humidity_old = humidity;
  temperature_old = temperature;

  // print to display
  lcd.clear();
  lcd.print("LUFT: " + String((float)humidity) + "%");
  lcd.setCursor(0, 1);
  lcd.print("TEMP: " + String((float)temperature) + (char)223 + "C");
}