/*
 * File:  pwm.h
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

#ifndef PWM_H
#define	PWM_H

#include "10F322_deviceconfig.h"

/******************PWM Defines used with pwm.c*/
#if _XTAL_FREQ == 8000000 /** 8MHz = PWM Frequency 19.61 kHz 8bits Duty*/
#define PWM1_ENABLE  PR2 = 0x65;T2CONbits.T2CKPS = 0b00;T2CONbits.TMR2ON = 0x01;PWM1CONbits.PWM1OE = 0x01;PWM1CONbits.PWM1EN = 0x01;
#define PWM2_ENABLE  PR2 = 0x65;T2CONbits.T2CKPS = 0b00;T2CONbits.TMR2ON = 0x01;PWM2CONbits.PWM2OE = 0x01;PWM2CONbits.PWM2EN = 0x01;
#endif

#if _XTAL_FREQ == 16000000  /**16Mhz = PWM Frequency  15.7 kHz 10bits  Duty*/
#define PWM1_ENABLE PR2 = 0xFF;T2CONbits.T2CKPS = 0b00;T2CONbits.TMR2ON = 0x01;PWM1CONbits.PWM1OE = 0x01;PWM1CONbits.PWM1EN = 0x01;
#define PWM2_ENABLE PR2 = 0xFF;T2CONbits.T2CKPS = 0b00;T2CONbits.TMR2ON = 0x01;PWM2CONbits.PWM2OE = 0x01;PWM2CONbits.PWM2EN = 0x01;
#endif


const uint16_t PIN_TO_PWM_DUTY_LOW_REGISTER_PGM[] =
{
	 (uint16_t) &PWM1DCL,
	 (uint16_t) &PWM2DCL,	
};

const uint16_t PIN_TO_PWM_DUTY_HIGH_REGISTER_PGM[] =
{
	 (uint16_t) &PWM1DCH,
	 (uint16_t) &PWM2DCH,	
};


void pwmOut(uint8_t pin, uint16_t dutyCycle);
void setPWMDutyCycle (uint8_t pin, uint8_t duty);



#endif	/* PWM_H */
