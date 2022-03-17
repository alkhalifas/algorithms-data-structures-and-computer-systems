// Implement your part 1 solution here
// gcc vfork.c -o vfork

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int colors[64][64*3];

void paint(int workID) {
    
    printf("Artist %d is painting\n", workID);

    int i;
    for(i = 0; i < 64*3; i++){
        colors[workID][i] = workID;
}

int main() {

    int numberOfArtists = 8;
 
    pid_t pid;
    
    int i;
    for(i = 0; i < numberofArtists; i++){
        
        // Perform a fork
        pid = vfork()

        if(pid == 0) {
            
