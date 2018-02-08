#include <Arduino.h>

int myPins[] = {3, 5, 6, 9, 10, 11};
int ledsCount = 5;

unsigned long fadeInTime = 5000;
double fadeInMultiply = 0.0;
unsigned long timer;
double maxBrightnest = 255.0;


void setup()
{
  int i;
  for (i = 0; i <= ledsCount; i++) {
    pinMode(myPins[i], OUTPUT);
    digitalWrite(myPins[i], LOW);
  }
}

void loop()
{
  timer = millis();
  fadeInMultiply = map(
    min(timer, fadeInTime),
    0, fadeInTime,
    0, 100
  ) / 100;

  int i;
  for (i = 0; i <= ledsCount; i++) {
    pinMode(myPins[i], OUTPUT);
    analogWrite(myPins[i], fadeInMultiply * maxBrightnest);
  }
}
