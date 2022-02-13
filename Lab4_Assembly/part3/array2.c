// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.
#include <stdio.h>
#include <stdlib.h>

int main() {

    int size = 400;

    int* myArray2 = (int*)malloc(size*sizeof(int));

    myArray2[0] = 0;    
    myArray2[4] = 4;    
    myArray2[8] = 8;    
    myArray2[15] = 15;    
    myArray2[16] = 16;    
    myArray2[23] = 23;    
    myArray2[42] = 42;    
    myArray2[43] = 43;    
    
    free(myArray2);

    return 0;
}
