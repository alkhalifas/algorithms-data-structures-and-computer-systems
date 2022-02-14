// Write a C program using the goto command and a label.

#include <stdio.h>
#include <stdlib.h>


int main() {

    
    int value = 15;

    if (value % 2 == 0) {
        goto even;
    } else {
        goto odd;
    }

    even:
        printf("I am EVEN! -> %d\n", value);


        return 0;
    odd:
        printf("I am ODD! -> %d\n", value);



    return 0;
}
