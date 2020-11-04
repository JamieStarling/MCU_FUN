/*
 * File:  gpio.c
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
#include "gpio.h"




/* Sets a PIN to either digital input or output
 *Required PIN number
 *Direction
 */
void pinMode(uint8_t pin, uint8_t direction)
{
    //var that holds the registers of the Direction, Analog and PIN BitMask.
   uint8_t *regDirection_ptr, *regAnalog_ptr, pinBitMask;
   
   //Get the BitMask of the PIN    
   pinBitMask = PIN_BIT_MASK_PGM[pin];
   
    //Get the register that controls the direction for the Pin
   regDirection_ptr = (uint8_t*) PIN_TO_DIRECTION_REGISTER_PGM[pin];    
   
   //Get the register that controls the analog for the Pin
   regAnalog_ptr = (uint8_t*) PIN_TO_ANALOG_REGISTER_PGM[pin];
   
          
    //If PIN is to be set as Input - Set the associated Register Bit
   if (direction == INPUT)
    {
       //Set the bit in the Direction Register with OR
        *regDirection_ptr |= pinBitMask;    
        
       //Invert the Pin Mask to clear the Analog Register with AND         
        *regAnalog_ptr &= ~pinBitMask;      
        
    }
    //If PIN is to be set as OUTPUT - Clear the associated Register Bit
    else
    {
       //Invert the Mask - Clear the bit in the Direction Register and Analog Register
       *regDirection_ptr &= ~pinBitMask; 
       *regAnalog_ptr &= ~pinBitMask;         
    }  
}




/*
 * Turns off or on a specific pin.  
 * Usage digitalWrite( pin to control , HIGH / LOW)   
 */
void digitalWrite (uint8_t pin, uint8_t value)
{ 
    
    //var that holds the registers of the Port Write and PIN BitMask.
   uint8_t *regPortWrite_ptr, pinBitMask;
   
   //Get the BitMask of the PIN    
   pinBitMask = PIN_BIT_MASK_PGM[pin];
   
   //Get the Port Write Register
   regPortWrite_ptr = (uint8_t*) PIN_TO_PORT_WRITE_REGISTER_PGM[pin]; 
   
    
    //If PIN is to be set HIGH
    if (value)
    {
        //Set the bit in the Latch Register with OR
        *regPortWrite_ptr |= pinBitMask;        
    }
    //Everything else - LOW
    else
    {      
       //Invert the Mask - Clear the bit in the Latch Register with AND
       *regPortWrite_ptr &= ~pinBitMask;         
    }  
}


/*Reads the current input value of a pin - returns value*/
uint8_t digitalRead (uint8_t pin)
{
     //var that holds the registers of the Port Read and PIN BitMask.
   uint8_t *regPortRead_ptr, pinBitMask;
   
   //Get the BitMask of the PIN    
   pinBitMask = PIN_BIT_MASK_PGM[pin];
   
   //Get the Port Write Register
   regPortRead_ptr = (uint8_t*) PIN_TO_PORT_READ_REGISTER_PGM[pin];
    
   if ((*regPortRead_ptr & pinBitMask) >> 0x00)
   {
       return 0x01;
   }
   else
   {
       return 0;
   }   
}

/*Toggles a given GPIO pin*/
void digitalToggle (uint8_t pin)
{
    //var that holds the registers of the Port Write and PIN BitMask.
   uint8_t *regPortWrite_ptr, pinBitMask;
    
   //Get the BitMask of the PIN    
   pinBitMask = PIN_BIT_MASK_PGM[pin]; 
   
   //Get the Port Write Register
   regPortWrite_ptr = (uint8_t*) PIN_TO_PORT_WRITE_REGISTER_PGM[pin];
   
   //Flip the Bit with XOR
    *regPortWrite_ptr ^= pinBitMask;   
    
}