// Write a C program that swaps two integers in a function
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int temp;
 
    printf("a = %d\n", a);    
    printf("b = %d\n", b);    
    
    temp = a;
    a = b;
    b = temp;
    
    printf("a = %d\n", a);    
    printf("b = %d\n", b);    
    return 0;
}
