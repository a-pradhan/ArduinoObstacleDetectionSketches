/* 
 *  Sketch to collect measurements from x2 IR sensors and x1 US 
 *  sensor and send data via bluetooth to Android Device
 */
#include <SoftwareSerial.h>

const int anPin = 0;
int USDistanceReading, IRReadingLeft, IRReadingRight;

// RX and TX pins for communication with HC-06 module
const byte rxPin = 3;
const byte txPin = 2;

SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  bluetooth.begin(38400);
  Serial.begin(38400);
  delay(2000);
}

void loop() {
  // obtain distance readings from sensors
  IRReadingLeft = getIRReading(4);
  USDistanceReading = analogRead(anPin); // A2D reading equivalanet to distance in cm
  IRReadingRight = getIRReading(5);
  
//  // send readings via bluetooth 
  bluetooth.print('#'); // denominates start of a set of readings
  bluetooth.print(IRReadingLeft);
  bluetooth.print(',');
  bluetooth.print(USDistanceReading);
  bluetooth.print(',');
  bluetooth.print(IRReadingRight);
  bluetooth.print('\n'); // denominates end of a set of readings

  // for debugging only - print readings to Serial Monitor
//  Serial.print('#');
//  Serial.print(IRReadingLeft);
//  Serial.print(',');
//  Serial.print(USDistanceReading);
//  Serial.print(',');
//  Serial.print(IRReadingRight);
//  Serial.print('\n');

delay(200);
}

long getIRReading(byte analogPin) {
  int reading;
  float distance;

  reading = analogRead(analogPin);
  distance = 1 / ((0.00027293 * reading)  - 0.01110356);

  return distance;
}



