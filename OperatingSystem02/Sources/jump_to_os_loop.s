.globl   jump_to_os_loop
.p2align 2
.type    jump_to_os_loop,%function
		
jump_to_os_loop:                    
	.fnstart
	mov 	r7, r1
	cpy 	sp,r7   
	cpy		pc, r0
	.fnend
