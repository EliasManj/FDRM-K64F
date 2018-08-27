.globl   set_lr
.p2align 2
.type    set_lr,%function
		
set_lr:                    @ Function "pop_stack" entry point.
	.fnstart
	mov 	lr, r0   
	bx      lr           	  @ Return by branching to the address in the link register.
	.fnend
