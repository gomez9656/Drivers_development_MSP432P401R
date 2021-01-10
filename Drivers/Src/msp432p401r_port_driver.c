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

/* PORT DeInit
 * brief: to Deinitialize PORT
 * param: Base address of the port
 * return: void
 */

void PORT_DeInit(PORT_RegDef_t *pPORTx){

}


/* PORT_ReadFromInputPin
 * brief: to read from a pin in a PORT
 * param: Base address of the port and the pin number
 * return: uint8_t means 1 or 0
 */
uint8_t PORT_ReadFromInputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber){

}

uint16_t PORT_ReadFromInputPort(PORT_RegDef_t *pPORTx){

}
void PORT_WriteToOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber, uint8_t Value){

}
void PORT_WriteToOutputPort(PORT_RegDef_t *pPORTx, uint16_t Value){

}
void PORT_ToggleOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber){

}
void PORT_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi){

}
void PORT_IRQHandling(uint8_t PinNumber){

}





