.globl   clean_stack_from_chaintask
.p2align 2
.type    clean_stack_from_chaintask,%function
		
clean_stack_from_chaintask:                    
	.fnstart
	add r7, r7, #0x40
	cpy	sp, r7
	bx lr
	.fnend
