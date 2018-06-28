#include "Hummerbot.h"
#include "debug.h"

Hummerbot::Hummerbot( uint8_t m1 = HB_LEFT_POSITIVE_PIN, uint8_t m2 = HB_LEFT_NEGATIVE_PIN, uint8_t m3 = HB_RIGHT_POSITIVE_PIN, uint8_t m4 = HB_RIGHT_NEGATIVE_PIN):SmartCar("hummer-bot", E_HUMMER_BOT, 0x01, E_BLUETOOTH_CONTROL)
{
    this->left_negative_pin = m1;
    this->left_positive_pin = m2;
    this->right_negative_pin = m3;
    this->right_positive_pin = m4;
}

Hummerbot::~Hummerbot()
{
    delete mInfraredTracing;
}

void Hummerbot::init(void)
{
    pinMode(left_positive_pin, OUTPUT);
    digitalWrite(left_negative_pin, LOW); // When not sending PWM, we want it low
    pinMode(right_positive_pin, OUTPUT);
    digitalWrite(right_positive_pin, LOW); // When not sending PWM, we want it low
    pinMode(left_negative_pin, OUTPUT);
    digitalWrite(left_negative_pin, LOW);  // When not sending PWM, we want it low
    pinMode(right_negative_pin, OUTPUT);
    digitalWrite(right_negative_pin, LOW); // When not sending PWM, we want it low
}

void Hummerbot::GoForward(void)
{
    int value = (Speed/10)*25;	 //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
    DEBUG_LOG(DEBUG_LEVEL_INFO, "GoForward %d \n",value);
    analogWrite(left_positive_pin,value);
    analogWrite(left_negative_pin,0);
    analogWrite(right_positive_pin,value);
    analogWrite(right_negative_pin,0);
}

void Hummerbot::GoBack(void)
{
    int value = (Speed/10)*25;   //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
    DEBUG_LOG(DEBUG_LEVEL_INFO, "GoBack %d \n",value);
    analogWrite(left_negative_pin,value);
    analogWrite(left_positive_pin,0);
    analogWrite(right_negative_pin,value);
    analogWrite(right_positive_pin,0);
}

void Hummerbot::KeepStop(void)
{
    DEBUG_LOG(DEBUG_LEVEL_INFO, "KeepStop \n");
    analogWrite(left_positive_pin,0);
    analogWrite(left_negative_pin,0);
    analogWrite(right_positive_pin,0);
    analogWrite(right_negative_pin,0);
}

void Hummerbot::TurnLeft()
{   
    int value = (Speed/10)*25;   //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
    DEBUG_LOG(DEBUG_LEVEL_INFO, "TurnLeft =%d \n",value);
    analogWrite(left_positive_pin, 0);
    analogWrite(left_negative_pin, value); //the hbot_speed value of motorA is val
    analogWrite(right_negative_pin, 0);
    analogWrite(right_positive_pin, value); //the hbot_speed value of motorB is val
}

void Hummerbot::TurnRight()
{
    int value = (Speed/10)*25;   //app contol hbot_speed is 0 ~ 100 ,pwm is 0~255
    DEBUG_LOG(DEBUG_LEVEL_INFO, "TurnRight%d \n",value);
    analogWrite(left_positive_pin, value);
    analogWrite(left_negative_pin, 0); //the hbot_speed value of motorA is val
    analogWrite(right_negative_pin, value);
    analogWrite(right_positive_pin, 0); //the hbot_speed value of motorB is val
}

void Hummerbot::SetInfraredTracingPin(uint8_t Pin1 = HB_INFRARED_TRACING_PIN1, uint8_t Pin2 = HB_INFRARED_TRACING_PIN2, uint8_t Pin3 = HB_INFRARED_TRACING_PIN3)
{
    static bool InfraredTracingInit = false;
    if (!InfraredTracingInit) {
        InfraredTracingPin1 = Pin1;
        InfraredTracingPin2 = Pin2;
        InfraredTracingPin3 = Pin3;
        mInfraredTracing = new InfraredTracing(InfraredTracingPin1, InfraredTracingPin2, InfraredTracingPin3);
        //mInfraredTracing->begin();
        InfraredTracingInit = true;
    }
}
