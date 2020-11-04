/*
 * File:   main.c
 * Author: Jamie
 *
 * Created on August 4, 2020, 5:26 PM
 */


#include "includes/10F322_deviceconfig.h"
#include "includes/gpio.h"
#include "includes/pwm.h"

void main(void) {
    
    pinMode(0,OUTPUT);
    pwmOut(0,50);
    
    while(1);
    
    
}
