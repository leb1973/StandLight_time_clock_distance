#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidService.h"
#include "TempHumidView.h"
#include "UltraSonic.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Button modebutton(27);
    Button powerbutton(28);
    Button timerbutton(29);
    Button moterButton(6);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    Motor motor(26);
    DHT11 dht(7);
    UltraSonic UltraSonic(5,4);    
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView temphumidView(&led1, &led2, &led3, &led4, &led5,&lcd);
    ClockView clockView(&lcd);
    MotorView motorView(&motor);
    Service service(&view);
    ClockService clockSerivce(&clockView);
    TempHumidService tempHumidService(&temphumidView);
    MotorService motorService(&motorView);
    Controller control(&service, &clockSerivce,&motorService, &tempHumidService);
    Listener listener(&modebutton,&powerbutton, &timerbutton,&moterButton, &control, &clockCheck, &dht, &UltraSonic);
    

    while (1)
    {
        listener.checkEvent();
        motorView.motorView();
        if(dht.dhtData.Temp < 26)
        {
            view.lightView();
        }
        delay(100);
    }

    return 0;
}