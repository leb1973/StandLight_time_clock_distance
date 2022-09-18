#include "ClockService.h"


ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    clockView = view;
}

ClockService::~ClockService()
{}

void ClockService::updateEvent()  
{   
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    clockView -> updateTime(timeDate);  // clock clockView로 넘겨줌
}

void ClockService::updateEventTimer()
{
    clockView->timerclock();  // timer clockView로 넘겨줌
}