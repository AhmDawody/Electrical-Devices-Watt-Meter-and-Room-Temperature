/*-------------------------------------------------------------------
 * File:        temp.c
 * Author:      Ahmed Shehata
 * Date:        March, 2023
 * Description: Source file of the temperature calculations functions.
 *------------------------------------------------------------------*/

// Included Header Files
// ----------------------
#include <stdint.h>
#include "temp/temp.h"
#include "adc/adc.h"

// Global Variables
// -----------------
uint8_t temp[3];

// Capture sample from ADC
// -----------------------
uint8_t capture(void){uint8_t x;
    x = (ADC_IN()*330)/4096;
    return x;
}

// Convert sample to temperature
// -----------------------------
uint8_t* convert(uint8_t x){
    x = capture();
    if(x > 9){
        temp[0] = x/10 + '0';
        temp[1] = x%10 + '0';
        temp[2] = '\0';
    }
    else if(x < 10){
        temp[0] = x + '0';
        temp[1] = '\0';
    }
    return temp;
}
