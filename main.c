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

        pPORT1->OUT |= (0 << 0);
        pPORT1->DIR |= (1 << 0);
        pPORT1->OUT |= (1 << 0);

        pPORT1->OUT = PORT_OUT_LOW << PORT_PIN_0;
        pPORT1->DIR = PORT_OUTPUT_DIR << PORT_PIN_0;
        pPORT1->OUT = PORT_OUT_HIGH << PORT_PIN_0;
}
