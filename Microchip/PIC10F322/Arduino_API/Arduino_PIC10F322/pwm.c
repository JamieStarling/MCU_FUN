/*
 * File:   pwm.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on November 4, 2020, 8:39 PM
 * 
 * THE SOFTWARE IS PROVIDED ?AS IS?, WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */


#include "pwm.h"

void analogWrite(int8_t pin , int8_t pwmvalue){
    
    /**16Mhz = PWM Frequency  15.7 kHz 10bits  Duty*/
    if (pin == 0) {
    PR2 = 0xFF;
    T2CONbits.T2CKPS = 0b00;
    T2CONbits.TMR2ON = 0x01;
    PWM1CONbits.PWM1OE = 0x01;
    PWM1CONbits.PWM1EN = 0x01;
    }
    
    if (pin == 1) {
        PR2 = 0xFF;
        T2CONbits.T2CKPS = 0b00;
        T2CONbits.TMR2ON = 0x01;
        PWM2CONbits.PWM2OE = 0x01;
        PWM2CONbits.PWM2EN = 0x01;
    }
    
    setPWMDutyCycle (pin, pwmvalue);

}


/*
 * Sets the duty cycle of the PWM Output input is a value from 0 - 255 
*/
void setPWMDutyCycle (uint8_t pin, uint8_t duty)
//Get the dutycycle register for the selected pin...
{
    
    uint16_t dutyValue;                 
    dutyValue = duty * 2;
  
    //Vars for the registers. 
    uint8_t *regDutyCycleLow_ptr, *regDutyCycleHigh_ptr;
           
     //Get the low duty Cycle  Register
  regDutyCycleLow_ptr = (uint8_t*) PIN_TO_PWM_DUTY_LOW_REGISTER_PGM[pin];
    
   //Get the high duty Cycle Register
  regDutyCycleHigh_ptr = (uint8_t*) PIN_TO_PWM_DUTY_HIGH_REGISTER_PGM[pin];
    
    
    *regDutyCycleLow_ptr =  ((dutyValue & 0b11) << 0x06);  //Get the LSB
    *regDutyCycleHigh_ptr = (dutyValue >> 0x02);    //Get the MSB
}