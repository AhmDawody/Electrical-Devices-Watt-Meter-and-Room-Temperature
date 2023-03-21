/*-------------------------------------------------------------------
 * File:        adc.h
 * Author:      Ahmed Shehata
 * Date:        March, 2023
 * Description: Header file of the ADC module .
 *---------------------------------------------*/
#ifndef ADC_H_
#define ADC_H_

// Included Header Files
// ----------------------
#include <stdint.h>
#include <stdbool.h>

void ADCInit(void);
uint32_t ADC_IN_AIN1(void);



#endif /* ADC_H_ */
