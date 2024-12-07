

#include <Servo.h>
int servoPin = 3;
Servo Servo1;
const int trigPin = 13;
const int echoPin = 12;


const int greenLED = 10;

long duration;
double distance;

double maxDistanceInches = 180; // this is how far we want our sensor to read, ignore everything farther than 12 inches.

void setup() {
  Servo1.attach(servoPin);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(greenLED, OUTPUT);
  digitalWrite(greenLED, LOW);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance in cm
  distance = duration * 0.034 / 2;
  


  //Light up light depending on distance!
  if ((distance > 180) && (distance < 225)) {
     
     digitalWrite(greenLED, HIGH);
     Servo1.write(155);
     delay(100);
     Servo1.write(90);
      delay(3000); 
  }
  else
     digitalWrite(greenLED, LOW);
     
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
