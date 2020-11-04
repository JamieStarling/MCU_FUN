/*
 * File:   main.c
 * Author: Jamie
 *
 * Created on August 2, 2020, 12:52 PM
 */


#include "includes/10F322_deviceconfig.h"
#include "includes/gpio.h"
#include "includes/wpua.h"

void main(void) 
{
    //Setup
    pinMode(0,OUTPUT);
    pinMode(2,INPUT);
    enableWPUA(2);
    
    
    while(1)
    {
        if(digitalRead(2))
        {
            digitalWrite(0,LOW);
        }
        else
        {
            digitalWrite(0,HIGH);
        }
        
        
    }
}
