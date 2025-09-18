#include "blinkLed.h"

void blinkLedCtrl(unsigned short ledPin, unsigned short msDelayTime){
    
    /* Init LED pin is OUTPUT */
    pinMode(ledPin, 1);

    /* Blink LED by freq = 2*msDelayTime */
    digitalWrite(ledPin, LOW);
    delay(msDelayTime);

    digitalWrite(ledPin, HIGH);
    delay(msDelayTime);
}