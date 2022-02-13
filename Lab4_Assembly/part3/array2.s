	.file	"array2.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$400, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$0, (%rax)
	movq	-16(%rbp), %rax
	addq	$16, %rax
	movl	$4, (%rax)
	movq	-16(%rbp), %rax
	addq	$32, %rax
	movl	$8, (%rax)
	movq	-16(%rbp), %rax
	addq	$60, %rax
	movl	$15, (%rax)
	movq	-16(%rbp), %rax
	addq	$64, %rax
	movl	$16, (%rax)
	movq	-16(%rbp), %rax
	addq	$92, %rax
	movl	$23, (%rax)
	movq	-16(%rbp), %rax
	addq	$168, %rax
	movl	$42, (%rax)
	movq	-16(%rbp), %rax
	addq	$172, %rax
	movl	$43, (%rax)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
