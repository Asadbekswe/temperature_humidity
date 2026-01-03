#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("DHT22 Monitor");
  lcd.setCursor(0,1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Sensor Error ");
    lcd.setCursor(0,1);
    lcd.print(" Check Wiring ");
    return;
  }

  String status;
  if (h < 30) status = "LOW ";
  else if (h > 70) status = "HIGH";
  else status = "OK  ";

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t,1);
  lcd.print((char)223);
  lcd.print("C   ");

  lcd.setCursor(0,1);
  lcd.print("Hum : ");
  lcd.print((int)h);
  lcd.print("% ");
  lcd.print(status);
}
