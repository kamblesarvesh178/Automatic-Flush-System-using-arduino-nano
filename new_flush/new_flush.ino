#include<Servo.h> //servo library
Servo servo;
int trigPin = 2;
int echoPin = 3;
int servoPin = 9;
int pos = 0; 

// defines variables
long duration; // variable for the duration of sound wave travel
int distance = 100; // variable for the distance measurement


void setup()  {
  servo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(0);   //close cap power on
  delay(1000);
  servo.detach();
  Serial.begin(9600);
  distance = 100;
  Serial.print("Done Setup");
}
void dis(){
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  //return distance;
}

void loop() {
  if (distance > 20){
  dis();
  }
  if (distance <= 20){
     // servo.attach(servoPin);

  servo.write(150);
  delay(3000);    //wait 5 seconds\
  servo.write(0);
  delay(1000);
  //servo.detach();
  dis();
    
  }
    
/*if (distance < 15)  {
  //if hand on the distance 10...15 cm
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
  Serial.println("Done 1234");

}
