//Alternating Flasher - PinA.0 and PinA.1 

#include "includes/10F322_deviceconfig.h"
#include "includes/gpio.h"

void main ()
{
  
    
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    
    //The Forever Loop
    while (1)
    {
        
        //Set PortA.0 High (turn on LED)
        digitalWrite(0,ON);   
        digitalWrite(1,OFF); 
        
        //Wait 1 second
        __delay_ms(1000);
        
        //Set PortA.0 Low  (turn off LED)
        digitalWrite(0,OFF);
        digitalWrite(1,ON);
        
        //Wait 1 second
        __delay_ms(1000);
        
        //End of Loop
        
    }
}


