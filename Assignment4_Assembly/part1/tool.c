// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>









int main(int argc, char** argv){
    
    // Set counts for each of the instructions
    int addCount = 0;
    int subCount = 0;
    int mulCount = 0;
    int divCount = 0;
    int movCount = 0;
    int leaCount = 0;
    int pushCount = 0;
    int popCount = 0;
    int retCount = 0;

    // Iterate over the args with argv[1] being the file of interest
    int i;
    for (i=0; i< argc; i++) {
        printf("argv[%d] is %s\n", i, argv[i]);
    }
 
    // Open the file using argv[1]
    FILE* myFile = fopen(argv[1], "r");

    // Account for when file is missing or not found
    if(myFile == NULL) {
        fprintf(stderr, argv[1], " not found\n");
        exit(1);
    }

    // Set buffer
    char buffer[255];

    fseek(myFile, 0, SEEK_SET);
    while(fgets(buffer, 255, myFile)){
        printf("LINE: %s", buffer);

    }
    
    fclose(myFile);


    return 0;
}










