/*
 * msp432p401r_eUSCI_driver.h
 *
 *  Created on: 16/01/2021
 *      Author: PC
 */

#ifndef DRIVERS_INC_MSP432P401R_EUSCI_DRIVER_H_
#define DRIVERS_INC_MSP432P401R_EUSCI_DRIVER_H_

#include "msp432p401r.h"

typedef struct{

    uint8_t     CTL1;
    uint8_t     CTL0;
    uint8_t     CTLW1;
    uint32_t    BR0;
    uint8_t     BR1;
    uint8_t     MCTLW;
    uint16_t    STATW;
    uint16_t    RXBUF;
    uint16_t    TXBUF;
    uint16_t    ABCTL;
    uint16_t    IRCTL;
    uint8_t     IRRCTL;
    uint32_t    RESERVED;
    uint16_t    RESERVED2; //Couldn't use a big number with uint
    uint16_t    IE;
    uint16_t    IFG;
    uint16_t    IV;
}eUSCI_A_RedgDef_t; //eUSCI_A = UART Mode

typedef struct{
    uint8_t     CTL1;
    uint8_t     CLT0;
    uint32_t    RESERVED;
    uint8_t     BR0;
    uint8_t     BR1;
    uint16_t    RESERVED2;
    uint16_t    STATW;
    uint16_t    RXBUF;
    uint16_t    TXBUF;
    uint32_t    RESERVED3;
    uint8_t     RESERVED4;
    uint32_t    RESERVED5;
    uint16_t    RESERVED6;
    uint16_t    IE;
    uint16_t    IFG;
    uint16_t    IV;
}eUSCI_B_RegDef_t;


#endif /* DRIVERS_INC_MSP432P401R_EUSCI_DRIVER_H_ */
