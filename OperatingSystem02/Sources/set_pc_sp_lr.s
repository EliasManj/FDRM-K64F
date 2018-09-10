.globl   set_pc_sp_lr
.p2align 2
.type    set_pc_sp_lr,%function
		
set_pc_sp_lr:                    
	.fnstart
	@Cambiar poner [0x48] [0x48+4] en 0x38
	@Poner el link register a RunNextTask
	add r3, r1, #0x00
	add r3, r3, #0x10
	ldr r4, [r3]
	add r3, r3, #0x04
	ldr r5, [r3]
	add sp, sp, #0x08
	sub sp, sp, #0x10
	push {r4,r5}
	add sp, sp, #0x10
	add r2, r2, #0x08
	@Poner en r2 (pc) para que se regrese
	add r2, r2, #0x00
	@Poner las direcciones en ff48
	add sp, sp, #0x18
	add r1, r1, #0x0C
	add r0, r0, #0x17
	cpy r5, r0
	cpy r0, r1
	cpy r1, r5
	ldr r1, =0x30e4
	push {r0,r1}
	cpy sp,r7
	cpy	pc, r2
	.fnend
