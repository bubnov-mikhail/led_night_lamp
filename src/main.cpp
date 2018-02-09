#include <Arduino.h>
int myPins[] = {3, 5, 6, 9, 10, 11};
double myPinsTimeShipt[] = {510.0, 320.0, 900.0, 550.0, 702.0, 601.0};
int ledsCount = 5;

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
  int i;
  for (i = 0; i <= ledsCount; i++) {
    double brightnest = cos((float)timer / myPinsTimeShipt[i]) * 128 + 128;
    analogWrite(myPins[i], (int)brightnest);
  }
}
