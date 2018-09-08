.thumb
.syntax unified
.globl   atomic_write
.p2align 2
.type    atomic_write,%function
		
atomic_write:                    
	.fnstart
	ldrex r2, [r1]
	mov r2, r0
	strex r3, r2, [r1]
	cmp r3, #0
	bne atomic_write
	bx lr
	.fnend
