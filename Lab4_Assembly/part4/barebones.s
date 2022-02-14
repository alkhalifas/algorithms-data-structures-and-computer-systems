# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans:
	pushq %rbp			# We are pushing values onto the stack using register base pointer
	movq  %rsp, %rbp		# We are moving a value from register stack pointer source, to register base pointer destination, thus creating empty stack.

					# (2) What is going on here
					# Ans:
	movq $1, %rax			# We are moving a quad with value of 1 from source $1 operand, to %rax ( long size register )
	movq $1, %rdi			# We are moving a quad with value 1 from source $1 operand, to %rdi ( first program argument in function)
	leaq .hello.str,%rsi		# We use leaq (load effective address), so we can store value of 'hello' into %rsi (second program argument in function)


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: It is an assembly langauge request to the operating system kernel to transfer control to accomplish a given task.
	syscall				# Which syscall is being run?
					# Ans: %rax is set to 1 so I would assume is a system write

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: We could also use sysenter instead

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	Here we  are using exit syscall, error code 0
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans: I would assume because the size of the string is 13
