/*
 * File:  osc.h
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 11, 2019, 2:14 PM
 * 

THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

 */

#ifndef OSC_H
#define	OSC_H

#include <xc.h>
#include <stdint.h>
#include "10F322_deviceconfig.h"


/******************CPU OSCILATOR used with osc.c*/

#define MHZ16  0b00000111
#define MHZ8   0b00000110
#define MHZ4   0b00000101
#define MHZ2   0b00000100
#define MHZ1   0b00000011
#define KHZ500 0b00000010
#define KHZ250 0b00000001
#define KHZ31  0b00000000

#define OSCILATOR_SPEEDCONTROL_REGISTER OSCCONbits.IRCF
#define CLOCK_REFERENCE_OUT_ENABLE CLKRCONbits.CLKROE = 1
#define CLOCK_REFERENCE_OUT_DISABLE CLKRCONbits.CLKROE = 0



void cpuFreqSelect(uint8_t speed);
void enableClockReferenceOut (void);
void disableClockReferenceOut (void);
 

#endif	/* OSC_H */
