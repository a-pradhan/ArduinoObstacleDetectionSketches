/*
 * sketch to collect A2D readings from sensors for callibration 
 * 30 readings are taken at 1 second intervals and output to the Serial Monitor
 */
//const byte anPin = 0; // for left IR sensor
//const byte anPin = 3; // for right US sensor
const byte anPin = 4; // for right IR sensor
int counter1 = 0;
int counter2= 0;

void setup() {
  Serial.begin(38400);
  delay(500);

}

void loop() {
  if(counter1 < 100) { 
    int reading = analogRead(3);
    Serial.println(reading);
    counter1++;
    delay(50);
  }

}



