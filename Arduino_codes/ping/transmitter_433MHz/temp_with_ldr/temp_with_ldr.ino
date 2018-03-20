#include <VirtualWire.h>
#include <RCSwitch.h>
 
RCSwitch mySwitch = RCSwitch();
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int ldr1 = A1;
int entry = 0;
int l1 = 0;
 
void setup() {
  Serial.begin(9600);
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);

}
 
void loop() {
  l1 = analogRead(ldr1);
  Serial.println("ldr op = ");
  Serial.print(l1);
 sensorValue = analogRead(sensorPin); //analog output of LM35
 
 sensorValue = sensorValue* 0.48828125; // Conversion to degrees
  Serial.println(sensorValue) ;
  mySwitch.send(sensorValue, 24); // transmitting Tempreture in Deg C
  delay(500); 
 
 
}
