# assembly.s program

MOVQ a, %rax
MOVQ b, %rbx
addq %rbx, %rax
IMULQ %rbx
movq %rax, c
