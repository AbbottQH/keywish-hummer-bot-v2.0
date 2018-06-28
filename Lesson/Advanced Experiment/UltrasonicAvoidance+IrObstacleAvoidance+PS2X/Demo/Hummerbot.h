#ifndef _HUMMERBOT_H_
#define _HUMMERBOT_H_
#include <stdint.h>
#include "Arduino.h"
#include "SmartCar.h"
#include "PS2X_lib.h"
#include "Servo.h"

#define HB_LEFT_POSITIVE_PIN 10
#define HB_LEFT_NEGATIVE_PIN 6
#define HB_RIGHT_POSITIVE_PIN 9
#define HB_RIGHT_NEGATIVE_PIN 5

#define HB_TRIGPIN 2
#define HB_ECHOPIN 3
#define HB_SERVOPIN 13

#define HB_INFRARED_AVOIDANCE_LEFT_PIN A3
#define HB_INFRARED_AVOIDANCE_RIGHT_PIN A4

#define HB_PS2X_CLK 11
#define HB_PS2X_CMD 7
#define HB_PS2X_ATT 8
#define HB_PS2X_DAT 4

class Hummerbot : public SmartCar {

private :
    uint8_t left_positive_pin, left_negative_pin, right_positive_pin, right_negative_pin;
    uint8_t TrigPin, EchoPin, SevoPin;   // For Ultrasonic Avoidance
    uint8_t IrPin;                       // Infrared remoter pin
    uint8_t InfraredAvoidanceLeftPin, InfraredAvoidanceRightPin;        // for Infrared Avoidance pin
    uint8_t InfraredTracingPin1, InfraredTracingPin2, InfraredTracingPin3;    // for Infrared tracing pin
    uint8_t Ps2xClkPin, Ps2xCmdPin, Ps2xAttPin, Ps2xDatPin;    // for Ps2 remoter
    

public :
    Hummerbot( uint8_t m1 = HB_LEFT_POSITIVE_PIN, uint8_t m2 = HB_LEFT_NEGATIVE_PIN, uint8_t m3 = HB_RIGHT_POSITIVE_PIN, uint8_t m4 = HB_RIGHT_NEGATIVE_PIN);
    ~Hummerbot();
    PS2X *ps2x;
    float left_read;
    float right_read;
    void GoForward(void);
    void GoBack(void);
    void TurnLeft(void);
    void TurnRight(void);
    void KeepStop(void);
    float Ultrasonic_Detection(void);
    void servo_angle(float angle);
    void SetInfraredPin(uint8_t Left_Pin = HB_INFRARED_AVOIDANCE_LEFT_PIN, uint8_t Right_Pin = HB_INFRARED_AVOIDANCE_RIGHT_PIN);
    void SetUltrasonicPin(uint8_t Trig_Pin = HB_TRIGPIN, uint8_t Echo_Pin = HB_ECHOPIN, uint8_t Sevo_Pin = HB_SERVOPIN);
    void SetInfraredAvoidancePin(uint8_t Left_Pin = HB_INFRARED_AVOIDANCE_LEFT_PIN, uint8_t Right_Pin = HB_INFRARED_AVOIDANCE_RIGHT_PIN);
    void SetPs2xPin(uint8_t clk = HB_PS2X_CLK, uint8_t cmd = HB_PS2X_CMD, uint8_t att = HB_PS2X_ATT, uint8_t dat = HB_PS2X_DAT);
    void init(void);
};

#endif  /* _HUMMERBOT_H_ */
