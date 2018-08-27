.thumb
.syntax unified
.globl   set_sp
.p2align 2
.type    set_sp,%function
		
set_sp:                    @ Function "pop_stack" entry point.
	.fnstart
	mov 	r7, r0
	cpy sp,r7   
	add r7, sp, #8
	bx      lr
	.fnend
