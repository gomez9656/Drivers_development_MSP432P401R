/*
 * msp432p401r.h
 *
 *  Created on: 24/09/2020
 *      Author: PC
 */

#ifndef DRIVERS_INC_MSP432P401R_H_
#define DRIVERS_INC_MSP432P401R_H_

#include <stdint.h>


#define FLASH_BASEADDR              0x00000000U
#define SRAM_BASEADDR               0x20000000U
#define ROM                         0x02000000U
#define PERIPHERAL_BASEADDR         0x40000000U

//Base addresses for port registers
#define PORTREGISTERS_BASEADDR      (PERIPHERAL_BASEADDR + 0x4C00)
#define PORT1_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0000h)
#define PORT2_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0001h)
#define PORT3_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0020h)
#define PORT4_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0021h)
#define PORT5_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0040h)
#define PORT6_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0041h)
#define PORT7_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0060h)
#define PORT8_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0061h)
#define PORT9_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0080h)
#define PORT10_BASEADDR             (PORTREGISTERS_BASEADDR + 0x0081h)
#define PORTJ_BASEADDR              (PORTREGISTERS_BASEADDR + 0x0120h)

//Base addresses for timers
#define TIMERA0_BASEADDR            (PERIPHERAL_BASEADD + 0x0000)
#define TIMERA1_BASEADDR            (PERIPHERAL_BASEADD + 0x0400)
#define TIMERA2_BASEADDR            (PERIPHERAL_BASEADD + 0x0800)
#define TIMERA3_BASEADDR            (PERIPHERAL_BASEADD + 0x0C00)

//Base addresses for eUSCI
#define eUSCIA0_BASEADDR            (PERIPHERAL_BASEADD + 0x1000)
#define eUSCIA1_BASEADDR            (PERIPHERAL_BASEADD + 0x1400)
#define eUSCIA2_BASEADDR            (PERIPHERAL_BASEADD + 0x1800)
#define eUSCIA3_BASEADDR            (PERIPHERAL_BASEADD + 0x1C00)
#define eUSCIB0_BASEADDR            (PERIPHERAL_BASEADD + 0x2000)
#define eUSCIB1_BASEADDR            (PERIPHERAL_BASEADD + 0x2400)
#define eUSCIB2_BASEADDR            (PERIPHERAL_BASEADD + 0x2800)
#define eUSCIB3_BASEADDR            (PERIPHERAL_BASEADD + 0x2C00)

//Base addresses for I2C. eUSCI_B registers can be used as I2C
#define I2C_BASEADDR                eUSCIB0_BASEADDR

////Base addresses for SPI. eUSCI_A registers can be used as SPI or UART
#define SPI_BASEADDR                eUSCIA0_BASEADD
#define UART_BASEADDR               eUSCIA0_BASEADD

//Peripheral register definition structure
typedef struct{
    uint32_t IN;
    uint32_t OUT;
    uint32_t DIR;
    uint32_t REN;
    uint32_t SEL0;
    uint32_t SEL1;
    uint32_t IV;
    uint32_t SELC;
    uint32_t IES;
    uint32_t IE;
    uint32_t IFG;
}PORT_RegDef_t;

#define PORT1                       ((PORT_RegDef_t*)PORT1_BASEADDR)
#define PORT2                       ((PORT_RegDef_t*)PORT2_BASEADDR)
#define PORT3                       ((PORT_RegDef_t*)PORT3_BASEADDR)
#define PORT4                       ((PORT_RegDef_t*)PORT4_BASEADDR)



#endif /* DRIVERS_INC_MSP432P401R_H_ */
