
# Godbolt

I **strongly** recommend using the godbolt tool (https://godbolt.org/) to write and experiment with your C programs for this exercise (i.e. **You do not have to compile each example by hand using gcc if you'd like to use godbolt instead**).  The color mappings in Compiler explorer (i.e. Godbolt) will help you see what is going on with the generated assembly. You **can** try using both godbolt and your compiler to generate assembly for this exercise.

Here is an example of the Godbolt tool (and also shows part 4 of this lab)
<img src="./assembly.PNG">

# Task 1 - Compiler Generated Assembly

Let us get some experience reading assembly code generated by the compiler (or godbolt)! It is actually kind of fun, you may learn some new instructions, and at the very least gain some intuition for what code the compiler is generating.

## Compiler generated assembly 1 - Swap

- Write a C program that swaps two integers(in the main body of code).
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as swap_int.s).
  - Use: `gcc -O0 -fno-builtin swap_int.c -S -o swap_int.s`
- Now modify your program to swap two long's.
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as swap_long.s).
  - Use: `gcc -O0 -fno-builtin swap_long.c -S -o swap_long.s`
- Compare each of the two assembly files using diff. See what changed.
- diff syntax
  - Use: `diff -y swap_int.s swap_long.s`
  
### Response/Observations

*After writing the two programs and observing the assembly outputs, there were a few differences between the two files. The most notable difference is the fact that the integer file mostly comprised movl instructions, whereas the long file comprised movq instructions. I looked up the differences out of curiosity, and learned that the two are variations of the same mov instruction. Movq moves 8 bytes, whereas movl moves 4 bytes. The second observation I noticed is that the int file containing the line '-4(%rbp)' in which it is accessing the value at -4 bytes offset from address rbp, whereas the long file contains the line '-8(%rbp) where it is accessing -8 bytes offset from address rbp. This difference is accounted for by the fact that integers are 4 bytes, and longs are 8 bytes.*

## Compiler generated assembly 2 - Functions

- Write a C program that swaps two integers in a **function** (You may use today's slide as a reference)
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as swap.s).
  - Use: `gcc -O0 -fno-builtin  swap.c -S -o swap.s`
- Do the instructions use memory/registers in a different way?

### Response/Observations

*The first observation I can make realtive to the previous part of this assignment is that the function adds much more information to the output assembly file giving it two main sections: the block pertaining to the swap function and another pertaining to the main function. Within the main function, we see some familiar items such as the registers (rbp, rsp, ...) that we saw previously, and a few instructions such as MOVL and MOVQ we saw in the previous file. However, there is also a new instruction described as CALL that references the function swap and passes control to it. It appears as though the instruction transfers the control of the program to the swap function, and within that program there are two new registers that we have not seen before: ebp, and esp. The ebp register concerns the base address, where as the esp register concernts the stack, and togeher handle the call and return mechanisms. Once completed, the values of the input integers are the returnd to the program using the eax register. One interesting item to note are the pop and push instructions we see within the function swap itself. Pushing a value writes it to the stack, whereas popping the value means restoring it on top of the stack into a register, specifically with the rbp register. *

## Compiler generated assembly 3 - Static Array
- Write a C program called array.c that has an array of 400 integers in the function of main.
  - Initialize some of the values to something (do not use a loop) (e.g. myArray[0]=72; myArray[70]=56; etc)
  	- Note that it is helpful to use 'weird' numbers so you can see where they jump out.
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as array.s).
  - Use: `gcc -O0 -fno-builtin -mno-red-zone array.c -S -o array.s`
- How much are the offsets from the address?

### Response/Observations

*With the file compiled and translated to Assembly, there are a few immediate items to note here. First, we can see the instruction 'SUB rsp, 1480' in which it moves the staack pointer to cover what it needs, thus subtracting enough from RSP to ensure that the array can be created. I initialized an array with a length of 400, and populated the first index position with a value of 0. In assembly, this translated to 'MOV DWORD PTR [rbp-1600], 0'. The value 1600 comes from the fact that we created an integer array of length 400, with 4 bytes per integer, giving us a total of 1600. In the following command, we initialize an integer in position 4, which translates to an offset described by [rbp-1584]. As we continue down the list, we notice the same pattern where elements adjacent to one another are consistently 4 bytes away from each other.*

## Compiler generated assembly 4 - Dynamic Array 

- Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.
  - Initialize some of the values to something (do not use a loop) (e.g. myArray[66]=712; myArray[70]=536; etc)
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as array2.s).
  - Use: `gcc -O0 -fno-builtin  array2.c -S -o array2.s`
- Study the assembly and think about what is different from the static array.

### Response/Observations

*When comparing the two, my first initial observation is that a great deal more code was generated for a dynamic array realtive to its static counterpart. In addition to the many instructions we saw with static arrays, there are two new instructions that appeared with its dynamic counterpart: SAL, and CDQE, which at to left shirt a byte or word, and convert a double word to quad, respectively. Finally, the last main observation is that each addition of a value to a dynamic array now consists of three instructions instead of one: specifically MOV, ADD and MOV again. The first MOV instruction utilizes the %rax register (long size register) with a destination of [rbp-16]. Next, the rax register is used as a source with a destination value corresponding to the byte off set, for example 16. Finally, yet another MOV instruction listing [rax] as the source with a value corresponding to the added value of interest.*

## Compiler generated assembly 5 - Goto
The C programming language has a 'goto' command, search how to use it if you have not previously.
(Note that the usage of 'goto' is strongly discouraged in your programs--even mentionining such a keyword may anger programmers due to the difficulty of following many goto statements--that said, goto translates directly to an assembly command so it is interesting for this exercise)

- Write a C program using the goto command and a label.
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as goto.s).
  - Use: `gcc -O0 -fno-builtin  goto.c -S -o goto.s`
- Observe what kind of jmp statement is inserted.

### Response/Observations

*After looking over the assembly file, I noticed two different jump instructions here: JNE and JMP. Under the main label, JNE, which stands for jump not equals, was listed as the idea here is to jump to a label called L2 if the values do not match in the TESTL instruction above it. On the other hand, the label L3 listed the JMP instruction, which performs an unconditional jump to the label L5 which is the end of the script.*

## Compiler generated assembly 6 - For-loops
- Write a C program using a for-loop that counts to 5.
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as for.s).
  - Use: `gcc -O0 -fno-builtin  for.c -S -o for.s`
- Observe where the code goes for the condition statement (at the start or at the end?).

### Response/Observations

*I wrote a simple script here that prints line over the course of a for loop within main(). Upon looking over the translated assembly code, it was not exactly what I had expected. Using CompilerExoplorer, I noticed that the lines representing the for loop in C, are actually dispersed across three labels in Assembly. Starting with the MOV instruction using a source of [rbp-4] and a destination of 0 in main(), we move to the L3 label where the eax, esi and edi registers are used to print the statement. Upon completion, the value 1 is added to [rbp-4], which I assume represents an incrementation within the for loop. The CMP instruction is then used to compare the two values, with the first being [rbp-4] which represents the current value, and the value of 4 which is the final value within the range of the for loop. Once the values are the same, the LEAVE instruction is then used followed by RET, to return.*

## Compiler generated assembly 7 - Switch Statements

- Write a C program using a switch statement (Sample here)[https://www.tutorialspoint.com/cprogramming/switch_statement_in_c.htm].
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as switch.s).
  - Use: `gcc -O0 -fno-builtin switch.c -S -o switch.s`
- See what code a switch statement generates. Is it optimal?

### Response/Observations

*After translating the program to Assembly, there are a few noticeable items I see here that I have not seen in the other items we have prepared so far. First, I noticed that the strings listed in each of the cases, are listed at the top of the Assembly file in their respective labels, ranging from .LC0 to .LC4 which I had not seen so far. Second, there is a new Assembly instruction we have not come across yet called MOVSX whose function is to move byte to word with sign-extension. From what I understand, this instruction obtains the byte located at the specific address EAX, and is then copied to the destination, which represents the value of the switch statement. This of course is followed by a SUB, CMP and JA instructions that subtract, compare and jumps based on the switch statement's value. Finally, for each of the cases, a label is designated comprising a MOV, CALL, and JMP instructions. *

## Compiler generated assembly 8 - Add Function

- Write a C program that calls an add function(long add(long a, long b).
  - Save, Compile, and Run the program to verify it works.
- Output the assembly from that program (Save it as add.s).
  - Use: `gcc -O0 -fno-builtin add.c -S -o add.s`
- Observe the outputs
- Observe arguments put into registers
- Observe where 'popq' is called.

### Response/Observations

*In this file, we create a function called add(long a, long b) which is called in main(). After looking over the code, we see that there is a section or label dedicated to the add() function listed above the one pertaining to main(). Inside add, we see two instructions at the top and bottom of the function: PUSH and POP, and within these instructions are a number of other instructions such as MOV. The MOV instructions utilize the RDI and RSI registers which are used for a functions first and second arguments, respectively. THis is then followed by the ADD function which adds the two values witin RAX and RDX together. Finally, this is followed by the POP instruction to restore whatever is on top of the stack into a register. The values are then printed in one of the string labels showing the proper output format.*

# More resources to help

- Matt Godbolt has written a great tool to help understand assembly generated from the compiler. 
  - https://godbolt.org/
- An assembly cheat sheet from Brown
  - https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf
- MIT Cheat sheet
  - http://6.035.scripts.mit.edu/sp17/x86-64-architecture-guide.html

# Deliverable

1. Add your .S files that you have generated to this repository (whether from gcc or from godbolt.org / CompilerExplorer ).
  - Note this submission will be auto graded for completion (i.e. save the file names as shown).
  - Add your observations (brief 1-2 sentences) in the appropriate response/observations section for each code in this readme file.
  

# Going Further

- (Optional) Try the objdump example to read the disassembly from your programs executables. Observe how close the output is to the compiler generated output.
