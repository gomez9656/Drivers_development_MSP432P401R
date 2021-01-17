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

}
