// Compile with: gcc -g -Wall args.c -o prog
// Run with: ./prog somefile.s

#include <stdio.h>

int main(int argc, char** argv){

    printf("argc is the argument count variable: %d\n", argc);

    int i;

    for (i = 0; i< argc; i++){
        printf("argv[%d] is %s\n", i, argv[i]);
    }

    return 0;
}
