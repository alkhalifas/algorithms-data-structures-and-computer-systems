// Write a C program using a switch statement
#include <stdio.h>
#include <stdlib.h>

int main() {

    char grade = 'B';

    switch(grade) {
        case 'A' :
            printf("Excellent!\n");
            break;
        
        case 'B' :
        printf("Well Done!\n");
        break;
        
        case 'C' :
        printf("Lets try harder next time!\n");
        break;
        
        case 'D' :
        printf("You might need to try again...\n");
        break;
        
        case 'F' :
        printf("Not even close :( \n");
        break;
            
    }

    return 0;
}
