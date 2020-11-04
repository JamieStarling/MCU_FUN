/*
 * File:   sysclock.c
 * Author: Jamie
 *
 * Created on November 2, 2020, 6:07 PM
 */


#include "arduino.h"

/* Sets the processor Frequence*/
void setSystemFSOC(uint8_t speed) {

OSCILATOR_SPEEDCONTROL_REGISTER = speed;   

}
