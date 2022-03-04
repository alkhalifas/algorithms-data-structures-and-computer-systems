// Modify this file for your assignment
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// Define the buffer
#define BUFFER 80

// Signal handler for when users click CTRL+C
void sigint_handler(int signal){
	write(1, "\nmini-shell terminated!\n", 35);
}	



// Define the commands to include

int main(){
  alarm(180); // Please leave in this line as the first statement in your program.
              // This will terminate your shell after 180 seconds,
              // and is useful in the case that you accidently create a 'fork bomb'
  
  signal(SIGINT, sigint_handler);
  printf("You can only terminate by pressing CTRL+C\n");
  while(1){
	  printf("Running forever!\n");
	  sleep(1);
  }
  
  return 0;
}
