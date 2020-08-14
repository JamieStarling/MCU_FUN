/*
 * File:   timer0_example.c
 * Author: Jamie Starling
 *
 * Created on August 14, 2020, 10:02 AM
 */


#include "includes/10F322_deviceconfig.h"
#include "includes/tmr0.h"
#include "includes/gpio.h"
#include "includes/osc.h"

void main(void) {
    
    cpuFreqSelect(KHZ31);
    enableTMR0(TRM0_MODE_TIMER,TRM0_PRESCALE_16,TRM0_EDGE_LOW_HIGH,TRM0_INTERRUPT_DISABLED);
    pinMode (0,OUTPUT);
    
    while(1)
    {
        if(tmr0_Check_Interrupt_Flag())
        {
            digitalToggle(0);
            tmr0_Clear_Interrupt_Flag();
        }
    }
    
}
