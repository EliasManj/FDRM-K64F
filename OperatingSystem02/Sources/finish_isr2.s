.globl   finish_isr2
.p2align 2
.type    finish_isr2,%function
		
finish_isr2:                    
	.fnstart
	cpy r3, r1
	add r3, r3, #0x10
	cpy r4, r3
	sub r4, #0x08
	cpy r5, r0
	ldr r0, [r3]
	str r4, [r3]
	add r1, r1, #0x30
	sub r1, r1, #0x04
	str r2, [r1]
	add r2, r2, #0x02
	add r1, r1, #0x04
	str r2, [r1]
	add r5, r5, #0x1C
	cpy pc, r5
	.fnend
