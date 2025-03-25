// C++ code
//
#define Trig 13 //Trig 핀
#define Echo 12 //Echo 핀
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C icd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  icd.init();
 icd.backlight();
 icd.print("LCD init");
 delay (2000);
 icd.clear();
}

void loop()
{
  long duration,distance;
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  duration = pulseIn(Echo, HIGH);
  
  distance = duration / 58.2;
    icd.setCursor(16,0);
  icd.print(duration);
  icd.print("\nDistance : ");
  icd.print(distance);
  icd.print(" Cm");
  for (int position = 0; position < 16; position++) {
    icd.scrollDisplayLeft();
    delay(150);}
  
 
}