#include <Wire.h>
 
// SI7021 I2C address is 0x40(64)
#define si7021Addr 0x40
 
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(si7021Addr);
  Wire.endTransmission();
  delay(300);
}
 
void loop()
{
  unsigned int data[2];
 
  Wire.beginTransmission(si7021Addr);
  //Send humidity measurement command
  Wire.write(0xF5);
  Wire.endTransmission();
  delay(500);
 
  // Request 2 bytes of data
  Wire.requestFrom(si7021Addr, 2);
  // Read 2 bytes of data to get humidity
  if(Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
 
  // Convert the data
  float humidity  = ((data[0] * 256.0) + data[1]);
  humidity = ((125 * humidity) / 65536.0) - 6;
 
  Wire.beginTransmission(si7021Addr);
  // Send temperature measurement command
  Wire.write(0xF3);
  Wire.endTransmission();
  delay(500);
 
  // Request 2 bytes of data
  Wire.requestFrom(si7021Addr, 2);
 
  // Read 2 bytes of data for temperature
  if(Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
 
  // Convert the data
  float temp  = ((data[0] * 256.0) + data[1]);
  float celsTemp = ((175.72 * temp) / 65536.0) - 46.85;
  float fahrTemp = celsTemp * 1.8 + 32;
 
  // Output data to serial monitor
  Serial.print("Humidity : ");
  Serial.print(humidity);
  Serial.println(" % RH");
  Serial.print("Celsius : ");
  Serial.print(celsTemp);
  Serial.println(" C");
  Serial.print("Fahrenheit : ");
  Serial.print(fahrTemp);
  Serial.println(" F");
  delay(1000);
}