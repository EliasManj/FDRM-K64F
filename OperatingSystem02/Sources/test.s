.thumb
.syntax unified
.globl   test
.p2align 2
.type    test,%function
		
test:                    @ Function "pop_stack" entry point.
	.fnstart
	add r7,r7,#0x20
	cpy sp,r7
	pop {r4-r5,r7,pc}
	.fnend
