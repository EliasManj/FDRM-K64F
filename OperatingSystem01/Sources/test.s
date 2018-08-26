.thumb
.syntax unified
.globl   test
.p2align 2
.type    test,%function
		
test:                    @ Function "pop_stack" entry point.
	.fnstart
	add r7,r7,#0x4
	cpy sp,r7
	ldm sp!,{r4,r7,lr}
	add sp,sp,#16
	bx lr
	.fnend
