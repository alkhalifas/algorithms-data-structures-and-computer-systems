// Modify this file for your assignment
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

// Define the buffer as a constant global
// variable (Specification #2)
#define BUFFER 80

// Built-in functions (Specification #6)
char* builtInCommands[] = {"cd", "help", "exit", "print", "history", "joke"};


// List of last 100 historical commands (Specification #9)
char historicalCommands[100][80];
int globalCommandCounter = 0;

// Array of jokes
char* jokeArray[] = {
    "99 little bugs in my code, 99 little bugs, take one down, patch it around, 2200 bugs in my code",
    "Eight bytes walk into a bar. The bartender asks 'what can i get you?' and the bytes reply 'can you make us a double?'",
    "How many programmers does it take to change a light bulb? None, thats a hardware problem",
    "Debugging: Its being the detective in a crime movie where you are also the murderer",
    "What is a programmers favorite type of coffee? Java",
    "Big tech is the only industry where the interview is significantly harder than the job itself",
    "Roses are red, violets are blue, unexpecteed '{' on line 32",
    "Sometimes I wish my life was a GitHub repo where I can revert to the last stable version",
    "Me on monday morning: no email has ever found me well!",
    "I hate programming, I hate programming, I hate programming, OMG it works!, I love programming!",
    "Teacher: How much is 0.1 apples + 0.2 apples? JavaScript: 0.300000000000000004"
};

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

// History (history) Command (Specification #9) that prints historical commands
// chronologically, the most recent command at the end of the output
int history_command(char** args) {
    // Greet user
    printf("My Command History!\n");
    
    // Iterate over the list of commands, up until the last one
    int i;
    for(i = 0; i < globalCommandCounter; i++){
            printf("Command:   %s\n", historicalCommands[i]);
    }
    return 1;
}

int joke_command(char** userArgs) {
    srand(time(NULL));
    int random = rand() %10 + 1;

    //printf("random number %d", random);
    printf("%s\n", jokeArray[random]);
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
    &history_command,
    &joke_command
};


// Get Users Input
char* getUserInput() {
    // Use malloc for the current line
    char* curLine = malloc(BUFFER * (sizeof(char)) + 1);
    
    // Reads line and stores
    fgets(curLine, BUFFER, stdin);
    
    // Use strchr to remove newline '\n' from curLine
    char *newLine = strchr(curLine, '\n');

    // Set to '\0'
    if (newLine) {
        *newLine = '\0';
    }
    return curLine;
   
   // Free curLine
   // free(curLine);
   // free(newLine);
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

   // Free userArgs
   // free(userArgs);
   // free(userArg);
}

// Parse arguments and identofy if there are
// pipes, return index (Specification #5)
int pipeFinder(char** userArgs) {
    
    int i;
    // Iterate over the userArgs, search
    // for the pipe '|' symbol
    while(userArgs[i] != NULL) {
        if (strcmp(userArgs[i], "|") == 0) {
           // Return the number of pipes we found
           //printf("Found a %d pipes.\n", i);
           return i;
        }
        i++;
    }
    return -1;
}

// Isolate the 'Before' part of the pipe, and get
// a list of the arguments
char** beforeArgPipe(char** userArgs) {

}

// Isolate the 'After' part of the pipe and get
// a list of the arguments
char** afterArgPipe(char** userArgs) {

}



// Run Built-in Commands (cd, exit, help, history)
// and if command is not found, run as non-built-in
// per Specification Requirement #6
int runBuiltInCommand(char** userArgs){
    // Check if there are no arguments from the user
    if (userArgs[0] == NULL) {
        return 1;
    } else {
   
    // Check for pipes:
    int numPipes;
    numPipes = pipeFinder(userArgs);

 
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

// A history logger that logs a history of the users inputs in a
// chronological fashion (Specification #9)
void historyLogger(char* userInput, int commandCount){
    
    strcpy(historicalCommands[commandCount], userInput);
    //printf(">>> COMMAND COUNT : %d\n", commandCount);
    //printf(">>> USER INPUT: %s\n", userInput);
    //printf(">>> COMMAND LISTED: %s\n", historicalCommands[commandCount]);

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

    // Keep running while working
    while(progSuccess){
        // Print 'mini-shell' text
        printf("mini-shell> ");
    
        // Parse user input
        userInput = getUserInput();
        
        // History Logger for commands
        historyLogger(userInput, globalCommandCounter);
        globalCommandCounter = globalCommandCounter + 1;
        
        // Parse user Args
        userArgs = parseUserInput(userInput);
        
        // Free Memory
        // free(userInput);
        // free(userArgs);

        // Run with success
        progSuccess = runBuiltInCommand(userArgs);

        // Free memory
        free(userInput);
        free(userArgs);
    }       
}



// Define the commands to include

int main(){
    // Terminate after 180 seconds
    alarm(180); 
  
    // Signal Handler
    signal(SIGINT, sigint_handler);

    // Print Welcome and CTRL+C Instruction Warning
    printf("##########################################################\n");
    printf("######            Welcome to Mini Shell!            ######\n");
    printf("######     You can terminate by pressing CTRL+C     ######\n");
    printf("######      See list of commands using 'help'       ######\n");
    printf("##########################################################\n");

    // Implement loop
    loop();

    return 0;
}
