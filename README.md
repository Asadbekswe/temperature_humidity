# 🌡️ Arduino DHT22 Temperature & Humidity Monitor

A simple Arduino project to measure temperature and humidity using a **DHT22 sensor** and display the data on an **I2C LCD**.

---

## 🚀 Features

* Reads temperature in Celsius
* Reads humidity in percentage
* Displays data on 16x2 I2C LCD
* Prints live data to Serial Monitor
* Stable and beginner-friendly setup

---

## 🧰 Components Used

* Arduino Uno
* DHT22 (AM2302) temperature and humidity sensor
* 16x2 I2C LCD display
* Jumper wires
* 10kΩ resistor (required for 4-pin DHT22)

---

## 🔌 Wiring

### DHT22

* VCC → 5V
* GND → GND
* DATA → D2
* 10kΩ resistor between VCC and DATA (only for 4-pin sensor)

### I2C LCD

* VCC → 5V
* GND → GND
* SDA → A4
* SCL → A5

---

## 📦 Required Libraries

Install these libraries using Arduino Library Manager:

* DHT sensor library (by Adafruit)
* Adafruit Unified Sensor
* LiquidCrystal_I2C

---

## 🧠 How It Works

* The DHT22 sends digital temperature and humidity data
* Arduino reads the data every 2 seconds
* Values are shown on the LCD and Serial Monitor

---

## 💻 Example Code

```cpp
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
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT read failed");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %, Temp: ");
  Serial.print(t);
  Serial.println(" C");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");
}
```

---

## ✅ Notes

* Use a **digital pin** for DHT22
* Read interval must be **at least 2 seconds**
* Check LCD I2C address if display is blank

---

## 📸 Demo

Add photos or a short video here to show the project in action.

---

## 📄 License

MIT License.
Free to use, modify, and share.

---



<div style="text-align: center;">
    <a href="https://buymeacoffee.com/Asadbekswe" target="_blank">
        <img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" 
             alt="Buy Me A Book" 
             style="height: 41px !important; 
                    width: 174px !important; 
                    box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important; 
                    -webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;">
    </a>
</div>



## 🙌 Author

Built with Arduino and curiosity.
