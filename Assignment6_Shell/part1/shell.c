// Modify this file for your assignment
#include <unistd.h>


int main(){
  alarm(180); // Please leave in this line as the first statement in your program.
              // This will terminate your shell after 180 seconds,
              // and is useful in the case that you accidently create a 'fork bomb'
  
  return 0;
}
