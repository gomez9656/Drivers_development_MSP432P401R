//#include "msp.h"
#include "Drivers/Inc/msp432p401r.h"
#include "Drivers/Inc/msp432p401r_port_driver.h"
/**
 * main.c
 */
#include <stdio.h>
#define PORT1   0x40004C00

void main(void)
{
    PORT_RegDef_t *pPORT1 = (PORT_RegDef_t*)PORT1;

    PORT_InitDir(pPORT1, PORT_PIN_0, OUTPUT);
    PORT_WriteToOutputPin(pPORT1, PORT_PIN_0, PORT_OUT_HIGH);

    PORT_InitDir(pPORT1, PORT_PIN_1,INPUT_PU);

    int value2 = PORT_ReadFromInputPin(pPORT1, PORT_PIN_1);

    if(value2){
        printf("wuju");
    }


    while(1){
/*
        if(S1_PRESSED){
            PORT_WriteToOutputPin(pPORT1, PORT_PIN_0, PORT_OUT_HIGH);
        }
        else{
            PORT_WriteToOutputPin(pPORT1, PORT_PIN_0, PORT_OUT_LOW);
        }
    */
    }

}
