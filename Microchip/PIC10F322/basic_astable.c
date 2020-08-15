/*
 * File:   basic_astable.c
 * Author: Jamie
 *
 * Created on August 15, 2020, 9:38 AM
 */


#include "includes/10F322_deviceconfig.h"
#include "includes/gpio.h"
#include "includes/osc.h"

#define Delay_Value 0  //Delay in instructions

void main(void) {
    
    pinMode(0,OUTPUT);
    cpuFreqSelect(MHZ16);
    
    while(1)
    {
        digitalToggle(0);
        _delay(Delay_Value);
    }
}
