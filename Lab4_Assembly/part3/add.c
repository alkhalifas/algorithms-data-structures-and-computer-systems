// Write a C program that calls an add function(long add(long a, long b).
#include <stdio.h>
#include <stdlib.h>


long add(long a, long b) {
    return a + b;
}


int main() {

    long x = 4;
    long y = 6;

    long mySum = add(x, y);

    printf("%d + %d = %d\n", x, y, mySum);

    return 0;
}
