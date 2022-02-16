// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void printResults(int matchArrayCount[], char *matchArray[], int matchArrayCycle[]){

    printf("#######################################\n");
    printf("#############  Results: ###############\n");
    printf("#######################################\n");

    int totalInstructions = 0;
    int totalCycles = 0;

    int i;
    for(i = 0; i < 9; i++) {
        if(matchArrayCount[i] != 0){
            printf("######  %s = %d\n", matchArray[i], matchArrayCount[i]);
            totalInstructions++;
            totalCycles = totalCycles + (matchArrayCount[i] * matchArrayCycle[i]);
        }
    }
    printf("#######################################\n");
    printf("###### Total Cycles = %d\n", totalCycles);
    printf("###### Total Instrs = %d\n", totalInstructions);
    printf("#######################################\n");
}




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

    // Set Cycle Counts
    int matchArrayCycle[9];
    matchArrayCycle[0] = 1;
    matchArrayCycle[1] = 1;
    matchArrayCycle[2] = 2;
    matchArrayCycle[3] = 4;
    matchArrayCycle[4] = 1;
    matchArrayCycle[5] = 1;
    matchArrayCycle[6] = 1;
    matchArrayCycle[7] = 1;
    matchArrayCycle[8] = 1;
    
    // Set Instruction Names 
    char *matchArray[9];
    matchArray[0] = "add";
    matchArray[1] = "sub";
    matchArray[2] = "mul";
    matchArray[3] = "div";
    matchArray[4] = "mov";
    matchArray[5] = "lea";
    matchArray[6] = "push";
    matchArray[7] = "pop";
    matchArray[8] = "ret";

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

    // Iterate over the lines
    while(!feof(myFile)){
        // Create buffer and set to 255
        char buffer[255];
        
        // Read each line from the file
        fscanf(myFile, "%s", buffer);
        
        // Convert all buffer to lower case
        for(i = 0; buffer[i]; i++){
            buffer[i] = tolower(buffer[i]);
        }

        // Iterate over the instructions
        for(i = 0; i < 9; i++){

            if(strstr(buffer, matchArray[i]) != NULL){

                // If there is a match, increment the matchArrayCount by 1
                matchArrayCount[i]++;
            }
        }
    }

    printResults(matchArrayCount, matchArray, matchArrayCycle);

    fclose(myFile);


    return 0;
}










