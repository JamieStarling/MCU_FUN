/*
 * File:   main.c
 * Author: Jamie
 *
 * Created on August 14, 2020, 8:52 AM
 */


#include "includes/10F322_deviceconfig.h"
#include "includes/gpio.h"
#include "includes/wpua.h"

#define PulseOut_Time 1000

void main(void) {
   
    /*Setup*/
    pinMode(0,OUTPUT); //Set PORTA.0 as OUTPUT
    pinMode(2,INPUT);  //Set PORTA.2 as INPUT
    enableWPUA(2);    //Enable WeakPullUp on PORTA.2
    
    while(1)
    {
        if (!digitalRead(2))  //If Input goes low
        {
            digitalWrite(0,HIGH);   //Set PORTA.0 HIGH
            __delay_ms(PulseOut_Time); //Wait
            digitalWrite(0,LOW);    //Set PORTA.0 LOW
       
        }
    }
    
    
    return;
}
