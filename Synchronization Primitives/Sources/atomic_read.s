.thumb
.syntax unified
.globl   atomic_read
.p2align 2
.type    atomic_read,%function
		
atomic_read:                    
	.fnstart
	ldr r1, [r0]
	mov r0, r1
	bx lr
	.fnend
