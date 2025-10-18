#include "DRV8874.h"

DRV8874::DRV8874(uint8_t in1Pin, uint8_t in2Pin, uint8_t sleepPin) 
    : _in1Pin(in1Pin), _in2Pin(in2Pin), _sleepPin(sleepPin) {}

void DRV8874::begin() {
    pinMode(_in1Pin, OUTPUT);
    pinMode(_in2Pin, OUTPUT);
    pinMode(_sleepPin,OUTPUT); // I wrote "pingMode" what the slobbering feck
    coast(); // Initialize in coast mode
}

void DRV8874::coast() {
    setOutputs(LOW, LOW);
}

void DRV8874::forward(uint8_t pwm) {
    analogWrite(_in1Pin, pwm);
    digitalWrite(_in2Pin, LOW);
}

void DRV8874::reverse(uint8_t pwm) {
    digitalWrite(_in1Pin, LOW);
    analogWrite(_in2Pin, pwm);
}

void DRV8874::brakeLow() {
    setOutputs(HIGH, HIGH);
}

void DRV8874::brakeForward(uint8_t pwm) {
    analogWrite(_in1Pin, pwm);
    digitalWrite(_in2Pin, HIGH);
}

void DRV8874::brakeReverse(uint8_t pwm) {
    digitalWrite(_in1Pin, HIGH);
    analogWrite(_in2Pin, pwm);
}

void DRV8874::setOutputs(uint8_t in1, uint8_t in2) {
    digitalWrite(_in1Pin, in1);
    digitalWrite(_in2Pin, in2);
}
uint8_t DRV8874::positivePwm(int8_t Pwm_in) {
    return (Pwm_in < 0) ? -Pwm_in : Pwm_in;
}
void DRV8874::doSleep(bool doSleep) {

    digitalWrite(_sleepPin,!doSleep); // the SLEEP pin defaults to low, and the board sleeps if it is low, so if sleep == true then set the pin to FALSE
    return;
    
}