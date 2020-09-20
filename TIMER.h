/*
 * TIMER.h
 *
 * Created: 16.08.2020 16:02:05
 *  Author: proda
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "global.h"
#include "SEG.h"

void init_timer1();

void init_timer0();
void setDC(uint8_t duty_cycle);

void sistemState();
void alarm(uint8_t hour_alarm,uint8_t min_alarm);
#endif /* TIMER_H_ */