/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef DELAYS_H
#define	DELAYS_H

#include "arduino.h"


void init_trm0(void);
void timer_irq(void);
unsigned long millis();
void delay(unsigned long ms);


#endif	/* DELAYS_H */

