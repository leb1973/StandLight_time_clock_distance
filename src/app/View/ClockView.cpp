#include "ClockView.h"
#include <wiringPi.h>

ClockView::ClockView(LCD *lcd)
{
    this->lcd = lcd;
    //timeDate = 0;
}

ClockView::~ClockView()
{
}

void ClockView::updateTime(struct tm *timeData)
{
    char buff[30];
    sprintf(buff, "%02d:%02d:%02d",
            timeData->tm_hour,
            timeData->tm_min,
            timeData->tm_sec);
    lcd->WriteStringXY(1, 0, buff);  // 시계 LCD 출력 
}

void ClockView::timerclock()
{
    static int clock_count = 0;
    static int hour = 0, min = 0, sec = 0;
    char buff[30];

    if(millis() - clock_count > 1000)
    {
        clock_count = millis();
        sec++;
        if(sec == 60)
        {
            sec = 0;
            min++;
        }
        if(min == 60)
        {
            min = 0;
            hour++;
        }
        if(hour == 24) 
        {
            hour = 0;
        }

        sprintf(buff, "%02d:%02d:%02d", hour, min, sec);
        lcd->WriteStringXY(1, 0, buff);  // Counter LCD 출력 
    }
}
