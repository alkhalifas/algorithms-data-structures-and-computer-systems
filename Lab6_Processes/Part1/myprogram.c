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

    // Set up first command
    myArgv1[0] = "/bin/ls";
    myArgv1[1] = NULL;

    // Set up second command
    myArgv2[0] = "/bin/echo";
    myArgv2[1] = "'I love Lady Gaga!'";
    myArgv2[2] = NULL;

    // Set up third command
    myArgv3[0] = "/bin/nl";
    myArgv3[1] = "example5.c";
    myArgv3[2] = NULL;

    // Create list of commands
    char** myCommands[] = {myArgv1, myArgv2, myArgv3};

    // Print results
    printf("###############################################################\n");
    printf("############################# Starting ########################\n");
    printf("###############################################################\n");

    // Iterate over list of 3 commands
    int i;
    for(i = 0; i < 3; i++){
        // Add fork conditional
        if(fork() == 0) {
            printf("###################### RUNNING PROCESS %d #####################\n", i);
            // Call execute program command
            execve(myCommands[i][0], myCommands[i], NULL);
            exit(1);
        } else {
            wait(NULL);
        }
    }
    printf("###############################################################\n");
    printf("############################ Completed ########################\n");
    printf("###############################################################\n");
  
    return 0;
}











