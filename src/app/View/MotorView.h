#ifndef MOTORVIEW_H
#define MOTORVIEW_H

#include "Motor.h"
#include <string>
#include "MotorState.h"

#pragma once

class MotorView
{
public:
    MotorView(Motor *motor);
    virtual ~MotorView();
    void setState(int motorstate);
    void motorView();
    void motoron();
    void motoroff();


private:
    Motor *motor;
    int motorState;
    
};

#endif