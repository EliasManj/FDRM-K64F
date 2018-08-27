.thumb
.syntax unified
.globl   set_sp2
.p2align 2
.type    set_sp2,%function
		
set_sp2:                    @ Function "pop_stack" entry point.
	.fnstart
	mov 	r7, r0
	cpy 	sp,r7   
	bx      lr
	.fnend
