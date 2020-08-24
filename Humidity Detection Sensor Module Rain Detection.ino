// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);  
}
void loop() {
  // read the sensor on analog A0:
	int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Flood");
    break;
 case 1:    // Sensor getting wet
    Serial.println("Rain Warning");
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.println("Not Raining");
    break;
  }
  delay(1);  // delay between reads
}
