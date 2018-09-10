.globl   set_sp
.p2align 2
.type    set_sp,%function
		
set_sp:                    
	.fnstart
	cpy r7, r0	
	cpy sp, r7
	bx lr
	.fnend
