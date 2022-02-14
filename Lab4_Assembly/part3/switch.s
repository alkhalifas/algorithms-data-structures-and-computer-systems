	.file	"switch.c"
	.section	.rodata
.LC0:
	.string	"Excellent!\n"
.LC1:
	.string	"Well Done!\n"
.LC2:
	.string	"Lets try harder next time!\n"
	.align 8
.LC3:
	.string	"You might need to try again...\n"
.LC4:
	.string	"Not even close :( \n"
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
	movb	$66, -1(%rbp)
	movsbl	-1(%rbp), %eax
	subl	$65, %eax
	cmpl	$5, %eax
	ja	.L2
	movl	%eax, %eax
	movq	.L4(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L4:
	.quad	.L3
	.quad	.L5
	.quad	.L6
	.quad	.L7
	.quad	.L2
	.quad	.L8
	.text
.L3:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L2
.L5:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L2
.L6:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L2
.L7:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	jmp	.L2
.L8:
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	nop
.L2:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
