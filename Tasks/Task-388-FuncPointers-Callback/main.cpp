#include "mbed.h"
#include "uop_msb.h"
#include <iostream>
#include "PressAndRelease.hpp"

using namespace uop_msb;
using namespace std;

//Globals
DigitalOut led1(LED1);
DigitalOut led2(LED2);

//Event queue for main
EventQueue mainQueue;
EventQueue workQueue;

//Flash a given LED - parameter passed by reference
void flashLed(DigitalOut& led) {
    led = !led;
}
 
void flashLed1() {
    // This is NOT on the main thread
    mainQueue.call(flashLed, led1);
    //flashLed(led1);                         
    //Dispatch printf on main thread
    workQueue.call(printf, "Button A\n");
        
}

void flashLed2() {
    //flashLed(led2);
    mainQueue.call(flashLed, led2);     
    workQueue.call(printf, "Button B\n");
     
}

int main() {  
    PressAndRelease btnA(BTN1_PIN, &flashLed1);
    PressAndRelease btnB(BTN2_PIN, &flashLed2);
    //Start main queue - dispatch
    mainQueue.dispatch_forever();
}









