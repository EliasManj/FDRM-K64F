/* This assembly file uses GNU syntax */
	.text
	.section	.rodata
	.align	2
	.equ iq, 8
	
.LC0:
	
	.text
	.align	2
	.global	main
	.type main function
	
main:
	push {r3, lr}
	add	r3, sp, #4
	
	@qaddition
	ldr	r0, =0x00010000
	ldr	r1, =0x00010000
	qadd r2, r0, r1
	ldr	r0, =0x00000240
	ldr	r1, =0x000004E0
	qadd r2, r0, r1
	
	@Multiply 1.75(01.11)*(01.01)1.25
	ldr	r0, =0x000001c0
	ldr	r1, =0x00000140
	mul r0, r0, r1	
	asr r0, r0, #iq
	
	@Divide 2(10.00)/.5(00.10)
	ldr	r0, =0x00000200
	ldr	r1, =0x00000080
	lsl r0, r0, #iq
	sdiv r2, r0, r1
	
	@substract
	ldr	r0, =0x80088000
	ldr	r1, =0x00044000
	uqsub16 r0, r1, r0
	lsl r0, r0, #iq
	
	ldr	r0, =0x00000880
	ldr	r1, =0x10000440
	mul r0, r0, r1
	asr r0, r0, #iq
			
	pop {r3, pc}
	
	.align	2
.L3:
	.word	.LC0
	.end
