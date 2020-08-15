/*
 * File:  nco.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  08/15/2020
 * 
 * Copyright 2018 - 2020 Jamie Starling


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
#include "nco.h"



void setupNCO1(uint8_t ClockSource,uint16_t IncrementValue,uint8_t FreqMode)
{
    NCO1CLKbits.N1CKS = ClockSource;
    NCO1INC  = IncrementValue;
    NCO1CONbits.N1PFM = FreqMode;
    
    enableNCO1();
    enableNCO1Output();
    
}

void enableNCO1(void)
/*
 Enables NCO1  
 */
{
    NCO1CONbits.N1EN = 1;   
}

void disableNCO1(void)
/*
 Disables NCO1  
 */
{
    NCO1CONbits.N1EN = 0;
}

void enableNCO1Output(void)
/* Enables Output on RA.2 */
{
     NCO1CONbits.N1OE = 1;
}

void disableNCO1Output(void)
/* Disables Output on RA.2 */
{
     NCO1CONbits.N1OE = 0;
}

void setNC01IncrementValue (uint16_t IncrementValue)
/* Sets the NCO Incremental Value using a 16bit number
 * 
 */
{   
    NCO1INC  = IncrementValue;
}