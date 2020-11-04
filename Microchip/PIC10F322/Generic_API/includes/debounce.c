/*
 * File:  debounce.c
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


#include "debounce.h"

//Debounces input - returns True if input matches, trigger, and sample of input 
uint8_t inputDebounce(uint8_t pin, uint8_t trigger)
{
    
     //Get Current Pin Value
    uint8_t currentPinValue = digitalRead(pin);
    
    
    if (currentPinValue == trigger)
    {
        //Wait    
        __delay_ms(delay_time);
        
        if (digitalRead(pin) == currentPinValue) {return TRUE;}
        else {return FALSE;}
    }
    return FALSE;
    
}