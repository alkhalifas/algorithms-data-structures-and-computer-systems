# x86-64 Assembly 

> "Nearing Machine Code Representation"

## Introduction/Motivation

Not so long ago (in a galaxy not so far away), programmers wrote most of their code in assembly. While programmers today primarily use higher level languages (Python, C, etc), it is not uncommon to debug the assembly of your code. These higher level languages afterall typically translate down to an assembly or assembly-like language. 

If you are interested in cybersecurity and reverse engineering, folks more frequently write and analyze assembly code. For high performance applications like [games](https://www.gamasutra.com/view/news/169946/CC_low_level_curriculum_Looking_at_optimized_assembly.php), programmers may write very optimized code using assembly to get things *just* right. If you are working in hardware or an embededd device, you might also do some assembly programming, as other languages environments are too bulky to support on a small device. Even web developers are using something called 'webassembly'. Hmm, the list is getting long here--I think the point is that learning assembly has quite some relevance! Let's dig in and get some practice.

In today's lab you are going to get some practice looking at and writing assembly.

# Task - Assembly - A first program

The first task is to actually just write a 'hello world' in assembly.

- Enter the following text into a file called [hello.s](./hello.s)
- ```asm
	  # Example for x86-64 processor using AT&T Style syntax
	.global _start

	.text

	_start:
		# Write a message to the screen
		mov $1, %rax
		mov $1, %rdi
		mov $message, %rsi
		mov $13, %rdx
		syscall

		# Exit the program
		mov $60, %rax
		xor %rdi, %rdi
		syscall

	message:
		.ascii "Hello, World\n"
  ```
- Save the file and then we will assemble the program using the GNU Assembler (https://en.wikipedia.org/wiki/GNU_Assembler)
  - `gcc -c hello.s`
  - This step builds an object file (.o suffix).
  - We now need to create an executable object file using our previously created hello.o file using a tool called *ld*
  - `ld hello.o -o hello`
    - Run `man ld` to learn more.
  - When this has been completed, push hello.s to your repo, and move on!

There are a few interesting things with this program.
1. First, there is a *global* symbol. The global sets up the starting point, as our program needs some entry point. You could think of '_start' as 'main' like in a C program. You can learn more here: http://web.mit.edu/gnu/doc/html/as_7.html#SEC89
2. The next directive (remember, lines that start with a '.' are directives) is .text. These are where our instructions start. https://stackoverflow.com/questions/14544068/what-are-data-and-text-in-x86
3. The next few lines are moving some values into registers. The first statement moves the immediate value $1 into register %rax. A few more lines down we see a syscall.
	  1. What is a syscall? In short, it is a call to a function built into the operating system (More here: https://www.geeksforgeeks.org/operating-system-introduction-system-call/).
	  2. To figure out which syscall it is, use this resource: https://filippo.io/linux-syscall-table/
4. Finally at the end there is a label ('message:') with a string literal (.ascii "Hello, World\n"). https://docs.oracle.com/cd/E26502_01/html/E28388/eoiyg.html

## Aside - Machine Representation of Numbers

  * Note: it may be beneficial to look at this ascii table to see how numbers and letters are represented. https://www.asciitable.com Remember, we do not have a 'text' datatype in assembly. Text instead is represented by numbers shown in the ascii table.

# Deliverable

1. Complete the [hello.s](./hello.s)
