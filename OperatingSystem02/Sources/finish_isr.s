.globl   finish_isr
.p2align 2
.type    finish_isr,%function
		
finish_isr:                    
	.fnstart
	cpy r3, r1
	add r3, r3, #0x10
	cpy r5, r0
	ldr r0, [r3]
	add r1, r1, #0x08
	cpy r7, r3
	str r1, [r3]
	add r3, #0x04
	ldr r4, =0x30f0
	str r4, [r3]
	add r5, r5, #0x10
	sub r7, r7, #0x10
	cpy pc, r5
	.fnend
