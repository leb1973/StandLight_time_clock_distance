#ifndef MOTOR_H
#define MOTOR_H

#pragma once

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "MotorState.h"

class Motor
{
public:
    Motor(int pin);
    virtual ~Motor();
    
    void Motoron();
    void Motoroff();

private:
    int pwmPinNumber;
    bool motorState;


};

#endif