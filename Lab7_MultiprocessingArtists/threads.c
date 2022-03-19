// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

# define NTHREADS 64

int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
char COLORS[64][64*3];

// Function to save image
// taken directly from lab documentation
void savePPM() {
    FILE *fp;
    fp = fopen("threads.ppm", "w+");
    fputs("P3\n", fp);
    fputs("64 64\n", fp);
    fputs("255\n", fp);

    int i;
    int j;

    for(i = 0; i < 64; i++) {
        for(j = 0; j < 64*3; j++) {
            fprintf(fp, "%d", COLORS[i][j]);
            fputs(" ", fp);
        }
    fputs("\n", fp);
    }
    fclose(fp);
}

// Paint function
void paint(int workID) {
    printf("Artist %d is painting\n", workID);

    int i;
    // Iterate and assign value
    for(i = 0; i < 64*3; i++){
        // Paint random colors if even
        if(workID % 2 == 0) {
            COLORS[workID][i] = rand() % 256;
        } else {
            // Paint black if ODD
            COLORS[workID][i] = workID;
        }
    }
}

// Function to create thread
void *thread(void *argp) {

    // Lock
    pthread_mutex_lock(&mutex1);

    // Increment
    counter = counter + 1;

    // Unlock
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

// Main Function
int main() {
    // Manage tids
    pthread_t tids[NTHREADS];
    printf("Start Counter: %d\n", counter);
    
    
    printf("|------------- Starting Creating -------------|\n");

    int i;
    // Iterate and create threads
    for(i = 0; i < NTHREADS; i++) {
        pthread_create(&tids[i], NULL, thread, NULL);
        //printf("Created thread %d --> %d\n", i, tids[i]);
        // Paint the image
        paint(i);
    }

    printf("|------------- Moving to Joining -------------|\n");
    
    // Iterate and join threads
    for (i = 0; i < NTHREADS; i++) {
        //printf("Joined thread %d --> %d\n", i, tids[i]);
        pthread_join(tids[i], NULL);
    }
    // Save Painting
    savePPM();
    printf("Final counter: %d\n", counter);

    return 0;
}
