#include "DRV8874.h"

DRV8874::DRV8874(uint8_t in1Pin, uint8_t in2Pin) 
    : _in1Pin(in1Pin), _in2Pin(in2Pin) {}

void DRV8874::begin() {
    pinMode(_in1Pin, OUTPUT);
    pinMode(_in2Pin, OUTPUT);
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
    setOutputs(LOW, LOW);
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
