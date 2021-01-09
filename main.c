//#include "msp.h"
#include "Drivers/Inc/msp432p401r.h"

/**
 * main.c
 */
void main(void)
{
    PORT_RegDef_t *pPORT1 = (PORT_RegDef_t*)0x40004C00;//Pointer to PORT1 address

        pPORT1->OUT |= (0 << 0);
        pPORT1->DIR |= (1 << 0);
        pPORT1->OUT |= (1 << 0);
}
