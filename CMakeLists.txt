cmake_minimum_required(VERSION 3.0.0)

project(StandLight)
add_executable(${PROJECT_NAME}
    ./src/main.cpp
    ./src/app/Service/Service.cpp
    ./src/app/Service/ClockService.cpp
    ./src/app/Service/TempHumidService.cpp
    ./src/app/Service/MotorService.cpp
    ./src/app/Listener/Listener.cpp
    ./src/app/Controller/Controller.cpp
    ./src/app/View/View.cpp
    ./src/app/View/ClockView.cpp
    ./src/app/View/TempHumidView.cpp
    ./src/app/View/MotorView.cpp
    ./src/hw/Button/Button.cpp
    ./src/hw/Led/Led.cpp
    ./src/hw/LCD/LCD.cpp
    ./src/hw/I2C/I2C.cpp
    ./src/hw/DHT11/DHT11.cpp
    ./src/hw/ClockCheck/ClockCheck.cpp
    ./src/hw/UltraSonic/UltraSonic.cpp
    ./src/hw/Motor/Motor.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./src/app/Service
    ./src/app/Service/TempHumidService
    ./src/app/Listener
    ./src/app/Controller
    ./src/app/View
    ./src/app/View/TempHumidView
    ./src/hw/Button
    ./src/hw/Led
    ./src/hw/LCD
    ./src/hw/I2C
    ./src/hw/DHT11
    ./src/hw/ClockCheck
    ./src/hw/UltraSonic
    ./src/hw/Motor
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
    -lpthread
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)