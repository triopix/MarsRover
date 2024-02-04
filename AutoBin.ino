// include the servo library and make new servo objects
#include <Servo.h>
Servo servo1;
Servo servo2;

// servo activation distance
int distanceVal = 30;

// define ultrasonic distance sensor pins
const int trigPin1 = 9;
const int echoPin1 = 8;
// define variables used for distance sensor
long duration1;
int distance;

//////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600); //use serial port with baud rate of 9600
  // first servo
  servo1.attach(7);
  servo1.write(0);
  delay(200);
  delay(200);
  pinMode(trigPin1, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT);   // Sets the echoPin as an Input
}

void loop() {
  distanceReady();
  functionality();
  Serial.println(distance);
}

void distanceReady() {
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads echoPin, returns the sound wave travel time in ms
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating distance
  distance = duration1 * 0.034 / 2;
}

// main code that opens/closes the trash can
void functionality() {
  if (distance <= distanceVal) {
    servo1.write(90);
    servo2.write(90);
    delay(200);
  } else if (distance > distanceVal) {
    servo1.write(0);
    servo2.write(0);
    delay(200);
  }}

void motorFunc() {
  // for controlling motor if it wants to turn left, left is low right is high
  // if it wants to turn right, left is high and right is low
}

void irFunc() {
  // detecting barcode
}

void ultrasonicFunc(){
  // check diagrams
  // use to check distances from angles
}

void servoFunc(){
  // 3 sectors - 45 degrees/90 deg/45 deg

  // servo functionaltiy to move the ultrasonic sensor
  // only moves when cntereded distance is less than 10 cm
  // stop motors then turn servo to sector 1, record the distance
  // check to sector 2, record distance
  // also check the center distance - as a side note, if we get the highest distance
  // we can remove it for efficency

  /*
  for example car goes straight, center sector <10, highest distance is left sector
  car moves left. servo moves back into center, and then we repeat
  whatever the highest distance is the direction we go.
  BUt the servo should always be in the center.
  
  
  
  */
}
