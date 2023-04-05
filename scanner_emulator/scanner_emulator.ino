/* Scanner trigger and button box emulator
 *  the circuit sends a trigger every TR seconds, and continuouslly 
 *  reads (3) button inputs. A "manual" trigger can be sent (button 4)
 *  
 *  last changed: 29.08.2021 by: ricardo.
*/

// define pins for buttons:
const int scannerButtonPin = 2;
const int leftButtonPin = 3;
const int middleButtonPin = 4;
const int rightButtonPin = 5;

// define variables:
int scannerButtonValue = 0;   // what is being sent by the scanner (trigger)
int leftButtonValue = 0;      // what is being sent by the left button
int middleButtonValue = 0;    // what is being sent by the middle button
int rightButtonValue = 0;     // what is being sent by the right button
int TR = 1720;                
unsigned long startTR = 0;

void setup() {
  pinMode(scannerButtonPin, INPUT);
  pinMode(leftButtonPin, INPUT);
  pinMode(middleButtonPin, INPUT);
  pinMode(rightButtonPin, INPUT);
  Serial.begin(9600);               // initialize serial port
  startTR = millis();               // get the current running time
}

void loop() {
  // send a scanner trigger every TR:
  if (millis() - startTR >= TR){
    Serial.write(53);
    startTR = millis();
  }

  // read all the pins:
  scannerButtonValue = digitalRead(scannerButtonPin);
  leftButtonValue = digitalRead(leftButtonPin);
  middleButtonValue = digitalRead(middleButtonPin);
  rightButtonValue = digitalRead(rightButtonPin);

  // in case you want to manually send a trigger:
  if (scannerButtonValue!=0){
    Serial.write(53);
    delay(300);
  }
  // check if any button has been pressed and rely its information:
  if (leftButtonValue!=0){
    Serial.write(49);
    delay(300);
  }
  if (middleButtonValue!=0){
    Serial.write(50);
    delay(300);
  }
  if (rightButtonValue!=0){
    Serial.write(51);
    delay(300);
  }
}
