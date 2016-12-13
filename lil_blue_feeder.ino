#include <Servo.h>

Servo feederServo;
int pos = 0;
unsigned long hoursUntilNextFeeding = 20000;
unsigned long lastTime = millis();

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if(millis() > (lastTime + (hoursUntilNextFeeding))) {
      feederLoop();
      lastTime = millis();  
      
  }

  
}

void feederLoop() {
  Serial.println("About to feed Lil' Blue...\n");
  feederServo.attach(13);

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    feederServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    feederServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  delay(2000);
  Serial.print("Bon Appetite!!\n");

  feederServo.detach();
}




//void feederLoop() {
//    long timeSinceStart = millis();
//    
//    Serial.print("start");
//    Serial.print(timeSinceStart);
//    delay(10000);
//    Serial.print(timeSinceStart);
////    myservo.attach(13);
//





//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
////    myservo.detach()
//}
