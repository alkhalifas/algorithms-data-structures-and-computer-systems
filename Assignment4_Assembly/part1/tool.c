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

            printf("########################################################################################\n");
            printf("----> BUFFER ALL   =  %s \n", buffer);

            int l;
            for(l = 0; buffer[l]; l++) {
                buffer[l] = tolower(buffer[l]);
            }

            printf("----> BUFFER LOWER = %s \n", buffer);

            //printf("----> STRING = %s \n", matchArray[j]);


            if(strstr(buffer, matchArray[j]) != NULL) {
                printf("MATCH!");
                matchArrayCount[j] = matchArrayCount[j] + 1;
            
            }
        
        }
    }

    int k;
    for(k = 0; k < 9; k++){
        printf("TOTAL %s = %d \n", matchArray[k], matchArrayCount[k]);
    }    


    fclose(myFile);


    return 0;
}










