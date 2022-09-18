#include "MotorService.h"

MotorService::MotorService(MotorView *motorView)
{
    this -> motorView = motorView;
    motorState = Motor_OFF;
}

MotorService::~MotorService()
{

}

void MotorService::updateState(std::string strState)
{
    switch(motorState)
    {
        case Motor_OFF:
        if(strState == "motorButton")
        {
            motorState = Motor_ON;
            motorView -> setState(motorState);
        }
        break;
        case Motor_ON:
        if(strState == "motorButton")
        {
            motorState = Motor_OFF;
            motorView -> setState(motorState);
        }
        break;
    }
}