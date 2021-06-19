#include <Arduino.h>
#include <../.pio/libdeps/uno/LiquidCrystal/src/LiquidCrystal.h>
#include <../.pio/libdeps/uno/SimpleDHT/SimpleDHT.h>

#define SensorPin 6

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
SimpleDHT11 dht11(SensorPin);

float temperature = 0;
float humidity = 0;


void setup()
{
  lcd.begin(16, 2);
}

void loop() 
{
  // get temperatrue and humidity
  dht11.read2(&temperature, &humidity, NULL);

  // print to display
  lcd.clear();
  lcd.print("LUFT: " + String((float)humidity) + "%");
  lcd.setCursor(0, 1);
  lcd.print("TEMP: " + String((float)temperature) + (char)223 + "C");

  delay(1000);
}