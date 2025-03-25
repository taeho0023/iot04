#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C icd(0x27, 16, 2);

void setup()
{
 icd.init();
 icd.backlight();
 icd.print("LCD init");
 delay (2000);
 icd.clear();
}

void loop()
{
  icd.setCursor(16,0);
  icd.print("Hello, world!");
  for (int position = 0; position < 16; position++) {
    icd.scrollDisplayLeft();
    delay(150);}
}