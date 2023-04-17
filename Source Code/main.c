/*-------------------------------------------------------------------
 * File:        SpaceInvaders.c
 * Author:      Ahmed Shehata
 * Date:        March, 2023
 *
 * Description: This project is a simple and affordable way to monitor
 *              room temperature using a single microcontroller board.
 *              The system is designed to measure the real-time
 *              room temperature.
 *------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

#include "delay/delay.h"
#include "adc/adc.h"
#include "temp/temp.h"
#include "pll/pll.h"
#include "uart/uart.h"
#include "pwm/pwm.h"

#define THRESHOLD 30


void main(void){
    uint8_t sample_t;
    uint8_t* temp;
    PLLInit();
    Sys_Init();
    UARTInit();
    ADCInit();
    PWMInit();
    while(1){
        LED_OFF();
        sample_t = capture_temp();
        temp = convert_temp(sample_t);
        if(sample_t <= THRESHOLD){
            Send_String1("Room Temperature is: ");
            Send_String1(temp);
            Send_String1(" C \n");
            Sys_Wait1ms(3000);
        }
        else if(sample_t > THRESHOLD){
            Send_String1("Warning-Room Temperature is: ");
            Send_String1(temp);
            Send_String1(" C \n");
            Alert_Start();
        }
    }

}



