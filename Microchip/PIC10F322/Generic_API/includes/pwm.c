/*
 * File:  pwm.c
 * Author: Jamie Starling - JamieStarling.com 
 *
 * Created on:  September 11, 2019, 3:13 PM
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

#include "pwm.h"

/*Enables a PIN for PWM output*/
void pwmOut(uint8_t pin, uint16_t dutyCycle)
{
    if (pin == 0) {PWM1_ENABLE}
    if (pin == 1) {PWM2_ENABLE}
    
    setPWMDutyCycle (pin, dutyCycle);
    
}




/*
 * Sets the duty cycle of the PWM Output input is a value from 0 - 100 percent
*/
void setPWMDutyCycle (uint8_t pin, uint8_t duty)
//Get the dutycycle register for the selected pin...
{
    
    //Compute the Duty Cycle Based on PR2
    //Dutyvalue = (desired% / 100) * 4(PR2 Value + 1)
    uint16_t dutyValue;            
    dutyValue = duty * (4*(PR2+1)) / 100;
    
  //Vars for the registers. 
    uint8_t *regDutyCycleLow_ptr, *regDutyCycleHigh_ptr;
           
     //Get the low duty Cycle  Register
  regDutyCycleLow_ptr = (uint8_t*) PIN_TO_PWM_DUTY_LOW_REGISTER_PGM[pin];
    
   //Get the high duty Cycle Register
  regDutyCycleHigh_ptr = (uint8_t*) PIN_TO_PWM_DUTY_HIGH_REGISTER_PGM[pin];
    
    
    *regDutyCycleLow_ptr =  ((dutyValue & 0b11) << 0x06);  //Get the LSB
    *regDutyCycleHigh_ptr = (dutyValue >> 0x02);    //Get the MSB
}