#include "msp.h"
#include "Drivers/Inc/msp432p401r.h"
#include "Drivers/Inc/msp432p401r_port_driver.h"
/**
 * main.c
 */
#define PORT1   0x40004C00

void main(void)
{
    PORT_RegDef_t *pPORT1 = (PORT_RegDef_t*)PORT1;

    PORT_InitDir(pPORT1, PORT_PIN_1, INPUT_PU);
    pPORT1->IES |= (1 << PORT_PIN_1);
    pPORT1->IFG = 0;              //Clear all PORT1 interrupt flags
    pPORT1->IE  |= (1 <<PORT_PIN_1);

    InitInterrupt(pPORT1, PORT_PIN_1, HIGH_TO_LOW);

    //Enable PORT1 interrupt. Interrupts for the PORT1 are in the NVIC INTERRUPT
    //INPUT #35, and the #35 is in the ISER #1, because each ISER handles 32 bits.
    //The #35 bit in the ISER[1] is in the #3 bit. An easy way to do this is using &
    //and left shift 1
    NVIC->ISER[1] = 1 << ((PORT1_IRQn) & 31);

    __enable_irq();             //Enable global interrupt

    for(;;);
}

void PORT1_IRQHandler(void){

    volatile uint32_t i;
    // Toggling the output on the LED
          if(P1->IFG & PORT_PIN_1)
              P1->OUT ^= PORT_PIN_0;

          // Delay for switch debounce
          for(i = 0; i < 10000; i++)

          P1->IFG &= ~PORT_PIN_1;

}


