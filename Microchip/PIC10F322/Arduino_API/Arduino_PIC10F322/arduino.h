/* 
 * File:   arduino.h
 * Author: Jamie Starling - JamieStarling.com 
 * Comments:
 * Revision history: 
 * 
 * THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

 
#ifndef Arduino_h
#define Arduino_h

#include <xc.h> // include processor files
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


//System configuration 
#include "10F322_deviceconfig.h"


//System Hardware
#include "gpio.h"
#include "delays.h"
#include "pwm.h"



/*Standard Defines*/
#define HIGH 0x01
#define LOW 0x00
#define ON  0x01
#define OFF 0x00
#define TRUE 0x01
#define FALSE 0x00


#define INPUT 0x00
#define OUTPUT 0x01
#define INPUT_PULLUP 0x2


#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

typedef bool boolean;
typedef uint8_t byte;
typedef unsigned int word;


//System initialization Function - main.c
void system_init(void);


//Used to set the clock speed - sysclock.c
//Part of the default system initialization
#define OSCILATOR_SPEEDCONTROL_REGISTER OSCCONbits.IRCF
#define MHZ16  0b00000111
#define _XTAL_FREQ 16000000  
void setSystemFSOC(uint8_t speed);


//default functions for the user program 
void setup(void);
void loop(void);






#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* Arduino_h */

