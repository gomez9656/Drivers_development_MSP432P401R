/*
 * msp432p401r_port_driver.c
 *
 *  Created on: 9/01/2021
 *      Author: PC
 */

#include "Drivers/Inc/msp432p401r_port_driver.h"



//void PORT_PeriClockControl(void);

/* PORT init
 * brief: to initialize PORT
 * param: pPORTHandle
 * return: void
 */
void PORT_init(PORT_Handle_t *pPORTHandle){

}

/* PORT_init_DIR
 * brief: to set pin as output or input
 * param: Base address of the port, pin number and value from @Macro for PORT DIR
 * return: void
 */
void PORT_init_DIR(PORT_RegDef_t *pPORTx, uint8_t PinNumber, uint8_t Value){

    if(Value == PORT_OUTPUT_DIR){

        pPORTx->DIR |= (1 << PinNumber); //Makes PinNumber as 1
    }else{

        pPORTx->DIR &= ~(1 << PinNumber); //Makes PinNumber as 0, or clears the bit position
    }
}

/* PORT DeInit
 * brief: to Deinitialize PORT
 * param: Base address of the port
 * return: void
 */
void PORT_DeInit(PORT_RegDef_t *pPORTx){

}


/* PORT_ReadFromInputPin
 * brief: to read from a pin in a PORT
 * param: Base address of the port and the pin number and pin number
 * return: uint8_t means 1 or 0
 */
uint8_t PORT_ReadFromInputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber){
    uint8_t value;
    value = (uint8_t)((pPORTx->OUT >> PinNumber) & 0x00000001);
    return value;
}

uint16_t PORT_ReadFromInputPort(PORT_RegDef_t *pPORTx){
    return 0;
}


/* PORT_WriteToOutputPin
 * brief: set output pin as 0 or 1
 * param: base address of port, pin number and value from @Macro for PORT output
 * return 0
 */
void PORT_WriteToOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber, uint8_t Value){

    if(Value == PORT_OUT_HIGH){

        pPORTx->OUT |= (1 << PinNumber); //Makes PinNumber as 1
    }else{

        pPORTx->OUT &= ~(1 << PinNumber); //Makes PinNumber as 0, or clears the bit position
    }
}

void PORT_WriteToOutputPort(PORT_RegDef_t *pPORTx, uint16_t Value){
}

/* PORT_ToggleOutputPin
 * brief: toggle an especific pin
 * param: base address of port and pin number
 * return 0
 */
void PORT_ToggleOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber){

    pPORTx->OUT ^= (1 << PinNumber); //XOR to toggle the bit position
}

void PORT_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi){

}
void PORT_IRQHandling(uint8_t PinNumber){

}





