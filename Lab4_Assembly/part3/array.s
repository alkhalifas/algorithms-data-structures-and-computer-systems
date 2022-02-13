	.file	"array.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1600, %rsp
	movl	$4, -1584(%rbp)
	movl	$8, -1568(%rbp)
	movl	$15, -1540(%rbp)
	movl	$16, -1536(%rbp)
	movl	$23, -1508(%rbp)
	movl	$42, -1432(%rbp)
	movl	$0, %eax
	leave
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
