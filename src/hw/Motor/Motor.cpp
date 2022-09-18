#include "Motor.h"


Motor::Motor(int pin)
{
    pwmPinNumber = pin;
    wiringPiSetup();
    softPwmCreate(pwmPinNumber, 0, 100);  //pin, range_init_start, range_init_end
}

Motor::~Motor()
{

}

void Motor::Motoron()
{
    // softPwmWrite(pwmPin, 10);   //pin, duty cycle
    // softPwmWrite(pwmPin, 30);
    // softPwmWrite(pwmPin, 90);
    softPwmWrite(pwmPinNumber, 99);
}
void Motor::Motoroff()
{
     softPwmWrite(pwmPinNumber,0);
}