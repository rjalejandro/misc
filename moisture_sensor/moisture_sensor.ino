/* 

 Soil Moisture Sensor

 reads the moisture value from a Velleman VMA303 moisture sensor,
 it converts it to a porcentage value,
 and turns ON an OK LED if the moisture value is >= 50%,
 or it turns ON a LOW moisture LED if moisture is below 50%

 last changed: 12.2021 by: ricardo.

*/

// define pins and variables:
#define SensorPin A7
float sensorValue = 0; 
int moisture_value = 0;
const int LOW_MOISTURE_LED = 3;
const int OK_MOISTURE_LED = 4;

void setup() { 
  Serial.begin(9600);
  pinMode(LOW_MOISTURE_LED, OUTPUT);
  pinMode(OK_MOISTURE_LED, OUTPUT);
  Serial.println("SOIL MOISTURE SENSOR");
  Serial.println("-----------------------------");
} 

void loop() { 
  for (int i = 0; i <= 100; i++) 
  {
    sensorValue = sensorValue + analogRead(SensorPin);
    delay(1);
  } 
  sensorValue = sensorValue/100.0;
  moisture_value = sensorValue*100/1024;
  Serial.print("Moisture: ");
  Serial.print(sensorValue);
  Serial.print(" - ");
  Serial.print(moisture_value);
  Serial.println("%");

  if (moisture_value>=50){
     digitalWrite(OK_MOISTURE_LED, HIGH);
     digitalWrite(LOW_MOISTURE_LED, LOW);
  }
  else if (moisture_value<50){
     digitalWrite(LOW_MOISTURE_LED, HIGH);
     digitalWrite(OK_MOISTURE_LED, LOW);
  }
  delay(5000);
} 
