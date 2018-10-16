#include "SerialPorts.h"
#include "IO_Map.h"
#include "RGB.h"
/*
 * SERIAL0 OUT PTC5
 * SERIAL0 RX  PTC7
 * 
 * SERIAL1 OUT PTC0
 * SERIAL1 RX  PTC9
 * 
 * SERIAL2 OUT PTC8
 * SERIAL2 RX  PTC1
 * 
 * SERIAL3 OUT PTC3
 * SERIAL3 RX  PTC2
 */

uint8_t serial_recive;

void serial_ports_Init(void) {
	serial0_Init();
	serial1_Init();
	serial2_Init();
	serial3_Init();
	portC_Init();
	Push_Btn_SW2();
	first_bit = 1;
	probe = 1;
	GPIOC_PDOR ^= (-(probe) ^ GPIOC_PDOR ) & (1 << 5); //Put PTC5 as HIGH
	xTimerSerial = xTimerCreate("Serial", 100, 0, (void *) 0,
			vSerialTimerCallback0);
}

void serial0_Init(void) {
	PORTC_PCR7 |= (1 << 8);		//Set to GPIO
	PORTC_PCR7 |= (10 << 16);//Interrupt on falling edge
}

void serial1_Init(void) {
	PORTC_PCR9 |= (1 << 8);
	PORTC_PCR9 |= (10 << 16);
}

void serial2_Init(void) {
	PORTC_PCR1 |= (1 << 8);
	PORTC_PCR1 |= (10 << 16);
}

void serial3_Init(void) {
	PORTC_PCR2 |= (1 << 8);
	PORTC_PCR2 |= (10 << 16);
}

void portC_Init(void) {
	SIM_SCGC5 |= (1 << 11);
	NVIC_IP(77) = 17;
	NVIC_IP(61) = 17;
	//NVIC_ICPR(1) |= (1 << (61 % 32)); //Clean flag of LPTM in the interrupt vector
	//NVIC_ISER(1) |= (1 << (61 % 32));//Activate the LPTM interrupt
}

void Push_Btn_SW2(void) {
	SIM_SCGC5 |= (1 << 11);
	PORTC_PCR6 |= (1<<8);
	PORTC_PCR6 |= (10<<16);
	NVIC_ICPR(1) |= (1<<(61%32));
	NVIC_ISER(1) |= (1<<(61%32));
}

//Interrupt handlers

void ivINT_LPTimer(void) {
	LPTMR0_CSR |= (1 << 7); //Clear timer compare flag
	if (probe) {
		probe = 0;
	} else {
		probe = 1;
	}
	GPIOC_PDOR ^= (-(probe) ^ GPIOC_PDOR ) & (1 << 5); //Put PTC5 as HIGH
}

void ivINT_PORTC(void) {
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	//Check which port the interrupt came from
	if ((PORTC_PCR6 &0x01000000) == 0x01000000) {
		RGB(0,0,1);
		PORTC_PCR6 &= ~(0<<24);
		if (xTimerSerial != NULL) {
			if( xTimerStartFromISR( xTimerSerial,&xHigherPriorityTaskWoken ) != pdPASS ) {
				RGB(1,0,1);
			}
		}
	} else if ((PORTC_PCR2&0x01000000) == 0x01000000) {
		RGB(0,1,0);
		PORTC_PCR2 &= ~(0<<24);
	} else if ((PORTC_PCR1&0x01000000) == 0x01000000) {
		RGB(0,1,1);
		PORTC_PCR1 &= ~(0<<24);
	} else if ((PORTC_PCR9&0x01000000) == 0x01000000) {
		RGB(1,0,0);
		PORTC_PCR9 &= ~(0<<24);
	} else if ((PORTC_PCR7&0x01000000) == 0x01000000) {
		RGB(1,0,1);
		PORTC_PCR7 &= ~(0<<24);
		if (xTimerSerial != NULL) {
			first_bit = 1;
			xTimerStartFromISR( xTimerSerial,&xHigherPriorityTaskWoken );
		}
	}
}

//Timer callback for PWM0
void vSerialTimerCallback0(TimerHandle_t xTimer) {
	if (first_bit) {
		NVIC_ICER(1) |= 0xFFFFFFFF;			//Disable interrupt
		first_bit = 0;
		xTimerChangePeriod(xTimer, 5, 0);
	} else {
		uint32_t ulCount;
		ulCount = (uint32_t) pvTimerGetTimerID(xTimer);
		if (ulCount < 8) {
			if(probe == 1) {
				probe = 0;
			} else {
				probe = 1;
			}
			GPIOC_PDOR ^= (-(probe) ^ GPIOC_PDOR ) & (1 << 5); //Put PTC5 as HIGH
			serial_recive>>=1;
			if (((GPIOC_PDIR & SERIAL0_MASK) >> SERIAL0_SHIFT)==1) {
				serial_recive = serial_recive | 0x80;
			}
			xTimerChangePeriod(xTimer, 7, 0);
			if(ulCount == 7) {
				ulCount = 7;
			}
			ulCount++;
			vTimerSetTimerID(xTimer, (void *) ulCount);
		} else if (ulCount == 8) {
			if (((GPIOC_PDIR & SERIAL0_MASK) >> SERIAL0_SHIFT)==1) {
				if(serial_recive > 0 && serial_recive <= 100) {
					duty_cycle1 = serial_recive;
				}
			}
			probe = 1;
			ulCount++;
			xTimerChangePeriod(xTimer, 7, 0);
			vTimerSetTimerID(xTimer, (void *) ulCount);
		} else {
			NVIC_ICPR(1) |= (1<<(61%32));
			NVIC_ISER(1) |= (1<<(61%32));
			xTimerStop(xTimer, 0);
			vTimerSetTimerID(xTimer, (void *) 0);
		}
	}

}

//Timer callback for PWM1
void vSerialTimerCallback1(TimerHandle_t xTimer) {
	NVIC_ICER(1) |= 0xFFFFFFFF;			//Disable interrupt
	uint32_t ulCount;
	ulCount = (uint32_t) pvTimerGetTimerID(xTimer);
	if (ulCount < 8) {
		serial_recive >>= 1;
		if (((GPIOC_PDIR & SERIAL1_MASK) >> SERIAL1_SHIFT)==1) {
			serial_recive = serial_recive | 0x80;
		}
		//Timer con 100us
		xTimerChangePeriod(xTimer, 2, 0);
		ulCount++;
		vTimerSetTimerID(xTimer, (void *) ulCount);
	} else {
		if (((GPIOC_PDIR & SERIAL1_MASK) >> SERIAL1_SHIFT)==1) {
			xTimerStop(xTimer, 1);
			if(serial_recive > 0 && serial_recive <= 100) {
				duty_cycle1 = serial_recive;
			}
		}
	}
}

//Timer callback for PWM2
void vSerialTimerCallback2(TimerHandle_t xTimer) {
	NVIC_ICER(1) |= 0xFFFFFFFF;			//Disable interrupt
	uint32_t ulCount;
	ulCount = (uint32_t) pvTimerGetTimerID(xTimer);
	if (ulCount < 8) {
		serial_recive >>= 1;
		if (((GPIOC_PDIR & SERIAL2_MASK) >> SERIAL2_SHIFT)==1) {
			serial_recive = serial_recive | 0x80;
		}
		//Timer con 100us
		xTimerChangePeriod(xTimer, 100, 0);
		ulCount++;
		vTimerSetTimerID(xTimer, (void *) ulCount);
	} else {
		if (((GPIOC_PDIR & SERIAL2_MASK) >> SERIAL2_SHIFT)==1) {
			xTimerStop(xTimer, 1);
			if(serial_recive > 0 && serial_recive <= 100) {
				duty_cycle2 = serial_recive;
				NVIC_ICPR(1) |= (1<<(61%32));
				NVIC_ISER(1) |= (1<<(61%32));
			}
		}
	}
}

//Timer callback for PWM3
void vSerialTimerCallback3(TimerHandle_t xTimer) {
	NVIC_ICER(1) |= 0xFFFFFFFF;			//Disable interrupt
	uint32_t ulCount;
	ulCount = (uint32_t) pvTimerGetTimerID(xTimer);
	if (ulCount < 8) {
		serial_recive >>= 1;
		if (((GPIOC_PDIR & SERIAL3_MASK) >> SERIAL3_SHIFT)==1) {
			serial_recive = serial_recive | 0x80;
		}
		//Timer con 100us
		xTimerChangePeriod(xTimer, 2, 0);
		ulCount++;
		vTimerSetTimerID(xTimer, (void *) ulCount);
	} else {
		if (((GPIOC_PDIR & SERIAL3_MASK) >> SERIAL3_SHIFT)==1) {
			xTimerStop(xTimer, 1);
			if(serial_recive > 0 && serial_recive <= 100) {
				duty_cycle3 = serial_recive;
			}
		}
	}
}

void LPTimer_Init(void) {
	SIM_SCGC5 |= (1 << 0); //Activate the LPTMR in the system control gating register
	LPTMR0_PSR = 0b0000101; //Bypass the preescaler and select the LPO(low power oscilator of 1Khz as the source of the timer)
	LPTMR0_CMR = 50;			//compare of 500 clock cycles = .5 secs
	LPTMR0_CSR = 0b01000001;	//Activate the timer and enable interrupts	
	NVIC_ICPR(1) |= (1<<(58%32));		//Clean flag of LPTM in the interrupt vector
	NVIC_ISER(1) |= (1<<(58%32)); //Activate the LPTM interrupt
	NVIC_IP(58) = 17;
}
