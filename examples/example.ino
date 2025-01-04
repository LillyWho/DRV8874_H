#include <DRV8874.h>

#define IN1_PIN 9
#define IN2_PIN 10

DRV8874 motor(IN1_PIN, IN2_PIN);

void setup() {
    motor.begin();
    Serial.begin(9600);
    Serial.println("DRV8874 Example Initialized");
}

void loop() {
    // Coast mode
    Serial.println("Coasting");
    motor.coast();
    delay(1000);

    // Forward at 50% PWM
    Serial.println("Forward 50%");
    motor.forward(127);
    delay(1000);

    // Reverse at 75% PWM
    Serial.println("Reverse 75%");
    motor.reverse(191);
    delay(1000);

    // Brake low
    Serial.println("Brake Low");
    motor.brakeLow();
    delay(1000);

    // Brake forward at 60% PWM
    Serial.println("Brake Forward 60%");
    motor.brakeForward(153);
    delay(1000);

    // Brake reverse at 40% PWM
    Serial.println("Brake Reverse 40%");
    motor.brakeReverse(102);
    delay(1000);
}
