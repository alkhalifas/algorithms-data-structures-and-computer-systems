#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    alarm(180); // Please leave in this line as the first statement in your program.
	        // This will terminate your program after 180 seconds,
	        // and is useful in the case that you accidently leave a bunch of running proceses.

    // Variable to store the process id
    pid_t pid;
    // Variable 'x' allocated on the stack
    int x = 1;

    // pid returns the child process id.
    // 0 if it is the child
    // >0 is the process id of the child which the parent recieves
    pid = fork();

    // Observe this time that the child runs in an infinite loop.
    if(pid==0){
    	printf("Running child forever now pid=%d\n",getpid());
    	while(1){
		// Work would be done here.
    	}
    }else{
	// Run the parent, and then shortly terminate it.
	printf("Terminating parent pid=%d\n",getpid());
	exit(0);
    }

	return 0;
}
