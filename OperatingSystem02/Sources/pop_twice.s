.globl   pop_twice
.p2align 2
.type    pop_twice,%function
		
pop_twice:                    
	.fnstart
	pop {r0, r1}
	bx lr
	.fnend
