#include <VirtualWire.h>
#include <RCSwitch.h>

int trigPin = 3;    //Trig - green Jumper
int echoPin = 4;   //Echo - yellow Jumper
int trigPin1 = 6;
int echoPin1 = 7;
long duration, cm, inches, duration1, cm1, inches1;
int count = 0;
RCSwitch mySwitch = RCSwitch();
 
void setup() {
  Serial.begin(9600);
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
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
  
  if(cm < 20)
    count++;
  //delay(10);
  
  mySwitch.send(inches, 24);
  //mySwitch.send(" ", 24);
  mySwitch.send(cm, 24);
  //Serial.print(inches);
  //Serial.print("in, ");
  Serial.print(cm);
  //Serial.print("cm");
  Serial.println();
  //delay(100);
  
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  
  duration1 = pulseIn(echoPin1, HIGH);
 
  // convert the time into a distance
  cm1 = (duration1/2) / 29.1;
  inches1 = (duration1/2) / 74;
  
  if(cm1 < 20)
    count--;
  
  mySwitch.send(inches1, 24);
  //mySwitch.send(" ", 24);
  mySwitch.send(cm1, 24);
  //Serial.print(inches1);
  //Serial.print("in1, ");
  Serial.print(cm1);
  //Serial.print("cm1");
  Serial.println();
  
  mySwitch.send(count, 24);
  //Serial.print("count, ");
  Serial.print(count);
  Serial.println();
  //delay(100);
 
}
