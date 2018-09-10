.globl   set_pc_sp
.p2align 2
.type    set_pc_sp,%function
		
set_pc_sp:                    
	.fnstart
	mov 	r7, r1
	add		r7, r7, #0x50
	cpy 	sp,r7   
	sub		r0, r0, #1
	cpy		pc, r0
	.fnend
