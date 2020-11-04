/*
 * File:   cascaded_timer.c
 * Author: Jamie
 *
 * Created on August 16, 2020, 8:56 PM
 */


#include "includes/10F322_deviceconfig.h"
#include "includes/gpio.h"
#include "includes/wpua.h"

#define ON_Value 1000  //On Time in MS

void main(void) {
    
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    pinMode(2,INPUT);
    enableWPUA(2);
    
    digitalWrite(0,OFF);
    digitalWrite(1,OFF);

    
    
    while(1)
    {
        if (!digitalRead(2))
        {
            digitalWrite(0,ON);
            __delay_ms(ON_Value);
            digitalWrite(0,OFF);
            digitalWrite(1,ON);
            __delay_ms(ON_Value);
            digitalWrite(1,OFF);
        }
    }
}