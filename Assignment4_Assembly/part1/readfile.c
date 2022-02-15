#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* myFile;

    myFile = fopen("./barebones.s", "r");

    if(NULL == myFile) {
        fprintf(stderr, "barebones.s not found\n");
        fprintf(stderr, "note: stderr argument means we write to a special 'error' output stream. \n");
        fprintf(stderr, "Program terminating now...\n");
        exit(1);    
    }

    char buffer[255];

    while(fscanf(myFile, "%s", buffer) != EOF){
        printf("Token: %s\n", buffer);
    }

    fseek(myFile, 0, SEEK_SET);
    while(fgets(buffer, 255, myFile)){
        printf("Line: %s", buffer);
    }
    
    fclose(myFile);
    
    
    return 0;
}


