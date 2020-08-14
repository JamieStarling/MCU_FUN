/*
 * File:  trm0.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 6, 2019, 4:46 PM
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
#include "tmr0.h"

void enableTMR0(uint8_t set_mode,uint8_t set_prescale,uint8_t edge_select,uint8_t enable_interrupt)
{
    if (!set_mode) //Set to TimerMode
    {
        OPTION_REGbits.T0CS = 0;
    }
    else  //Set to Counter Mode
    {
        TRISAbits.TRISA2 = 1; //Set PortA.2 to input
        OPTION_REGbits.T0CS = 1;
        OPTION_REGbits.T0SE = edge_select;
        
    }
    
    //set prescale
    if (set_prescale == TRM0_PRESCALE_0 )
    {
        OPTION_REGbits.PSA= 1;
    }
    else
    {
        OPTION_REGbits.PSA= 0;
        OPTION_REGbits.PS = set_prescale;
    }
    
    //set Interrupt enable. 
    tmr0_Clear_Interrupt_Flag();
    if (enable_interrupt == TRM0_INTERRUPT_ENABLE)
    {
        INTCONbits.TMR0IE = 1;
    }
    else{INTCONbits.TMR0IE = 0;}
    
}

void tmr0_Disable_Interrupt(){INTCONbits.TMR0IE = 0;}
void tmr0_Enable_Interrupt(){INTCONbits.TMR0IE = 1;}
void tmr0_Clear_Interrupt_Flag(){INTCONbits.TMR0IF = 0;}
uint8_t tmr0_Check_Interrupt_Flag(){return INTCONbits.TMR0IF;}
void tmr0_Clear_Count(){TMR0 = 0;}

