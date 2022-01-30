#include <stdlib.h>  // Include for malloc/free and NULL

#include "stack_t.h" // Include our function declarations and data types


// Creates a stack
stack_t* create_stack(unsigned int capacity){
	// Modify the body of this function as needed.
	stack_t* myStack = (stack_t*)malloc(sizeof(stack_t));	
	myStack->count = 0;
	myStack->capacity = capacity;
	myStack->head = NULL;
	return myStack;
}

// Stack Empty
int stack_empty(stack_t* s){
	if(s->head == NULL){
		return 1;
	} else {
		return 0;
	}
}

// Stack Full
int stack_full(stack_t* s){
	if(s->count == s.capacity){
		return 1;
	} else {
		return 0;
	}
}

// Enqueue a new item
int stack_enqueue(stack_t* s, int item){
i	if(s->count == s.capacity) {
		return -1;
	} else {
		node_t* newNode = (node_t*)malloc(sizeof(node_t));
		newNode->data = item;
		newNode->next = s->head;
		s->head = newNode;
		s->count++;
		return 0;
	}
}

// Dequeue an item
int stack_dequeue(stack_t* s){

		return 9999999; // Note: This line is a 'filler' so the code compiles.
}

// Stack Size
unsigned int stack_size(stack_t* s){
	return 0;
}

// Free stack
void free_stack(stack_t* s){

}



