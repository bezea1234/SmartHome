
#ifndef ADC_H_
#define ADC_H_

#include "global.h"
void initADC();
uint16_t readADC(uint8_t channel);
void write_verifyTemperature(uint16_t a);

#endif /* ADC_H_ */