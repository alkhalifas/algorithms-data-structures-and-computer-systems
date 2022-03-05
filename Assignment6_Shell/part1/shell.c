// Modify this file for your assignment
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// Define the buffer as a constant global
// variable (Specification #2)
#define BUFFER 80

// Built-in functions (Specification #6)
char* builtInCommands[] = {"cd", "help", "exit", "print", "history"};

// List of historical commands (Specification #9)
char historicalCommands[100][80];

// Struct for the linked list
//struct Node {
//    char* command;
//    struct Node* next;
//}

// Signal handler for when users click CTRL+C
// for exiting (Specification #3)
void sigint_handler(int sig){
    write(1, "\nmini-shell terminated!\n\n", 35);
    exit(0);
}


// Exit command (exit) to exit program (Specification #6)
int exit_command(char** args){
    return 0;
}

// Print command (p) for debugging purposes
int print_command(char** userArgs) {
    printf("print command!!!");
    return 1;
}


// Change Directory (cd) Command (Specification #6)
int cd_command(char** args) {
    // Null conditional
    if (args[1] == NULL) {
        printf("Please pass an argument!\n");
    } else if (chdir(args[1]) != 0) {
        perror("Error found!");
    }
    return 1;
}

// History (history) Command (Specification #9)
int history_command(char** args) {

    printf("My Command History!\n");

    int i;
    for(i = 0; i < 100; i++){

    printf("Command:   %s\n", historicalCommands[i]);

    }
    return 1;
}

// Help (help) Command (Specification #6)
int help_command(char** args) {
 
    printf(" Help: Some commands you can use:\n");
    printf("     cd      -    to change directories \n");
    printf("     help    -    to see some sample commands \n");
    printf("     exit    -    to exit the mini-shell program \n");
    printf("     history -    to see your previous commands \n");
    printf("     joke    -    to see a random joke! \n");

    return 1;
}

// Pointers for built-in functions (Specification #6)
int (*builtInCommandsPtrs[]) (char**) = {
    &cd_command,
    &help_command,
    &exit_command,
    &print_command,
    &history_command
};


// Get Users Input
char* getUserInput() {
    // Use malloc for the current line
    char* curLine = malloc(BUFFER * (sizeof(char)) + 1);
    
    // Reads line and stores
    fgets(curLine, BUFFER, stdin);
    
    // Use strchr to remove newline '\n' from curLine
    char *newLine = strchr(curLine, '\n');

    //printf("USER INPUT>>> %s\n", curLine);

    // Set to '\0'
    if (newLine) {
        *newLine = '\0';
    }
    return curLine;
}


// Parse Users Input
char** parseUserInput(char* userInput) {
    // Use malloc to allocate memory for the userArgs 
    char** userArgs = malloc(BUFFER * sizeof(char*));

    // Tokenize userArgs to split by space or tab
    char* userArg = strtok(userInput, " \t");
    
    // Iterate over the userArgs
    int i = 0;
    while(userArg) {
        userArgs[i] = userArg;
        userArg = strtok(NULL, " \t");
        i++;
   }
   // Set to NULL
   userArgs[i] = NULL;
   return userArgs;
}

// Run Built-in Commands (cd, exit, help, history)
// and if command is not found, run as non-built-in
// per Specification Requirement #6
int runBuiltInCommand(char** userArgs){
    // Check if there are no arguments from the user
    if (userArgs[0] == NULL) {
        return 1;
    } else {
    
    // Iterate over and execute command with respective arguments
    // from the user
    int i;
    for(i = 0; i < (sizeof(builtInCommands) / sizeof(char*)); i++) {
        if (strcmp(userArgs[0], builtInCommands[i]) == 0) {
            return (builtInCommandsPtrs[i])(userArgs);
            }
        }
    }
   // If its not a built in command, treat as
   // other command and run 
    return runNonBuiltInCommand(userArgs);
}

// Run Non-Built-in Commands
int runNonBuiltInCommand(char** userArgs){
    // Set fork() 
    pid_t pid = fork();
    
    // Conditional for false commands
    if (pid == 0) {
        if (execvp(userArgs[0], userArgs) == -1) {
            printf("Command not found - Did you mean something else?\n");
        }
        // Exit
        exit(1);
    // Else wait
    } else {
        wait(NULL);
    }
    return 1;
}


void historyLogger(char* userInput, int commandCount){
    
    strcpy(historicalCommands[commandCount], userInput);
    printf(">>> COMMAND COUNT : %d\n", commandCount);
    printf(">>> USER INPUT: %s\n", userInput);
    printf(">>> COMMAND LISTED: %s\n", historicalCommands[commandCount]);

}

// Infinite loop (Specification #1)
void loop(){
    
    // Set up userInput, userArgs:
    char* userInput;
    char** userArgs;

    // Set conditional variable to avoid
    // infinite loops
    int progSuccess = 1;    

    // Command Count
    int commandCount = 0;

   

    while(progSuccess){
        // Print 'mini-shell' text
        printf("mini-shell> ");
    
        // Parse user input / args
        userInput = getUserInput();
        
        // History Logger
        historyLogger(userInput, commandCount);
        commandCount = commandCount + 1;
        
        userArgs = parseUserInput(userInput);
        
        //printf(">>>>>>> userInput: %s", userInput);
        progSuccess = runBuiltInCommand(userArgs);

    }       
}



// Define the commands to include

int main(){
    // Terminate after 180 seconds
    alarm(180); 
  
    // Signal Handler
    signal(SIGINT, sigint_handler);

    // Print Welcome and CTRL+C Instruction Warning
    printf("#########################################################\n");
    printf("#####            Welcome to Mini Shell!            ######\n");
    printf("#####  You can only terminate by pressing CTRL+C   ######\n");
    printf("#########################################################\n");

    // Implement loop
    loop();

    return 0;
}
