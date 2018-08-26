.globl   set_lr_sp
.p2align 2
.type    set_lr_sp,%function
		
set_lr_sp:                    @ Function "pop_stack" entry point.
	.fnstart
	mov 	r7, r1
	cpy 	sp,r7   
	add 	r7, sp, #8
	mov 	lr, r0
	bx      lr
	.fnend
