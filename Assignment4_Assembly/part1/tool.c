// Implement your cycle count tool here.
#include <stdio.h>










int main(int argc, char** argv){
    
    int addCount = 0;
    int subCount = 0;
    int mulCount = 0;
    int divCount = 0;
    int movCount = 0;
    int leaCount = 0;
    int pushCount = 0;
    int popCount = 0;
    int retCount = 0;





    int i;
    for (i=0; i< argc; i++) {
        printf("argv[%d] is %s\n", i, argv[i]);
    }

    FILE myFile = fopen(argv[1], "r");

    if(myFile == NULL) {
        fprintf(stderr, argv[1], " not found\n");
        exit(1);
    }

    char buffer[255];

    



    return 0;
}










