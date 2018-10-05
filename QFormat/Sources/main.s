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
	add	r3, sp, #8
	
	@qaddition CHECK
	ldr	r0, =0x00000044	@4.25
	ldr	r1, =0x00000088	@8.5
	qadd r2, r0, r1	@4.25 + 8.5 = 12.75
	qsub r3, r1, r0	@8.5 - 4.25 = 4.25
	qsub r4, r0, r1	@4.25 - 8.5 = -4.25
	ldr	r0, =0xffffffbc	@-4.25
	qadd r2, r0, r1	@8.5+(-4.25)
	
	@Need to change iq to 12
	@Multiply 1.75(01.11)*(01.01)1.25 CHECK
	ldr	r0, =0x00001400	@1.25
	ldr	r1, =0x00001c00	@1.75
	mul r0, r0, r1	@1.75*1.25
	asr r0, r0, #iq
	ldr	r0, =0x00001400	@1.25
	ldr	r1, =0xfffff000	@-1
	mul r0, r0, r1	@1.25*-1
	asr r0, r0, #iq
	ldr	r1, =0x00001c00	@1.75
	mul r0, r1, r0 @1.75*-1.25
	asr r0, r0, #iq
	
	@Need to change iq to 8
	@Divide 2.0(10.10)/.5(00.10) CHECK
	ldr	r0, =0x00000200 @2
	ldr	r1, =0x00000080	@.5
	lsl r0, r0, #iq		
	sdiv r2, r0, r1		@2/.5
	
	ldr	r0, =0xfffffe00 @-2
	lsl r0, r0, #iq
	sdiv r2, r0, r1		@-2/.5
	
	ldr	r0, =0x00000100 @1
	ldr	r1, =0x00000100	@1
	lsl r0, r0, #iq
	sdiv r2, r0, r1
	
	ldr	r0, =0x00000100 @1
	ldr	r1, =0xffffff00	@-1
	lsl r0, r0, #iq
	sdiv r2, r0, r1		@-1/1
	
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
