#include "Controller.h"
#include "DHT11.h"

Controller::Controller(Service *serv, ClockService *clockServ, MotorService *motorService, TempHumidService *tempHumidService)  // 어느 서비스에 분배해줄것인가 
{
    this -> service = serv;
    this -> clockService = clockServ;
    this -> tempHumidService = tempHumidService;
    this -> lightState = LIGHT_OFF;
    this -> motorService = motorService;
    clockState = 0;
    motorState = Motor_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    std::cout << strBtn << std::endl;
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if(strBtn == "timerButton")
    {
        clockState = !clockState;
    }

    if(strBtn == "clockUpdate")
    {
        if(clockState)
        {
            clockService -> updateEventTimer();  // timer
        }
        if(!clockState)
        {
            clockService -> updateEvent();  // clock
        }
    }

    if(strBtn == "motorButton")
    {
        motorService -> updateState("motorButton");
    }
}
void Controller::updateTempHumid(DHT_Data DHT_Data)
{
    tempHumidService -> updateEvent(DHT_Data);
}

void Controller::updateDistance(int distance)
{
    service -> updateDistance(distance);
}