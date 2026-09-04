#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

const int RAIN_PIN = 2;

void setup() {
  Serial.begin(9600);
  pinMode(RAIN_PIN, INPUT);

  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(20, 30, "Rain Sensor Test");
  u8g2.sendBuffer();
  delay(2000);
}

void loop() {
  // Try both logics
  int rainValue = digitalRead(RAIN_PIN);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(15, 12, "Rain Sensor");

  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(10, 40);

  if (rainValue == HIGH) {
    u8g2.print("RAINING");
  } else {
    u8g2.print("NO RAIN");
  }

  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(0, 60);
  u8g2.print("Raw: ");
  u8g2.print(rainValue);   // Shows 0 or 1

  u8g2.sendBuffer();

  Serial.print("Raw value: ");
  Serial.println(rainValue);

  delay(700);
}