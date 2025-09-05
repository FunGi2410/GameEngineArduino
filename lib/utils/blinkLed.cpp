#include "blinkLed.h"

void blinkLed_init(void){
    pinMode(LED_2, 1);
}

void blinkLed_ctrl(void){
    Serial.println("HELLo");
    digitalWrite(LED_2, 0);
    delay(500);

    digitalWrite(LED_2, 1);
    delay(500);
}