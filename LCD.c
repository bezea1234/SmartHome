/*
 * LED.c
 *
 * Created: 16.08.2020 15:46:05
 *  Author: proda
 */ 
#include "LCD.h"
void initLCD()
{
	for(int i=0;i<4;i++)
	{
		commandLCD(0x38);
		_delay_ms(5);
	}
	commandLCD(0x08);
	_delay_ms(5);
	commandLCD(0x01);
	_delay_ms(1);
	commandLCD(0x06);
	_delay_ms(1);
	commandLCD(0x0E);
	_delay_ms(1);
}



void commandLCD(uint8_t comm)
{
	CLEAR_PIN_PORT(PORTC,RS);
	SET_PORT_PIN(PORTC,E);
	PORTD=comm;
	_delay_ms(1);
	CLEAR_PIN_PORT(PORTC,E);
}

void writeLCD(char character)
{
	SET_PORT_PIN(PORTC,RS);
	SET_PORT_PIN(PORTC,E);
	PORTD=character;
	_delay_ms(1);
	CLEAR_PIN_PORT(PORTC,E);
}

void placeCursor(uint8_t poz,uint8_t lin)
{
	uint8_t comm;
	poz=poz-1;
	if(lin==1)
	{
		
		comm=0x80+poz;
	}
	else
	{
		comm=0xC0+poz;
	}
	commandLCD(comm);
}
void clearLCD()
{
	commandLCD(0x01);
}
void writeStringLCD(char* str,uint8_t poz,uint8_t lin)
{
	placeCursor(poz,lin);
	for(uint8_t i=0;str[i]!='\0';i++)
	{
		writeLCD(str[i]);
	}
}

