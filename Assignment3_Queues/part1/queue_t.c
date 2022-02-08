#include "queue_t.h"
#include <stdlib.h> // malloc/free
#include <stdio.h>

// Create a queue
queue_t* create_queue(unsigned int _capacity){
    
    // Create a new queue and set size using malloc
    queue_t* newQueue = (queue_t*)malloc(sizeof(queue_t));

    // Set the back, front, size, capacity, and data
    newQueue->back = _capacity - 1;
    newQueue->front = 0;
    newQueue->capacity = _capacity;
    newQueue->size = 0;
    newQueue->data = (int*)malloc(_capacity*sizeof(int));;

    return newQueue; 
}



// Queue Empty
int queue_empty(queue_t* q){
    // check if size equals zero
    if (q->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Queue Full
int queue_full(queue_t* q){
    // Check if size equals capacity
    if (q->size == q->capacity) {
        return 1;
    } else {
	return 0;
    }
}

// Enqueue a new item
int queue_enqueue(queue_t* q, int item){
    // Check if the queue is full using queue_full function
    if (queue_full(q) == 1){
        return -1;
    } else {
        // Adjust size, back, and data 
        q->size = q->size + 1;
        q->back = (q->back + 1) % q->capacity;
        q->data[q->back] = item;
    return 0;
    }
}

// Dequeue an item
int queue_dequeue(queue_t *q){

		return 99999; // Note: This line is a filler so the code compiles.
}


// Queue Size
unsigned int queue_size(queue_t* q){
    if (q == NULL) {
        exit(1);
    } else {
        return q->size;
    }
}

// Free queue
void free_queue(queue_t* q){
    free(q->data);
    free(q);
}

