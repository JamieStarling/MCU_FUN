/*
 * File:   interrupt.c
 * Author: Jamie
 *
 * Created on November 4, 2020, 2:22 PM
 */


#include "arduino.h"

void __interrupt () my_isr_routine (void) {
    
#ifdef DELAYS_H
timer_irq();
#endif

}