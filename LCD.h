/*
 * LED.h
 *
 * Created: 16.08.2020 15:45:52
 *  Author: proda
 */ 


#ifndef LED_H_
#define LED_H_

#include "global.h"


void initLCD();
void commandLCD(uint8_t comm);
void writeLCD(char character);
void placeCursor(uint8_t poz,uint8_t lin);
void clearLCD();
void writeStringLCD(char* str,uint8_t poz,uint8_t lin);




#endif /* LED_H_ */