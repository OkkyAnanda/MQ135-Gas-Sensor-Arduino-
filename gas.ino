int Sensor =A0;

#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C
lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(Sensor,INPUT);
lcd.begin(16,2);
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dataSensor=analogRead(Sensor);
  Serial.println(dataSensor);
  delay(100);
  if (dataSensor>=250){
    
    lcd.clear();
    lcd.setCursor(1,0);
lcd.print(" gas bocor   ");
lcd.setCursor(0,1);
lcd.print(" bahayaaaa  ");
  }else{
    
    lcd.clear();
  lcd.setCursor(1,0);
lcd.print(" gas aman   ");
lcd.setCursor(0,1);
lcd.print(" okeeee  ");
  
  }
}
