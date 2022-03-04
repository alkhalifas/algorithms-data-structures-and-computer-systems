// Modify this file for your assignment
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// Define the buffer
#define BUFFER 80

// Built-in functions
char* builtInCommands[] = {"cd", "help", "exit"};

// Signal handler for when users click CTRL+C
void sigint_handler(int sig){
    write(1, "\nmini-shell terminated!\n", 35);
    exit(0);
}


// Change Directory (cd) Command
int cd_command(char** args) {
    // Null conditional
    if (args[1] == NULL) {
        printf("Please pass an argument!\n");
    } else if (chdir(args[1]) != 0) {
        perror("Error found!");
    }
    return 1;
}






// Define the commands to include

int main(){
    // Terminate after 180 seconds
    alarm(180); 
  
    // Signal Handler
    signal(SIGINT, sigint_handler);
    printf("You can only terminate by pressing CTRL+C\n");
    while(1){
        printf("Running forever!\n");
	sleep(1);
    }
  
    return 0;
}
