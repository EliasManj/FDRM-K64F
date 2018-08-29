.thumb
.syntax unified
.globl   restore_context
     .p2align 2
	.type    restore_context,%function
			
restore_context:                     
	.fnstart
	mov r7, r0
	sub r1, r1, #1
	cpy	sp, r7
	cpy pc, r1
	.fnend
