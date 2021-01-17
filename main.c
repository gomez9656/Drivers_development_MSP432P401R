//#include "msp.h"
#include "Drivers/Inc/msp432p401r.h"
#include "Drivers/Inc/msp432p401r_port_driver.h"
/**
 * main.c
 */
#define PORT1   0x40004C00

void main(void)
{
    PORT_RegDef_t *pPORT1 = (PORT_RegDef_t*)PORT1;

    PORT_InitDir(pPORT1, PORT_PIN_0, OUTPUT);
    PORT_InitDir(pPORT1, PORT_PIN_1, INPUT_PU);

    int value;
    unsigned int i;
    while(1){

        value = PORT_ReadFromInputPin(pPORT1, PORT_PIN_1);

        if(value){
            PORT_ToggleOutputPin(pPORT1, PORT_PIN_0);
        }
        for(i = 0; i < 20000; i++);
    }

}
