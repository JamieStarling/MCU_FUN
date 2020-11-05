/*
 * File:   delays.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on November 3, 2020, 3:02 PM
 * 
 * 
 * THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */


#include "delays.h"

  /*At 16Mhz - timer0 increments every 250ns 16/4 = 4Mhz
   * Unlike the AVR devices that run at the system clock speed.
   * to get the 1ms update - tmr0 needs to be prescaled to 16
   * 
   * the prescaler is set so that timer0 ticks every 16 instruction cycles, and the
   * the overflow handler is called every 256 ticks. */

//#define clockCyclesPerMicrosecond() ( _XTAL_FREQ / 1000000L )
//#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
//#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

//#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(16 * 256))

// the whole number of milliseconds per timer0 overflow
//#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)
#define MILLIS_INC 1
// the fractional number of milliseconds per timer0 overflow. we shift right
// by three to fit these numbers into a byte. (for the clock speeds we care
// about - 8 and 16 MHz - this doesn't lose precision.)
//#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
//#define FRACT_MAX (1000 >> 3)


volatile unsigned long timer0_overflow_count = 0;
volatile unsigned long timer0_millis = 0;
//static unsigned char timer0_fract = 0;

void timer_irq(void){
  
    //We are going to cheat - with the math above to figure this out on the fly, takes up a lot
    //of program space - roughly the tmr0 overflows every 1.024ms. close enough
    
    //TODO:Save Stack
    unsigned long m = timer0_millis;
	//unsigned char f = timer0_fract;    
    
    m += MILLIS_INC;
	

	//timer0_fract = f;
	timer0_millis = m;
	timer0_overflow_count++;
    
    //clear tmr0 flag
    INTCONbits.TMR0IF = 0;
    
    //TODO:Restore Stack
    
}

void init_trm0(void)
{
    //Set tmr0 to use internal clock source
    OPTION_REGbits.T0CS = 0;
    //Assign prescaler to tmr0
    OPTION_REGbits.PSA = 0;
    //Assign 16 to prescaller
    OPTION_REGbits.PS = 0b011;
    TMR0 = 0x00;
    
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
    
}

unsigned long millis()
{
	unsigned long m;
	//uint8_t oldSREG = SREG;

	// disable interrupts while we read timer0_millis or we might get an
	// inconsistent value (e.g. in the middle of a write to timer0_millis)
	//cli();
	m = timer0_millis;
	//SREG = oldSREG;

	return m;
}

void delay(unsigned long ms)
{
	uint32_t start = millis();

	while (millis() - start < ms) {
	
	}
    
   }

