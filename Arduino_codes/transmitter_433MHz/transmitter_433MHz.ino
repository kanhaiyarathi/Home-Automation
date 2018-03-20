#include <VirtualWire.h>
#include <RCSwitch.h>
int trigPin = 2;    //Trig - green Jumper
int echoPin = 4;    //Echo - yellow Jumper
long duration, cm, inches;
RCSwitch mySwitch = RCSwitch();
 
void setup() {
  Serial.begin(9600);
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  // Optional set pulse length.
  // mySwitch.setPulseLength(320);
 
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);
 
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
 
}
 
void loop() {
  /* Same switch as above, but using decimal code */
  /*mySwitch.send(5393, 24);
  delay(1000);  
  mySwitch.send(5396, 24);
  delay(1000);*/  
 
  /* Same switch as above, but using binary code */
  /*mySwitch.send("000000000001010100010001");
  delay(1000);  
  mySwitch.send("000000000001010100010100");
  delay(1000);*/
 
  //delay(2000);
  //mySwitch.send(4212181, 24);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  mySwitch.send(inches, 24);
  //mySwitch.send(" ", 24);
  mySwitch.send(cm, 24);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
 
}
