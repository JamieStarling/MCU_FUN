#include "includes/10F322_deviceconfig.h"

void main ()
{
    
    ANSELAbits.ANSA0 = 0; //Disable Analog
    //Set Pin 0 PortA.0 as output
    TRISAbits.TRISA0 = 0;
    
    //The Forever Loop
    while (1)
    {
        
        //Set PortA.0 High (turn on LED)
        LATAbits.LATA0 = 1;       
        
        //Wait 1 second
        __delay_ms(1000);
        
        //Set PortA.0 Low  (turn off LED)
       LATAbits.LATA0 = 0;
        
        //Wait 1 second
        __delay_ms(1000);
        
        //End of Loop
        
    }
}


