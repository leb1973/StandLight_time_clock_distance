#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"
#include "Motor.h"
#include "MotorService.h"

class Listener
{
private :
    Button *powerButton;
    Button *modeButton;
    Button *timerButton;
    Button *motorButton;
    ClockCheck *clockCheck;
    Controller *controller;
    DHT11 *dht11;
    UltraSonic *ultraSonic;

public:
    Listener(Button *modeButton, Button *powerButton,Button *timerButton, Button *motorButton, Controller *control, ClockCheck *clock, 
             DHT11 *dht11,UltraSonic *ultraSonic);
    ~Listener();
    void checkEvent();
    
};

#endif /* __LISTENER_H__ */
