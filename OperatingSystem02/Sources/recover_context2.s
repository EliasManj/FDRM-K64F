.globl   recover_context2
.p2align 2
.type    recover_context2,%function
		
recover_context2:                    
	.fnstart
	add r0, r0, #0x10
	str r2, [r0]
	add r0, r0, #0x04
	str r1, [r0]
	cpy r0, r1
	bx  lr
	.fnend
