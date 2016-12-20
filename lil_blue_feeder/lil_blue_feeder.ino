#include <ArduinoUnit.h>
#include <Servo.h>

Servo feederServo;
int pos = 0;
unsigned long hoursUntilNextFeeding = 24;
unsigned long millisecondsUntilNextFeeding = hoursUntilNextFeeding * 60 * 60 * 1000;
unsigned long lastTime = millis();

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(millis() > (lastTime + (10000))) {
      feederLoop();
      lastTime = millis();
  }
}


void feederLoop() {
  Serial.println("About to feed Lil' Blue...\n");
  feederServo.attach(13);

  for (pos = 0; pos <= 100; pos += 1) {
    feederServo.write(pos);           
    delay(15);                       
  }

  for (pos = 100; pos >= 0; pos -= 1) { 
    feederServo.write(pos);
    delay(15);
  }

  delay(2000);
  Serial.print("Bon Appetite!!\n");

  feederServo.detach();
}
