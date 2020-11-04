/*
 * File:  gpio.h
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 6, 2019, 4:45 PM
 * 
 *

THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

 */

#ifndef GPIO_H
#define	GPIO_H

#include <xc.h>
#include <stdint.h>
#include "10F322_deviceconfig.h"

#define MAXIOPINS 4

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3  //10F32x PIN 3 is always input only

/******************GPIO Defines - Used with gpio.c*/


const uint8_t PIN_BIT_MASK_PGM[] = 
{
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,     
};

const uint16_t PIN_TO_DIRECTION_REGISTER_PGM[] =
{
	 (uint16_t) &TRISA,
	 (uint16_t) &TRISA,
	 (uint16_t) &TRISA,
     (uint16_t) &TRISA,
};

const uint16_t PIN_TO_ANALOG_REGISTER_PGM[] =
{
	 (uint16_t) &ANSELA,
	 (uint16_t) &ANSELA,
	 (uint16_t) &ANSELA,
     (uint16_t) &ANSELA,
};


const uint16_t PIN_TO_PORT_WRITE_REGISTER_PGM[] =
{
	 (uint16_t) &LATA,
	 (uint16_t) &LATA,
	 (uint16_t) &LATA,
     (uint16_t) &LATA,
};

const uint16_t PIN_TO_PORT_READ_REGISTER_PGM[] =
{
	 (uint16_t) &PORTA,
	 (uint16_t) &PORTA,
	 (uint16_t) &PORTA,
     (uint16_t) &PORTA,
};


void pinMode(uint8_t pin, uint8_t direction);
void digitalWrite (uint8_t pin, uint8_t value);
uint8_t digitalRead (uint8_t pin);
void digitalToggle (uint8_t pin);
#endif	/* GPIO_H */

