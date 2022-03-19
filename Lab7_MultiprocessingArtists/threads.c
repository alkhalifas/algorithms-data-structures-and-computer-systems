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
void savePPM() {

}

// Function to create thread
void *thread(void *vargp) {
    pthread_mutex_lock(&mutex1);
    counter = counter + 1;

    int i;
    // Iterate over COLORS and set
    

    // Unlock
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

// Main Function
int main() {
    pthread_t tids[NTHREADS];
    printf("Start Counter: %d\n", counter);
    
    
    int i;
    for(i = 0; i < NTHREADS; i++) {
        pthread_t thread;
        tids[i] = thread;
        pthread_create(&thread, NULL, thread, NULL);
    }

    int j;
    for (j = 0; j < NTHREADS; j++) {
        pthread_join(tids[j], NULL);
    }

    printf("Final counter: %d\n", counter);

    return 0;
}
