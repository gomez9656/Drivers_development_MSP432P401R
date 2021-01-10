/*
 * msp432p401r_port_driver.h
 *
 *  Created on: 9/01/2021
 *      Author: PC
 */

//This file contains driver specific data, in this case for PORTS

#ifndef DRIVERS_INC_MSP432P401R_PORT_DRIVER_H_
#define DRIVERS_INC_MSP432P401R_PORT_DRIVER_H_

#include "msp432p401r.h"

/*This is a configuration structure for a PORT pin */

typedef struct{

    uint8_t PORT_PinNumber;
    uint8_t PORT_PinMode;
    uint8_t PORT_PinSpeed;
    uint8_t PORT_PinPuPdControl;
    uint8_t PORT_PinOPType;
    uint8_t PORT_PinAltFunMode;
}PORT_PinConfig_t;

/* This is a Handle structure for a PORT pin */

typedef struct{

    PORT_RegDef_t *pPORTx;           //Base address for PORT
    PORT_PinConfig_t PORT_PinConfig;
}PORT_Handle_t;


/* API supported by this driver */

void PORT_PeriClockControl(void); //MSP does not need this

/* Init and DeInit */
void PORT_init(PORT_Handle_t *pPORTHandle);
void PORT_DeInit(PORT_RegDef_t *pPORTx); //This functions should work to DeInit thw whole peripheral

/*Data read and write */


uint8_t PORT_ReadFromInputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber); //8 bits because the return value is 0 or 1
uint16_t PORT_ReadFromInputPort(PORT_RegDef_t *pPORTx); // 16 bits because is a port
void PORT_WriteToOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber, uint8_t Value);
void PORT_WriteToOutputPort(PORT_RegDef_t *pPORTx, uint16_t Value);
void PORT_ToggleOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber);

/*IRQ Configuration and handle */

void PORT_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void PORT_IRQHandling(uint8_t PinNumber);






#endif /* DRIVERS_INC_MSP432P401R_PORT_DRIVER_H_ */
