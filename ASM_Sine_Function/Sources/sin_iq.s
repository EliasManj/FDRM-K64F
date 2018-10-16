.globl   sin_iq
     .p2align 2
     .equ iq, 13
	.type    sin_iq,%function
			
sin_iq:                     
	.fnstart
	
	cpy r1, r0
	cpy r5, r0
	
	ldr r4, =0x00000001
	lsl r4, #iq
	mul r1, r1, r1				@x*2
	asr r1, r1, #iq
	
	ldr r2, =0x00000002a		@42
	lsl r2, #iq
	cpy r3, r1
	lsl r3, r3, #iq
	sdiv r3, r3, r2				@x*2/42
	qsub r2, r4, r3				@(1-x^2/42)
	
	ldr r0, =0x00000014			@20
	lsl r0, #iq
	lsl r3, r1, #iq
	sdiv r3, r3, r0				@(x^2/20)
	
	mul r3, r3, r2				
	asr r3, r3, #iq				@(x^2/20)*(1-(x^2/42))
	
	qsub r0, r4, r3				@ 1 - [(x^2/20)*(1-(x^2/42))]
	
	ldr r2, =0x00000006
	lsl r2, r2, #iq
	lsl r3, r1, #iq
	sdiv r2, r3, r2				@(x^2/6)
	
	mul r0, r0, r2
	asr r0, r0, #iq				@(x^2/6)*(1 - [(x^2/20)*(1-(x^2/42))])
	
	qsub r2, r4, r0				@ 1 - [(x^2/6)*(1 - [(x^2/20)*(1-(x^2/42))])]
	
	mul r5, r5, r2
	asr	r5, r5, #iq				@ x*(1 - [(x^2/6)*(1 - [(x^2/20)*(1-(x^2/42))])])
	
	cpy r0, r5
	 
	bx       lr           
	.fnend
