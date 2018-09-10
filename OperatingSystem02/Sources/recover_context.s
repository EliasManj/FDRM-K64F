.globl   recover_context
.p2align 2
.type    recover_context,%function
		
recover_context:                    
	.fnstart
	add r1, r1, #0x10
	str r0, [r1]
	cpy r0, r1
	add r1, r1, #0x04
	add r0, r0, #0x1c
	ldr r3, [r0]
	cpy r0, r3
	str r3, [r1]
	bx  lr
	.fnend
