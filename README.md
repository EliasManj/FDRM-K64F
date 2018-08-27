# FDRM-K64F

## Board
![alt text](https://http2.mlstatic.com/tarjeta-freescale-nxp-freedom-board-frdm-k64f-kinetis-D_NQ_NP_705002-MLM27197322984_042018-F.jpg)

## RGB Pins

| LED | K64
| ------ |:------------------:|
| RED              | PTB22/SPI2_SOUT/FB_AD19/CMP2_OUT |
| BLUE              | PTB21/SPI2_SCK/FB_AD30/CMP1_OUT    |
| GREEN              | PTE26/ENET_1588_CLKIN/UART4_CTS_b/RTC_CLKOUT/USB0_CLKIN |

![alt text](https://lh3.googleusercontent.com/qYSUjl_BCulbMZvFPh3Ny8xh5UI0lI--XBM8nrluWPSO5If99ZIUJBeXwkgozKOC0X9vDKdfxomhX75O3AQF66qgPTjqLB0b2BnYiqQk_YReQhOTnWXaNZCPCihne2bgT9m7jLV47pZLAFJB)

## Push Button Switches

SW2 is connected to PTC6 and SW3 is connected to PTA4

Only SW3 can be a non-maskable interrupt

| SWITCH | FUNCTION | ISR
| ------ |:------------------:|:-------:|
| SW2              | PTC6/SPI0_SOUT/PD0_EXTRG/I2S0_RX_BCLK/FB_AD9/I2S0_MCLK/LLWU_P10  | PORTC_IRQHandler() |
| SW3              | PTA4/FTM0_CH1/NMI_b/LLWU_P3     | PORTA_IRQHandler()  |

## References 

[K64F User Manual](https://www.nxp.com/docs/en/user-guide/FRDMK64FUG.pdf)

[K64 Sub-Family Reference Manual](http://www.mouser.com/ds/2/813/K64P144M120SF5RM-1074828.pdf)

[Using Assembly and Intrinsics in C](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.100748_0606_00_en/lmi1470147220260.html)

[Segger J-Link Firmware for OpenSDAv2 CodeWarrior](https://mcuoneclipse.com/2014/04/27/segger-j-link-firmware-for-opensdav2/)

[ARM Interrupt Handling](http://www.eng.auburn.edu/~nelson/courses/elec5260_6260/slides/ARM%20STM32F407%20Interrupts.pdf)
