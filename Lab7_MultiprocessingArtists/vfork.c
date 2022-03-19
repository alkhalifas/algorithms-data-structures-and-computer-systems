// Implement your part 1 solution here
// gcc vfork.c -o vfork

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Canvas represented by 64 rows x 64 columns, with
// each pixel storing 3 color components (RGB)
int colors[64][64*3];

// Paint function that takes a workID and paints along
// that IDs row while iterating over the columns
void paint(int workID) {
    
    // Print artistID
    printf("Artist %d is painting\n", workID);

    // Iterate over the columns, assign value
    int i;
    for(i = 0; i < 64*3; i++){

        //printf("--------------------------\n");
        //printf("colorInfo %d ->> %d\n", i, rand() % 255 + 1);
        //printf("--------------------------\n");
        
        // Check if even or odd
        if(workID % 2 == 0){
            // If Even, color randomly
            colors[workID][i] = rand() % 255 + 1;
        } else {
            // If Odd, color black
            colors[workID][i] = workID;
        }
    }
}

// Saves the PPM file
void savePPM(){

    FILE *fp;
    fp = fopen("vfork.ppm", "w+");
    fputs("P3\n", fp);
    fputs("64 64\n", fp);
    fputs("255\n", fp);
    
    int i;
    int j;

    for(i = 0; i < 64; i++){
        for(j = 0; j < 64*3; j++){
            fprintf(fp, "%d", colors[i][j]);
            fputs(" ", fp);
        }
        fputs("\n", fp);
    }
    fclose(fp);

}

// Main call that executes the program
int main() {

    // Select number of artists, which correspond to
    // child processes in the program
    int numberOfArtists = 64;
 
    // Variable to store the process IDs
    pid_t pid;
    
    // Iterate over the number of artists or processes 
    // selected and fork
    int i;
    for(i = 0; i < numberOfArtists; i++){
        
        // Perform a fork
        pid = vfork();
        
        // Print PID
        //printf("PID is: %d\n", pid);
        
        // Call paint then exit
        if(pid == 0) {
            paint(i);
            exit(0);
        }
       
        printf("Child process created: %d\n", pid);
    }
    printf("Masterpiece(vfork.ppm) is being assembled\n");
    
    savePPM();

    return 0;
}
            
