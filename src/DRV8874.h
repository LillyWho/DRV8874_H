#pragma once
#ifndef DRV8874_H
#define DRV8874_H

#include <Arduino.h>

class DRV8874 {

public:
	DRV8874(uint8_t in1Pin, uint8_t in2Pin);

	void begin();
	void coast();
	void forward(uint8_t pwm);
	void reverse(uint8_t pwm);
	void brakeLow();
	void brakeForward(uint8_t pwm);
	void brakeReverse(uint8_t pwm);

uint8_t positivePwm(int8_t Pwm_in);
private:

	uint8_t _in1Pin;
	uint8_t _in2Pin;
	uint8_t _sleepPin;
	
	void setOutputs(uint8_t in1, uint8_t in2);
};

#endif
