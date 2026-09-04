#include <U8g2lib.h>
#include <Wire.h>

// Constructor with reset statement
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// If still static, try this one:
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int SOIL_PIN = A0;

void setup() {
  Serial.begin(9600);

  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(20, 30, "Soil Sensor Test");
  u8g2.sendBuffer();
  delay(2000);
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);

  // Decide dry or wet
  String condition;
  if (soilValue > 500) {
    condition = "DRY";
  } else {
    condition = "WET";
  }

  // Show on OLED
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 12, "Soil Moisture Sensor");

  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(0, 35);
  u8g2.print("Value: ");
  u8g2.print(soilValue);

  u8g2.setCursor(0, 55);
  u8g2.print("Status: ");
  u8g2.print(condition);

  u8g2.sendBuffer();

  // Serial Monitor
  Serial.print("Soil Value: ");
  Serial.print(soilValue);
  Serial.print(" --> ");
  Serial.println(condition);

  delay(1000);
}