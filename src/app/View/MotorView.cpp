#include "MotorView.h"
#include <wiringPi.h>

MotorView::MotorView(Motor *motor)
{
    this -> motor = motor;
}

MotorView::~MotorView()
{

}

void MotorView::setState(int motorstate)
{
    motorState = motorstate;
}

void MotorView::motorView()
{

    switch (motorState)
    {
    case Motor_ON:
            motoron();

    break;

    case Motor_OFF:
            motoroff();

    break;
    }

}

void MotorView::motoron()
{
    motor ->Motoron();
}

 void MotorView::motoroff()
 {
     motor ->Motoroff();
 }