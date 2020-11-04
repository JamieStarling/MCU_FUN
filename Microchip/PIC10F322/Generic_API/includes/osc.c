/*
 * File:  osc.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 11, 2019, 2:15 PM
 * 
 * Copyright 2018 - 2019 Jamie Starling


THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

 */


#include <xc.h>
#include <stdint.h>
#include "osc.h"


/* Sets the processor Frequence*/
void cpuFreqSelect(uint8_t speed) {

OSCILATOR_SPEEDCONTROL_REGISTER = speed;   

}

/* Enables the Reference Clock out*/
void enableClockReferenceOut (void)
{  
    CLOCK_REFERENCE_OUT_ENABLE; 
    
}

/* Disable the Reference Clock out*/
void disableClockReferenceOut (void)
{  
    CLOCK_REFERENCE_OUT_DISABLE;
    
}

