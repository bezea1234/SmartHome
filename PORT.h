/*
 * PORT.h
 *
 * Created: 16.08.2020 15:48:28
 *  Author: proda
 */ 


#ifndef PORT_H_
#define PORT_H_

#include "global.h"
#include "LCD.h"

void setPort(volatile uint8_t* port_ddr, uint8_t mask);
uint8_t buttonState(volatile uint8_t* port,uint8_t mask);
void setAlarm(uint8_t *hour_set,uint8_t*min_set);

#endif /* PORT_H_ */