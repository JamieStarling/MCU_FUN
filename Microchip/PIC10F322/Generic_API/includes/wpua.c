
/*
 * File:  wpua.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  June 6, 2019, 10:01 PM
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


#include "wpua.h"





uint8_t enableWPUA (int8_t pin)
/*Enables Weak Pull ups on port pin - input pin number*/
{
	OPTION_REGbits.nWPUEN = 0; //Enable WeakPull up in option register
	
	switch (pin)
	{
		case 0 : //Port RA.0
             WPUAbits.WPUA0 = 1;
             return 0;
        
        case 1: //Port RA.1
            WPUAbits.WPUA1 = 1;
            return 0;
            
        case 2: //Port RA.2
            WPUAbits.WPUA2 = 1;            
            return 0;
            
        case 3 : //Port RA.3
            WPUAbits.WPUA3 = 1;
            return 0;
            
        default : //Value out of range - return 255
        return 0xFF;	
	}	
}	

uint8_t disableWPUA (int8_t pin)
/*Disables Weak Pull ups on port pin - input pin number*/
{
	OPTION_REGbits.nWPUEN = 0; //Enable WeakPull up in option register
	
	switch (pin)
	{
		case 0 : //Port RA.0
             WPUAbits.WPUA0 = 0;
             return 0;
        
        case 1: //Port RA.1
            WPUAbits.WPUA1 = 0;
            
        case 2: //Port RA.2
            WPUAbits.WPUA2 = 0;            
            return 0;
            
        case 3 : //Port RA.3
            WPUAbits.WPUA3 = 0;
            return 0;
            
        default : //Value out of range - return 255
        return 0xFF;	
	}	
}	

