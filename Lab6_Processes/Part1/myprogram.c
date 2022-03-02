#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Terminate after 180 seconds
    alarm(180);

    // Store up to 16 args
    char* myArgv1[16];
    char* myArgv2[16];
    char* myArgv3[16];
    char* myArgv4[16];

    myArgv1[0] = "/bin/ls";
    myArgv1[1] = "'-l'";
    myArgv1[2] = NULL;

    myArgv2[0] = "/bin/echo";
    myArgv2[1] = "'CS is Awesome!'";
    myArgv2[2] = NULL;

    myArgv3[0] = NULL;

    char** myCommands[] = {myArgv1, myArgv2, myArgv3};

    printf("#################################");
    printf("############ Starting ###########");
    printf("#################################");

    int i;
    for(i = 0; i < 3; i++){
        if(fork() == 0) {
            printf("## RUNNING PROCESS # = %d\n", i);
            execve(myCommands[i][0], myCommands[i], NULL);
            exit(1);
        } else {
            wait(NULL);
        }
    }
    printf("#################################");
    printf("########### Completed ###########");
    printf("#################################");
  
    return 0;
}











