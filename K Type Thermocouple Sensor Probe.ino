#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <max6675.h>

int SO = 7;
int CS = 6;
int CLK = 5;

LiquidCrystal lcd (8,9,10,11,12,13);
MAX6675 temp(CLK,CS,SO);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  delay(500);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cel.:");
  lcd.print(temp.readCelsius());
  lcd.print("C");
  Serial.print("Cel.:");
  Serial.println(temp.readCelsius());
  lcd.setCursor(0,1);
  lcd.print("Far.:");
  lcd.print((temp.readCelsius()*9/5)+32);
  lcd.print("F");
  Serial.print("Far.:");
  Serial.println((temp.readCelsius()*9/5)+32);
  delay(1000); 
}

