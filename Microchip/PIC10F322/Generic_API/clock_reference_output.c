#include "includes/10F322_deviceconfig.h"
#include "includes/osc.h"

void main(void) 
{
    cpuFreqSelect(MHZ16);
    enableClockReferenceOut ();
    
    while(1);
}
