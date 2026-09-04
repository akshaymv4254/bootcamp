#include <U8g2lib.h>
#include <Wire.h>

// Constructor for 1.3" OLED
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int WATER_LEVEL_PIN = A1;   // Signal pin of HW-038

void setup() {
  Serial.begin(9600);

  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(10, 30, "Tank Level Sensor");
  u8g2.sendBuffer();
  delay(2000);
}

void loop() {
  int rawValue = analogRead(WATER_LEVEL_PIN);   // 0 to 1023

  // Convert to percentage (you will need to calibrate)
  int percentage = map(rawValue, 0, 600, 0, 100);  // Adjust 600 according to your sensor
  percentage = constrain(percentage, 0, 100);

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(15, 12, "Tank Level");

  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(25, 40);
  u8g2.print(percentage);
  u8g2.print(" %");

  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(0, 60);
  u8g2.print("Raw: ");
  u8g2.print(rawValue);

  u8g2.sendBuffer();

  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print(" | Level: ");
  Serial.print(percentage);
  Serial.println("%");

  delay(800);
}