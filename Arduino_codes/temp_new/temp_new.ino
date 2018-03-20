#include <RCSwitch.h>
const int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
RCSwitch mySwitch = RCSwitch();
void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
  // declare the ledPin as an OUTPUT:
 // pinMode(ledPin, OUTPUT);  
}

void loop() {
  // read the value from the sensor:
  //sensorValue = analogRead(sensorPin); 
  sensorValue = analogRead(sensorPin);
  sensorValue = sensorValue*0.17528125;
 Serial.println(sensorValue) ;
 //sensorValue = sensorValue* 0.17528125;
 //sensorValue = (1.8*sensorValue*100.0)/1024;
  Serial.print("CELSIUS: ");
  Serial.print(sensorValue);
  Serial.println("*C "); 
  mySwitch.send(sensorValue, 24);
  delay(200);
 
  // turn the ledPin on
  //digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  //delay(sensorValue);          
  // turn the ledPin off:        
  //digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  //delay(sensorValue);                  
}
