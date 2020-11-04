/*
 * File:   main.c
 * Author: Jamie
 *
 * Created on November 3, 2020, 7:20 AM
 */


#include "arduino.h"

int main(void) {
    system_init();
    setup();
    
    while(1){loop();}
}