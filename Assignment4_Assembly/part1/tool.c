// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>







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

    // Iterate over the instruction options

    while(!feof(myFile)){

        char buffer[255];
          
        fscanf(myFile, "%s", buffer);
        
        for(i = 0; i < 9; i++){
    
            if(strstr(buffer, matchArray[i]) != NULL){

                printf(">>> FOUND %s in --> %s\n", matchArray[i], buffer);

                matchArrayCount[i]++;
            }

            //printf("No Match for %s  ..\n", matchArray[i]);
            
        }
    
    }

    for(i = 0; i < 9; i++) {

        printf("Total %s = %d\n", matchArray[i], matchArrayCount[i]);

    }


    fclose(myFile);


    return 0;
}










