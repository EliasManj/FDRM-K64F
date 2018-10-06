/* ###################################################################
 **     Filename    : main.c
 **     Project     : PE_FreeRTOS
 **     Processor   : MK64FN1M0VLQ12
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2018-10-05, 09:25, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "FRTOS1.h"
#include "MCUC1.h"
#include "UTIL1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "RGB.h"
#include "user_tasks.h"
/* Funciton definitions */
void user_main(void);
void RGB_test(void);
void LPTimer_Init(void);
void vTimerCallback(TimerHandle_t xTimer);
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	user_main();

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

void user_main(void) {
	TimerHandle_t xTimer;

	RGB_test();

	//xTaskCreate(vTask1, "Task 1", 200, NULL, 1, NULL);
	//xTaskCreate(vTask2, "Task 2", 200, NULL, 1, NULL);

	xTimer = xTimerCreate("Timer", 100, 1, (void *) 0, vTimerCallback);
	if (xTimer != NULL) {
		xTimerStart( xTimer, 0);
	}

	//LPTimer_Init();
}

void LPTimer_Init(void) {
	SIM_SCGC5 |= (1 << 0); //Activate the LPTMR in the system control gating register
	LPTMR0_PSR = 0b0000101; //Bypass the preescaler and select the LPO(low power oscilator of 1Khz as the source of the timer)
	LPTMR0_CMR = 500;			//compare of 500 clock cycles = .5 secs
	LPTMR0_CSR = 0b01000001;	//Activate the timer and enable interrupts	
	NVIC_ICPR(1) |= (1<<(58%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(58%32)); //Activate the LPTM interrupt
}

void RGB_test(void) {
	RGB_Init();
	RGB(1, 0, 0);
	RGB(0, 1, 0);
	RGB(0, 0, 1);
}

void vTimerCallback(TimerHandle_t xTimer) {
	const uint32_t ulMaxExpiryCountBeforeStopping = 10;
	uint32_t ulCount;
	/* The number of times this timer has expired is saved as the timer's ID. Obtain the
	 count. */
	ulCount = (uint32_t) pvTimerGetTimerID(xTimer);
	/* Increment the count, then test to see if the timer has expired
	 ulMaxExpiryCountBeforeStopping yet. */
	ulCount++;
	/* If the timer has expired 10 times then stop it from running. */
	if (ulCount >= ulMaxExpiryCountBeforeStopping) {
		/* Do not use a block time if calling a timer API function from a timer callback
		 function, as doing so could cause a deadlock! */
		xTimerStop( xTimer, 0);
	} else {
		/* Store the incremented count back into the timer's ID field so it can be read back again
		 the next time this software timer expires. */
		vTimerSetTimerID(xTimer, (void *) ulCount);
	}
}

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.3 [05.09]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
