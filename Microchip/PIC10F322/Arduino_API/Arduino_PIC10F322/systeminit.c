/*
 * File:   systeminit.c
 * Author: Jamie
 *
 * Created on November 2, 2020, 8:17 PM
 */


#include "arduino.h"

void system_init(void){
    //Sets System to 16Mhz
    setSystemFSOC(MHZ16);
    
    #ifdef DELAYS_H
    //Initilizes the timer system only if included
    init_trm0();
    #endif

}
