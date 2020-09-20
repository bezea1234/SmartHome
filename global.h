/*
 * global.h
 *
 * Created: 16.08.2020 15:18:08
 *  Author: proda
 */ 


#ifndef GLOBAL_H_
#define GLOBAL_H_

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#define SET_PORT_PIN(port,pin) port|=1<<pin
#define CLEAR_PIN_PORT(port,pin) port&=~(1<<pin)
#define SHIFT_LEFT(val) 1<<val

//LCD
#define RS 0 //PINUL 0 de pe PORTUL C
#define E 1	//PINUL 1 de pe PORTUL C

//LED
//PINI de pe PORTULC
#define PIN_LED_RED 2	
#define PIN_LED_GREEN 3

//BUTTON
#define BUTTON_PUSH 1
#define BUTTON_POP 0
#define PIN_BUTTON_SET_ALARM 1
#define PIN_BUTTON_SET_HOUR 2
#define PIN_BUTTON_SET_MIN 4
//7seg
//PINI de pe PORTUL B
#define DS 0
#define SH_CP 1
#define ST_CP 2
#define DIG1 4
#define DIG2 5
#define DIG3 6
#define DIG4 7

//timer1
//biti din TCCR1B
#define WGM12 3 
#define CS12 2	
#define  CS11 1
#define  CS10 0
//biti din TIMSK
#define OCIE1A 4

//buzzer
#define BUZ 3 //PIN 3 de pe PORTUL A

//ADC
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define ADEN 7
#define ADSC 6
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

//timer0
#define WGM01 3
#define WGM00 6
//#define COM00 4
#define COM01 5
#define CS01 1
#define CS00 0
#define CS02 2
#endif /* GLOBAL_H_ */