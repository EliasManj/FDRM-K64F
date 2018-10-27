/*
 *    kinetis_sysinit.c - Default init routines for Flycatcher
 *                     		Kinetis ARM systems
 *    Copyright © 2012 Freescale semiConductor Inc. All Rights Reserved.
 */
 
#include "kinetis_sysinit.h"
#include "derivative.h"

/**
 **===========================================================================
 **  External declarations
 **===========================================================================
 */
#if __cplusplus
extern "C" {
#endif
extern uint32_t __vector_table[];
extern unsigned long _estack;
extern void __thumb_startup(void);
#if __cplusplus
}
#endif

/**
 **===========================================================================
 **  Default interrupt handler
 **===========================================================================
 */
void Default_Handler()
{
	__asm("bkpt");
}

/**
 **===========================================================================
 **  Reset handler
 **===========================================================================
 */
void __init_hardware()
{
	SCB_VTOR = (uint32_t)__vector_table; /* Set the interrupt vector table position */
	/*
		Disable the Watchdog because it may reset the core before entering main().
		There are 2 unlock words which shall be provided in sequence before
		accessing the control register.
	*/
	WDOG_UNLOCK = KINETIS_WDOG_UNLOCK_SEQ_1;
	WDOG_UNLOCK = KINETIS_WDOG_UNLOCK_SEQ_2;
	WDOG_STCTRLH = KINETIS_WDOG_DISABLED_CTRL;
}

/* Weak definitions of handlers point to Default_Handler if not implemented */
void NMI_Handler() __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler() __attribute__ ((weak, alias("Default_Handler")));
void Mem_Manage_Fault_Handler() __attribute__ ((weak, alias("Default_Handler")));
void Bus_Fault_Handler() __attribute__ ((weak, alias("Default_Handler")));
void Usage_Fault_Handler() __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler() __attribute__ ((weak, alias("Default_Handler")));
void DebugMonitor_Handler() __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler() __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler() __attribute__ ((weak, alias("Default_Handler")));

void DMA0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA2_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA3_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA4_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA5_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA6_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA7_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA8_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA9_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA10_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA11_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA12_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA13_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA14_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA15_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DMA_Error_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void MCM_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void FTFL_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void Read_Collision_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void LVD_LVW_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void LLW_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void Watchdog_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void RNG_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void I2C0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void I2C1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void SPI0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void I2S0_Tx_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void I2S0_Rx_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART0_LON_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART0_Status_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART0_ERR_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART1_Status_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART1_ERR_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART2_Status_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART2_ERR_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART3_Status_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART3_ERR_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void ADC0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CMP0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CMP1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void FTM0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void FTM1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void FTM2_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CMT_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void RTC_Seconds_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PIT0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PIT1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PIT2_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PIT3_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PDB_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void USB_OTG_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void USB_Charger_Detect_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void Tamper_Drylce_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DAC0_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void MCG_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void LPTimer_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PORTA_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PORTB_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PORTC_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PORTD_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void PORTE_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void SWI_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART4_Status_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void UART4_ERR_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CMP2_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void FTM3_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void DAC1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void ADC1_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void I2C2_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Message_buffer_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Bus_Off_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Err_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Tx_WarningIRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Rx_Warning_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Wake_Up_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void SDHC_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void ENET_MAC_Timer_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void ENET_MAC_Transmit_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void ENET_MAC_Receive_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));
void ENET_MAC_Error_IRQHandler() __attribute__ ((weak, alias("Default_Handler")));

/* The Interrupt Vector Table */
void (* const InterruptVector[])() __attribute__ ((section(".vectortable"))) = {
    /* Processor exceptions */
    (void(*)(void)) &_estack,
    __thumb_startup,
    NMI_Handler,
    HardFault_Handler,
    Mem_Manage_Fault_Handler,
    Bus_Fault_Handler,
    Usage_Fault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMonitor_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    /* Interrupts */
    DMA0_IRQHandler, /* DMA Channel 0 Transfer Complete */
    DMA1_IRQHandler, /* DMA Channel 1 Transfer Complete */
    DMA2_IRQHandler, /* DMA Channel 2 Transfer Complete */
    DMA3_IRQHandler, /* DMA Channel 3 Transfer Complete */
	DMA4_IRQHandler, /* DMA Channel 4 Transfer Complete */
    DMA5_IRQHandler, /* DMA Channel 5 Transfer Complete */
    DMA6_IRQHandler, /* DMA Channel 6 Transfer Complete */
    DMA7_IRQHandler, /* DMA Channel 7 Transfer Complete */
	DMA8_IRQHandler, /* DMA Channel 8 Transfer Complete */
    DMA9_IRQHandler, /* DMA Channel 9 Transfer Complete */
    DMA10_IRQHandler, /* DMA Channel 10 Transfer Complete */
    DMA11_IRQHandler, /* DMA Channel 11 Transfer Complete */
	DMA12_IRQHandler, /* DMA Channel 12 Transfer Complete */
    DMA13_IRQHandler, /* DMA Channel 13 Transfer Complete */
    DMA14_IRQHandler, /* DMA Channel 14 Transfer Complete */
    DMA15_IRQHandler, /* DMA Channel 15 Transfer Complete */
	DMA_Error_IRQHandler, /* DMA Error */
    MCM_IRQHandler, /* Normal Interrupt */
    FTFL_IRQHandler, /* FTFL Interrupt */
	Read_Collision_IRQHandler,
	LVD_LVW_IRQHandler, /* Low Voltage Detect, Low Voltage Warning */
	LLW_IRQHandler, /* Low Leakage Wake-up */
	Watchdog_IRQHandler,
	RNG_IRQHandler,
	I2C0_IRQHandler, /* I2C0 interrupt */
    I2C1_IRQHandler, /* I2C1 interrupt */
    SPI0_IRQHandler, /* SPI0 Interrupt */
    SPI1_IRQHandler, /* SPI1 Interrupt */
	I2S0_Tx_IRQHandler, /* Transmit I2S0 interrupt */
    I2S0_Rx_IRQHandler, /* Receive I2S0 interrupt */
    UART0_LON_IRQHandler, /* UART0 LON interrupt */
	UART0_Status_IRQHandler, /* UART0 Status interrupt */
	UART0_ERR_IRQHandler, /* UART0 Error interrupt */
	UART1_Status_IRQHandler, /* UART1 Status interrupt */
	UART1_ERR_IRQHandler, /* UART1 Error interrupt */
	UART2_Status_IRQHandler, /* UART2 Status interrupt */
	UART2_ERR_IRQHandler, /* UART2 Error interrupt */
	UART3_Status_IRQHandler, /* UART3 Status interrupt */
	UART3_ERR_IRQHandler, /* UART3 Error interrupt */
	ADC0_IRQHandler, /* ADC0 interrupt */
    CMP0_IRQHandler, /* CMP0 interrupt */
	CMP1_IRQHandler, /* CMP1 interrupt */
    FTM0_IRQHandler, /* FTM0 fault, overflow and channels interrupt */
    FTM1_IRQHandler, /* FTM1 fault, overflow and channels interrupt */
    FTM2_IRQHandler, /* FTM2 fault, overflow and channels interrupt */
	CMT_IRQHandler,
    RTC_Alarm_IRQHandler, /* RTC Alarm interrupt */
    RTC_Seconds_IRQHandler, /* RTC Seconds interrupt */
    PIT0_IRQHandler, /* PIT timer all channels interrupt */
	PIT1_IRQHandler, /* PIT timer all channels interrupt */
	PIT2_IRQHandler, /* PIT timer all channels interrupt */
	PIT3_IRQHandler, /* PIT timer all channels interrupt */
	PDB_IRQHandler,
	USB_OTG_IRQHandler,
	USB_Charger_Detect_IRQHandler,
	Tamper_Drylce_IRQHandler,
    DAC0_IRQHandler, /* DAC0 interrupt */
	MCG_IRQHandler, /* MCG Interrupt */
    LPTimer_IRQHandler, /* LPTimer interrupt */
	PORTA_IRQHandler, /* Port A interrupt */
	PORTB_IRQHandler, /* Port B interrupt */
	PORTC_IRQHandler, /* Port C interrupt */
    PORTD_IRQHandler, /* Port D interrupt */
	PORTE_IRQHandler, /* Port E interrupt */
	SWI_IRQHandler,
	SPI2_IRQHandler,
	UART4_Status_IRQHandler,
	UART4_ERR_IRQHandler,
	0,
	0,
	CMP2_IRQHandler,
	FTM3_IRQHandler,
	DAC1_IRQHandler,
	ADC1_IRQHandler,
	I2C2_IRQHandler,
	CAN0_Message_buffer_IRQHandler,
	CAN0_Bus_Off_IRQHandler,
	CAN0_Err_IRQHandler,
	CAN0_Tx_WarningIRQHandler,
	CAN0_Rx_Warning_IRQHandler,
	CAN0_Wake_Up_IRQHandler,
	SDHC_IRQHandler,
	ENET_MAC_Timer_IRQHandler,
	ENET_MAC_Transmit_IRQHandler,
	ENET_MAC_Receive_IRQHandler,
	ENET_MAC_Error_IRQHandler
};