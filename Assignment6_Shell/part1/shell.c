// Modify this file for your assignment
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// Define the buffer as a constant global
// variable (Specification #2)
#define BUFFER 80

// Built-in functions
char* builtInCommands[] = {"cd", "help", "exit"};

// Signal handler for when users click CTRL+C
// for exiting (Specification #3)
void sigint_handler(int sig){
    write(1, "\nmini-shell terminated!\n", 35);
    exit(0);
}


// Exit command (exit)
int exit_command(char** args){
    return 0;
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

// Help (help) Command
int help_command(char** args) {
 
    // Todo: add later   
    return 1;
}

// Pointers for built-in functions
int (*builtInCommandsPtrs[]) (char**) = {
    &cd_command,
    &help_command,
    &exit_command
};


// Get Users Input
char* getUserInput() {
    // Use malloc for the current line
    char* curLine = malloc(BUFFER * (sizeof(char)) + 1);

    fgets(curLine, BUFFER, stdin);
    
    char *newLine = strchr(curLine, '\n');

    if (newLine) {
        *newLine = '\0';
    }
    return curLine;
}


// Parse Users Input
char** parseUserInput(char* userInput) {
    
    char** userArgs = malloc(BUFFER * sizeof(char*));

    char* userArg = strtok(userInput, " \t");

    int i = 0;
    while(userArg) {
        userArgs[i] = userArg;
        userArg = strtok(NULL, " \t");
        i = i++;
   }

   userArgs[i] = NULL;
   return userArgs;
}

// Infinite loop (Specification #1)
void loop(){
    
    // Set up userInput, userArgs:
    char* userInput;
    char** userArgs;

    // Set conditional variable to avoid
    // infinite loops
    int progSuccess = 1;    

    while(progSuccess){
        // Print 'mini-shell' text
        printf("mini-shell> ");
    
        // Parse user input / args
        userInput = getUserInput();
        userArgs = parseUserInput(userInput);

        //progSuccess = eCmd(userArgs);

    }
        
}



// Define the commands to include

int main(){
    // Terminate after 180 seconds
    alarm(180); 
  
    // Signal Handler
    signal(SIGINT, sigint_handler);

    // Print CTRL+C Instruction Warning
    printf("You can only terminate by pressing CTRL+C\n");
    
    // Implement loop
    loop();

    return 0;
}
