// Depends on: https://github.com/rambros3d/ESP32_PWM_Fusion

#include "DRV8874.h"

#include <Servo.h>
Servo myservo = Servo();
DRV8874::DRV8874(uint8_t in1Pin, uint8_t in2Pin) : _in1Pin(in1Pin), _in2Pin(in2Pin) {}
// https://www.pololu.com/product/4035
void DRV8874::begin() {
    pinMode(_in1Pin, OUTPUT);
    pinMode(_in2Pin, OUTPUT);
    coast(); // Initialize in coast mode
}

void DRV8874::coast() {
	if(myservo.attached(_in1Pin)) {
		myservo.detach(_in1Pin);
	}
	if(myservo.attached(_in2Pin)) {
		myservo.detach(_in2Pin);
	}
    setOutputs(LOW, LOW);
}

void DRV8874::forward(uint8_t pwm) {
	//reset all the pin mappings so we're free to write in forward mode
	if(myservo.attached(_in1Pin)) {
		myservo.detach(_in1Pin);
	}
	if(myservo.attached(_in2Pin)) {
		myservo.detach(_in2Pin);
	}
	myservo.attach(_in1Pin);
    myservo.writePwm(_in1Pin,pwm,10000,12);
    digitalWrite(_in2Pin, LOW);
}

void DRV8874::reverse(uint8_t pwm) {
	//reset all the pin mappings so we're free to write in forward mode
	if(myservo.attached(_in1Pin)) {
		myservo.detach(_in1Pin);
	}
	if(myservo.attached(_in2Pin)) {
		myservo.detach(_in2Pin);
	}
    myservo.attach(_in2Pin);
    myservo.writePwm(_in2Pin,pwm,10000,12);
    digitalWrite(_in1Pin, LOW);
}

void DRV8874::brakeLow() {
    setOutputs(HIGH, HIGH);
}

void DRV8874::brakeForward(uint8_t pwm) {
	if(myservo.attached(_in1Pin)) {
		myservo.detach(_in1Pin);
	}
	if(myservo.attached(_in2Pin)) {
		myservo.detach(_in2Pin);
	}
    myservo.attachInvert(_in1Pin);
    myservo.writePwm(_in1Pin,255 - pwm,10000,12);
    digitalWrite(_in2Pin, HIGH);
}

void DRV8874::brakeReverse(uint8_t pwm) {
	if(myservo.attached(_in1Pin)) {
		myservo.detach(_in1Pin);
	}
	if(myservo.attached(_in2Pin)) {
		myservo.detach(_in2Pin);
	}
    myservo.attachInvert(_in2Pin);
    myservo.writePwm(_in2Pin,255 - pwm,10000,12);
    digitalWrite(_in1Pin, HIGH);
}

void DRV8874::setOutputs(uint8_t in1, uint8_t in2) {
    digitalWrite(_in1Pin, in1);
    digitalWrite(_in2Pin, in2);
}
