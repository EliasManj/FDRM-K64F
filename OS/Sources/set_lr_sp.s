.globl   set_lr_sp
.p2align 2
.type    set_lr_sp,%function
		
set_lr_sp:                    @ Function "pop_stack" entry point.
	.fnstart
	mov 	r7, r1
	add		r7, r7, #0x40
	cpy 	sp,r7   
	sub		r0, r0, #1
	cpy		pc, r0
	.fnend
