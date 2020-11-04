#include "includes/10F322_deviceconfig.h"
#include "includes/gpio.h"
#include "includes/wpua.h"
#include "includes/debounce.h"


void main ()
{
  
    
    pinMode(0,OUTPUT);
    pinMode(1,OUTPUT);
    
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);    
    
    pinMode(2,INPUT);
    enableWPUA(2);
    
    //The Forever Loop
    while (1)
    {
        
       if(inputDebounce(2,LOW)) //Check the input if high turn off the LED
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
        
       //Turn off the LEDS
        digitalWrite(0,LOW);
        digitalWrite(1,LOW); 
       
    }
}


