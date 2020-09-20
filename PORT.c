/*
 * PORT.c
 *
 * Created: 16.08.2020 15:48:40
 *  Author: proda
 */ 
#include "PORT.h"

void setPort(volatile uint8_t* port_ddr, uint8_t mask)
{
	*port_ddr=mask;
}
uint8_t buttonState(volatile uint8_t* port,uint8_t mask)
{
	
	if((*port&mask)==mask)
	{
		return BUTTON_POP;
	}
	else
	{
		return BUTTON_PUSH;
	}
}

void setAlarm(uint8_t *hour_set,uint8_t*min_set)
{
	uint8_t alarm=0;
	
	uint8_t set_h=0;
	char str_h[2];
	
	uint8_t set_m=0;
	char str_m[2];
	
	if(buttonState(&PINA,SHIFT_LEFT(PIN_BUTTON_SET_ALARM)))	//verificare daca butonul este apasat
	{
		alarm=1;
	}
	_delay_ms(100);
	
	while(alarm)
	{
		
		if(buttonState(&PINA,SHIFT_LEFT(PIN_BUTTON_SET_HOUR)))	//verificare daca butonul este apasat
		{
			set_h=1;
		}
		_delay_ms(100);
		
		while(set_h)
		{
				
				(*hour_set)=(*hour_set)+1;
				
				if ((*hour_set)>=24)
				{
					(*hour_set)=0;
				}
				set_h=0;
		}
		if(buttonState(&PINA,SHIFT_LEFT(PIN_BUTTON_SET_MIN)))	//verificare daca butonul este apasat
		{
			set_m=1;
		}
		_delay_ms(100);
		
		while(set_m)
		{
			
			(*min_set)=(*min_set)+1;
			
			
			if ((*min_set)>=60)
			{
				(*min_set)=0;
			}
			set_m=0;
		}
		
		
		writeStringLCD("a:",9,2);
		itoa(*hour_set,str_h,10);
		writeStringLCD(str_h,11,2);
		writeLCD(' ');
		
		itoa(*min_set,str_m,10);
		writeStringLCD(str_m,14,2);
		writeLCD(' ');
		
		if(buttonState(&PINA,SHIFT_LEFT(PIN_BUTTON_SET_ALARM)))	//verificare daca butonul este apasat
		{
			clearLCD();
			alarm=0;
		}
	}

}
