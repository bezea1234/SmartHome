/*
* SmartHome.c
*
* Created: 16.08.2020 15:17:42
* Author : proda
*/

#include "global.h"
#include "PORT.h"
#include "LCD.h"
#include "TIMER.h"
#include "SEG.h"
#include "ADC.h"

extern volatile uint8_t old_state;
int main(void)
{
	setPort(&DDRC,0x0F); //setare pini pentru LCD (RS SI E) si cei pentru LEDURI ca output
	setPort(&DDRD,0xFF); //setare pini pentru LCD ca output
	
	setPort(&DDRB,0xFF);	//setare pini pentru 7 seg display ca output
	
	setPort(&DDRA,0x1E);   //setare pinul buzz,pinul pentru set alarm, pinul pentru set hour ca output
	
	SET_PORT_PIN(PORTA,PIN_BUTTON_SET_ALARM);	//activare rezistor pull-up pentru pInul pentru buton
	SET_PORT_PIN(PORTA,PIN_BUTTON_SET_HOUR);	//activare rezistor pull-up pentru pInul pentru buton
	SET_PORT_PIN(PORTA,PIN_BUTTON_SET_MIN);	//activare rezistor pull-up pentru pInul pentru buton
	
	//afisare la inceput "SMART HOME" pe LCD
	initLCD();
	writeStringLCD("SMART HOME",1,1);
	_delay_ms(1000);
	clearLCD();
	
	//afisare ceas pe 7seg display
	init_timer1();
	
	//citire temperatura
	uint16_t adc=0;
	uint16_t v_in=0;
	initADC();
	//init_timer0();	//pwm
	
	//alarma
	uint8_t hour_alarm=5;
	uint8_t min_alarm=35;
	
	
	while (1)
	{
		//STAREA
		sistemState();
		
		//TEMPERATURA
		if(old_state==1)
		{
			
			adc=readADC(0);
			v_in=(((uint32_t)adc*5*100)/1024);
			write_verifyTemperature(v_in);
			
			setAlarm(&hour_alarm,&min_alarm);
		}
		//
		if((hour_alarm<=23)&(hour_alarm>=0))
		{
			if (min_alarm<60)
			{
				alarm(hour_alarm,min_alarm);
			}	
		}
		_delay_ms(100);
	}
}

