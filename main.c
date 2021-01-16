//#include "msp.h"
#include "Drivers/Inc/msp432p401r.h"
#include "Drivers/Inc/msp432p401r_port_driver.h"
/**
 * main.c
 */

#define PORT1   0x40004C00

void main(void)
{
    //PORT_RegDef_t *pPORT1 = (PORT_RegDef_t*)0x40004C00;//Pointer to PORT1 address
    PORT_RegDef_t *pPORT1 = (PORT_RegDef_t*)PORT1;

    PORT_PinConfig_t PIN_LED;
    PIN_LED.PORT_PinNumber = PORT_PIN_0;
    PIN_LED.PORT_PinMode = PORT_INPUT_DIR;

    PORT_Handle_t PORT1_Handle;
    PORT1_Handle.PORT_PinConfig = PIN_LED;
    PORT1_Handle.pPORTx = pPORT1;

    PORT_init(&PORT1_Handle);

}
