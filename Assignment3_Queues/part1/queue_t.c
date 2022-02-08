#include "queue_t.h"
#include <stdlib.h> // malloc/free

// Create a queue
queue_t* create_queue(unsigned int _capacity){
    
    // Create a new queue and set size using malloc
    queue_t* newQueue = (queue_t*)malloc(size_of(queue_t));

    // Set the back, front, size, capacity, and data
    newQueue->back = _capacity - 1;
    newQueue->front = 0;
    newQueue->capacity = _capacity;
    newQueue->size = 0;
    newQueue->data = 0;

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
		return -1; // Note: you should have two return statements in this function.
}

// Dequeue an item
int queue_dequeue(queue_t *q){

		return 99999; // Note: This line is a filler so the code compiles.
}


// Queue Size
unsigned int queue_size(queue_t* q){
	return 0;
}


// Free queue
void free_queue(queue_t* q){

}
