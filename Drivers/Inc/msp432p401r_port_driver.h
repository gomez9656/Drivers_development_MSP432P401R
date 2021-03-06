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

    uint8_t PORT_PinNumber; //Posibles values from @PORT pin numbers
    uint8_t PORT_PinMode;   //Posibles values from @Macro for PORT DIR
    uint8_t PORT_PinSpeed;
    uint8_t PORT_PinPuPdControl;
    uint8_t PORT_PinOPType;
    uint8_t PORT_PinAltFunMode;
}PORT_PinConfig_t;

/*Peripheral register C definition structure
 * You can check this in the page 683 of the reference manual
 */
typedef struct{
    uint8_t     IN;         /*possibles values from @Macro for PORT input */
    uint8_t     RESERVED;
    uint8_t     OUT;        /*possibles values from @Macro for PORT output*/
    uint8_t     RESERVED1;
    uint8_t     DIR;        /*possibles values from @Macro for PORT DIRt */
    uint8_t     RESERVED2;
    uint8_t     REN;        /*possibles values from @Macro for PORT pull up or pull down registers  */
    uint8_t     RESERVED3;
    uint8_t     DS;
    uint8_t     RESERVED4;
    uint8_t     SEL0;       /*possibles values from @Macro for PORT SEL0 */
    uint8_t     RESERVED5;
    uint8_t     SEL1;       /*possibles values from @Macro for PORT SEL1 */
    uint8_t     RESERVED6;
    uint16_t    IV;
    uint8_t     RESERVED7[6];
    uint8_t     SELC;
    uint8_t     RESERVED8;
    uint8_t     IES;        /*Possibles values from @Macro for IES register*/
    uint8_t     RESERVED9;
    uint8_t     IE;         /*possibles values from @Macro for PORT enabling interrupt */
    uint8_t     RESERVED10;
    uint8_t    IFG;         /*Possibles values from @Macro for IFG register */
}PORT_RegDef_t;

/* This is a Handle structure for a PORT pin */
typedef struct{

    PORT_RegDef_t *pPORTx;           //Base address for PORT
    PORT_PinConfig_t PORT_PinConfig;
}PORT_Handle_t;



/* API supported by this driver */

void PORT_PeriClockControl(void); //MSP does not need this but it can be useful in other micros

/* Init and DeInit */
void PORT_Init(PORT_Handle_t *pPORTHandle);
void PORT_DeInit(PORT_RegDef_t *pPORTx); //This functions should work to DeInit thw whole peripheral

/*Data read and write */
void PORT_InitDir(PORT_RegDef_t *pPORTx, uint8_t PinNumber, uint8_t InputOutputMode);
int PORT_ReadFromInputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber); //8 bits because the return value is 0 or 1
uint16_t PORT_ReadFromInputPort(PORT_RegDef_t *pPORTx); // 16 bits because is a port
void PORT_WriteToOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber, uint8_t Value);
void PORT_WriteToOutputPort(PORT_RegDef_t *pPORTx, uint16_t Value);
void PORT_ToggleOutputPin(PORT_RegDef_t *pPORTx, uint8_t PinNumber);

/*IRQ Configuration and handle */
void InitInterrupt(PORT_RegDef_t *pPORTx, uint8_t PinNumber, uint8_t IEMode);
void PORT_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDi);
void PORT_IRQHandling(uint8_t PinNumber);

/* Macro for PORT input */
#define PORT_IN     0
#define PORT_OUT    1

/* Macro for PORT output */
#define PORT_OUT_LOW    0
#define PORT_OUT_HIGH   1

/* Macro for PORT DIR */
#define PORT_INPUT_DIR  0
#define PORT_OUTPUT_DIR 1

/* Macro for PORT pull up or pull down registers */
#define INPUT       0
#define INPUT_PD    1
#define INPUT_PU    2
#define OUTPUT      3

/* Macro for PORT Drive strength */
#define REGULAR_DS  0
#define HIGH_DS     1

/* Macro for PORT SEL0 */
#define SEL0_UP    1
#define SEL0_DOWN  0

/* Macro for PORT SEL1 */
#define SEL1_UP    1
#define SEL1_DOWN  0

/* Macro for PORT function select */
#define IO          0
#define PRIMARY     1
#define SECONDARY   2
#define TERTIARY    3

/* Macro for IES register*/
#define HIGH_TO_LOW     1
#define LOW_TO_HIGH     0

/* Macro for IE register */
#define INTERRUPT_ENABLED   1
#define INTERRUPT_DISABLED  0

/* Macro for IFG register */
#define INTERRUPT_PENDING       1
#define NO_INTERRUPT_PENDING    0

/* PORT pin numbers */
#define PORT_PIN_0      0
#define PORT_PIN_1      1
#define PORT_PIN_2      2
#define PORT_PIN_3      3
#define PORT_PIN_4      4
#define PORT_PIN_5      5
#define PORT_PIN_6      6
#define PORT_PIN_7      7
#define PORT_PIN_8      8



#endif /* DRIVERS_INC_MSP432P401R_PORT_DRIVER_H_ */
