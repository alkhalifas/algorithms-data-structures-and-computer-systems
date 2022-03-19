#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 1000

int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;


void *thread(void *vargp){
    pthread_mutex_lock(&mutex1);
        counter = counter + 1;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}


int main() {
    
    // Store the pthread ID
    pthread_t tids[NTHREADS];
    printf("Counter starts at: %d \n", counter);

    // Create and execute multiple threads
    int i;
    for(i = 0; i < NTHREADS; ++i) {
        pthread_create(&tids[i], NULL, thread, NULL);
    }

    // Create and execute multiple threads
    for(i = 0; i < NTHREADS; ++i) {
        pthread_join(tids[i], NULL);
    }
   
    printf("Final Counter Value: %d\n", counter);
    
    return 0;
    
}
    
