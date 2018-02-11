#include <Arduino.h>
int myPins[] = {3, 5, 6, 9, 10, 11};
double myPinsTimeShipt[] = {510.0, 320.0, 900.0, 550.0, 702.0, 601.0};
int ledsCount = 5;

unsigned long timer;
unsigned long timerRealStart;
unsigned long fadeInTime = 800000;
unsigned long fadeIn = 0;

void setup()
{
  timerRealStart = millis();
  int i;
  for (i = 0; i <= ledsCount; i++) {
    pinMode(myPins[i], OUTPUT);
    digitalWrite(myPins[i], LOW);
  }
}

void loop()
{
  timer = millis() - timerRealStart;
  fadeIn = min(fadeIn + 1, fadeInTime);
  double fadeInMulty = ((double)fadeIn / (double)fadeInTime);

  int i;
  double maxBrightnest = min(128.0, (sin((float)timer / 1500.0) * 64.0) + 128.0);
  for (i = 0; i <= ledsCount; i++) {
    double brightnest = (cos((float)timer / myPinsTimeShipt[i]) * maxBrightnest) + 128.0;
    analogWrite(myPins[i], (int)(brightnest * fadeInMulty));
  }
}
