#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards

const int pwPin = 5;
const int delayTime = 200;
long pulse, inches, cm;
int pos = 0;
int left = 0;
int right = 180;
int interval = 5;

void setup() 
{ 
  //This opens up a serial connection to shoot the results back to the PC console
  Serial.begin(9600);
  //Assigns servo to pin 9
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  //Range finder input pin
  pinMode(pwPin, INPUT);
  
} 
 
void loop() 
{ 
  while (Serial.available() > 0) {
    left = Serial.parseInt();
    right = Serial.parseInt(); 
    interval = Serial.parseInt();
  }
  //Clockwise scan
  for(pos = left; pos <= right; pos += interval) 
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(delayTime);                       // waits for the servo to reach the position
    pulse = pulseIn(pwPin, HIGH);
    Serial.print(pos);
    Serial.print(",");
    Serial.print(pulse);
    Serial.println();
  }
  //Counter-clockwise scan
  for(pos = right; pos >= left; pos -= interval) 
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(delayTime);                       // waits for the servo to reach the position
    pulse = pulseIn(pwPin, HIGH);
    Serial.print(pos);
    Serial.print(",");
    Serial.print(pulse);
    Serial.println();
  }

}

