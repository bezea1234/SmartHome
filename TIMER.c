/*
 * TIMER.c
 *
 * Created: 16.08.2020 16:02:17
 *  Author: proda
 */ 
#include "TIMER.h"
#include "PORT.h"
#include "LCD.h"
#include "ADC.h"

volatile uint8_t cifre[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
volatile uint8_t val=1;
volatile uint8_t min=20;
volatile uint8_t hour=5;
volatile uint8_t contor=0;

volatile uint8_t old_state;
void init_timer1()
{
	TCCR1B|=(SHIFT_LEFT(WGM12))|(SHIFT_LEFT(CS12));//MODUL CTC +prescaler 256
	OCR1A=625;
	TIMSK |= (1 << OCIE1A);
	sei(); // activãm primirea întreruperilor
	
}

ISR(TIMER1_COMPA_vect)
{
	PORTB|=SHIFT_LEFT(DIG1)|SHIFT_LEFT(DIG2)|SHIFT_LEFT(DIG3)|SHIFT_LEFT(DIG4);
	
	switch(val)
	{
		case 1:
		CLEAR_PIN_PORT(PORTB,DIG1);
		shiftRegister(cifre[min%10]);
		break;
		case 2:
		CLEAR_PIN_PORT(PORTB,DIG2);
		shiftRegister(cifre[min/10]);
		break;
		case 3:
		CLEAR_PIN_PORT(PORTB,DIG3);
		shiftRegister((cifre[hour%10]&(0x7F))); //afisare cu punct
		break;
		case 4:
		CLEAR_PIN_PORT(PORTB,DIG4);
		shiftRegister(cifre[hour/10]);
		break;
	}
	
	val++;
	contor++;
	if(val>4)
	{
		val=1;
	}
	if(contor>=100)
	{
		contor=0;
		min++;
	}
	
	if(min>=60)
	{
		hour++;
		min=0;
	}
	
	if(hour>=24)
	{
		
		hour=0;
	}
	
}

//timer 0 pentru PWM
void init_timer0()
{
	TCCR0|=(SHIFT_LEFT(WGM01))|(SHIFT_LEFT(WGM00))|(SHIFT_LEFT(COM01))|(SHIFT_LEFT(CS00))|(SHIFT_LEFT(CS01));//MODUL FASTPWM+non-inverting +prescaler 1024
}
void setDC(uint8_t duty_cycle)
{
	OCR0=(duty_cycle*256)/100;
}


void sistemState()
{
	if((hour<22)&&(hour>=6))
	{
		SET_PORT_PIN(PORTC,PIN_LED_RED);
		CLEAR_PIN_PORT(PORTC,PIN_LED_GREEN); //aprindere led verde
		writeStringLCD("DESCHIS",1,2);
		old_state=1; //starea actuala deschisa
		
	}
	else
	{
		CLEAR_PIN_PORT(PORTC,PIN_LED_RED);//aprindere led rosu
		SET_PORT_PIN(PORTC,PIN_LED_GREEN);
		writeStringLCD("INCHIS ",1,2);
		old_state=0;  //starea actuala inchis
	}
}

void alarm(uint8_t hour_alarm,uint8_t min_alarm)
{
	if ((hour==hour_alarm)&&(min==min_alarm))
	{
		writeStringLCD("  ALARMA!  ",1,1);
		_delay_ms(5000);
		clearLCD();
	}
}

