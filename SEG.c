/*
 * SEG.c
 *
 * Created: 16.08.2020 16:01:52
 *  Author: proda
 */ 
#include "SEG.h"

void shiftRegister(uint8_t val)
{
	for (uint8_t i=0;i<=7;i++)
	{
		if(((val)&(SHIFT_LEFT(i)))==0)
		{
			CLEAR_PIN_PORT(PORTB,DS);
		}
		else
		{
			SET_PORT_PIN(PORTB,DS);
		}
		SET_PORT_PIN(PORTB,SH_CP);
		_delay_us(10);
		CLEAR_PIN_PORT(PORTB,SH_CP);
		_delay_us(10);
	}
	SET_PORT_PIN(PORTB,ST_CP);
	_delay_us(10);
	CLEAR_PIN_PORT(PORTB,ST_CP);
	_delay_us(10);
}