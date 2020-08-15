/*
 * File:   basic_astable_nco.c
 * Author: Jamie
 *
 * Created on August 15, 2020, 10:39 AM
 */


#include "includes/10F322_deviceconfig.h"
#include "includes/nco.h"
#include "includes/gpio.h"
#include "includes/osc.h"

void main(void)
{
    cpuFreqSelect(MHZ16);
    pinMode(2,OUTPUT);    
    setupNCO1(NCO_CLOCK_SOURCE_FOSC ,0xFFFF,NCO_FREQUNCY_MODE_FIXED); //500Khz Output
    
    

    while(1){}
   
}
