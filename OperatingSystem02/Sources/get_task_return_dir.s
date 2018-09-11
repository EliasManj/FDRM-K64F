.globl   get_task_return_dir
.p2align 2
.type    get_task_return_dir,%function
		
get_task_return_dir:                    
	.fnstart
	cpy r1, r0
	add r1, r1, #0x10
	sub r1, r1, #0x04
	add r1, r1, #0x20
	ldr r0, [r1]
	bx lr
	.fnend
