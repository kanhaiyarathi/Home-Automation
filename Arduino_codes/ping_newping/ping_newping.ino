#include <NewPing.h>
#include <RCSwitch.h>
#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define TRIGGER_PIN1 6
#define ECHO_PIN1 7
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
RCSwitch mySwitch = RCSwitch();
int count = 0;
void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  mySwitch.enableTransmit(10);
}

void loop() {
  delay(100);
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  if(uS / US_ROUNDTRIP_CM < 10 && uS / US_ROUNDTRIP_CM > 0)
    count--;
  unsigned int uS1 = sonar1.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS1 / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  if(uS1 / US_ROUNDTRIP_CM < 10 && uS1 / US_ROUNDTRIP_CM > 0)
    count++;
  Serial.println("cm");
  Serial.print("count =");
  Serial.println(count);
  mySwitch.send(count, 24);
}
