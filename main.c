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

    PORT_init_DIR(pPORT1, PORT_PIN_0, PORT_OUTPUT_DIR);
    PORT_init_DIR(pPORT1, PORT_PIN_1, PORT_INPUT_DIR);

    //When input mode is on, you use REN and OUT to set it as pulldown or pullup resistor
    pPORT1->REN |= 1 << PORT_PIN_1;
    pPORT1->OUT |= (1 << PORT_PIN_1);

    //int value = !(pPORT1->IN & 0x2);
    int value = !((pPORT1->IN >> PORT_PIN_1) & 0x00000001);

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
