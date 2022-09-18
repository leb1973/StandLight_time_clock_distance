#ifndef MOTORSERVICE_H
#define MOTORSERVICE_H

#pragma once
#include "MotorState.h"
#include "MotorView.h"

class MotorService
{
public:
    MotorService(MotorView *motorView);
    ~MotorService();
    void updateState(std::string strState);

private:

    int motorState;
    MotorView *motorView;
};

#endif