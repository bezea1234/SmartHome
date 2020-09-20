 
#include "ADC.h"
#include "TIMER.h"
#include "LCD.h"
void initADC()
{
	ADMUX|=SHIFT_LEFT(REFS0);	//selectare referinta si modul de incadrare a celor 2 registri ADCL si ADCH si selectare canal ADC0
	ADCSRA|=SHIFT_LEFT(ADEN)|SHIFT_LEFT(ADPS0)|SHIFT_LEFT(ADPS1)|SHIFT_LEFT(ADPS2);	//pornire adc+ PRESCALER=128
}
uint16_t readADC(uint8_t channel)
{
	ADCSRA|=SHIFT_LEFT(ADSC);	//start conversie
	while(ADCSRA &(SHIFT_LEFT(ADSC)));	//asteptare finalizare conversie
	return ADC;
	
}
void write_verifyTemperature(uint16_t a)
{
	char str[16];
	if((a<300)&(a>=0))
	{
		a=a/10;
	}
	if((a>=300)&(a<400))
	{
		a=30;
	}
	if((a>=400)&(a<=489))
	{
		a=31;
	}
	if(a>489)
	{
		a=32;
	}
	
	if (a>=27)
	{
		SET_PORT_PIN(PORTA,BUZ);
		setDC(50);
	}
	else
	{
		CLEAR_PIN_PORT(PORTA,BUZ);
		setDC(0);
	}
	itoa(a,str,10);
	writeStringLCD("T=",1,1);
	writeStringLCD(str,3,1);
	writeStringLCD(".0 oC",5,1);		
}

