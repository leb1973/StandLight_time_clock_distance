#include "Listener.h"
#include <wiringPi.h>
#include <iostream>

using namespace std;

Listener::Listener(Button *modeButton,Button *powerButton, Button *timerButton, Button *motorButton, Controller *control, 
                   ClockCheck *clock, DHT11 *dht11,UltraSonic *ultraSonic)
// event를 받음 
{
    this -> modeButton = modeButton;  // 1 -> 2 , 2 -> 3 Button
    this -> powerButton = powerButton;  // 1 -> off, 2 -> off Button
    this -> timerButton = timerButton;
    this -> motorButton = motorButton;
    this -> controller = control;
    this -> clockCheck = clock;
    this -> dht11 = dht11;
    this -> ultraSonic = ultraSonic;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if(dht11 -> dhtData.Temp < 26)
    {
        
        if (modeButton->getState() == RELEASE_ACTIVE)
        {
            controller->updateEvent("modeButton");
        }

        if (powerButton->getState() == RELEASE_ACTIVE)
        {
            controller->updateEvent("powerButton");
        }
        if (timerButton -> getState() == RELEASE_ACTIVE)
        {
            controller->updateEvent("timerButton");
        }
        
        if (clockCheck->isUpdate())  // isUpdate = 시간 함수 
        {   
            controller->updateEvent("clockUpdate");  // clock cotroller로 넘겨줌     
        }

        if (motorButton->getState() == RELEASE_ACTIVE)
        {
            controller->updateEvent("motorButton");
        }
    }
    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11 -> readData();
        if(!dhtData.error)  // true
        {
            controller -> updateTempHumid(dhtData);
        }
    }

    static unsigned int prevUltraSonicTime = 0;
    if(millis() - prevUltraSonicTime > 2000)
    {
        prevUltraSonicTime = millis();
        int distance = ultraSonic -> readDistance();
        controller -> updateDistance(distance);
    }
}