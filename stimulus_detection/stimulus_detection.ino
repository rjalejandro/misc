/* 

 Light Signal Timer

 detects changes in light intensity, and measures the ellapsed time between changes.
 Initially adapted to detect when the screen changes from anything to black, and to measure
 the time black pixels were on the screen. Now, it's adapted to detect when something gray 
 was on the screen vs when an orange was on the screen.

 last changed: 05.2021 by: ricardo.

*/

int sensorPin       = A7;     // LDR on A0 
int sensorValue     = 0;      // Value from LDR
int thresholdValue  = 360;    // Value determining when the screen is black
bool pixelDetection = false;  // When black pixels are detected
float startTime     = 0.0;    // Time black pixels appear on the screen
float endTime       = 0.0;    // Time black pixels stop appearing on the screen
float totalTime     = 0.0;    // Total time black pixels were on the screen
bool justPrint      = false;


void setup() {
  Serial.begin(9600);      // Initialize serial port
}

void loop() {
  // read the sensor value:
  sensorValue = analogRead(sensorPin);

  if (justPrint==true) {
    Serial.println(sensorValue); 
  }
  else {
//   if it sees gray, send a 1:
    if ((sensorValue >= 620)&&(sensorValue <= 665)){
        Serial.println("---Right detected---");
        startTime = millis();
        while((analogRead(sensorPin) >= 620) && (analogRead(sensorPin) <= 665)){
          endTime = millis();
        }
        totalTime = endTime - startTime;
        Serial.print("Ellapsed time: ");
        Serial.println(totalTime);
    }
    if ((sensorValue >= 730)&&(sensorValue <= 750)){
        Serial.println("---Orange detected---");
        startTime = millis();
        while((analogRead(sensorPin) >= 730) && (analogRead(sensorPin) <= 760)){
          endTime = millis();
        }
        totalTime = endTime - startTime;
        Serial.print("Ellapsed time: ");
        Serial.println(totalTime);
    }
  }
  delay(40);
}
