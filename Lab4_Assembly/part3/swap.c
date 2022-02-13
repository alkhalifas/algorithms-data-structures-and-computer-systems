// Write a C program that swaps two integers in a function
#include <stdio.h>

void swap(int *ap, int *bp){

    int temp;
    temp = *ap;
    *ap = *bp;
    *bp = temp;

}

int main() {
    
    int a = 5;
    int b = 10;
 
    //printf("a = %d\n", a);    
    //printf("b = %d\n", b);    
    
    swap(&a, &b);
 
    //printf("a = %d\n", a);    
    //printf("b = %d\n", b);    
    return 0;
}
