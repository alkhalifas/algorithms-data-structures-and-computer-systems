// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>








int main(int argc, char** argv){
    
    // Set counts for each of the instructions
    int matchArrayCount[9];
    matchArrayCount[0] = 0;
    matchArrayCount[1] = 0;
    matchArrayCount[2] = 0;
    matchArrayCount[3] = 0;
    matchArrayCount[4] = 0;
    matchArrayCount[5] = 0;
    matchArrayCount[6] = 0;
    matchArrayCount[7] = 0;
    matchArrayCount[8] = 0;
 
    char *matchArray[9];
    matchArray[0] = "ADD";
    matchArray[1] = "SUB";
    matchArray[2] = "MUL";
    matchArray[3] = "DIV";
    matchArray[4] = "MOV";
    matchArray[5] = "LEA";
    matchArray[6] = "PUSH";
    matchArray[7] = "POP";
    matchArray[8] = "RET";

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
       // printf("LINE: %s", buffer);
        int j;
        for(j=0; j<9; j++){
            char *pch = strstr(buffer, matchArray[j]);
            if(pch) {
                matchArrayCount[j] += 1;
            }
        }
    }
    
    fclose(myFile);


    return 0;
}










