#include <stdlib.h>  // Include for malloc/free and NULL
#include <stdio.h>   // Included for printf for testing purposes
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
	if(s->count == s->capacity){
		return 1;
	} else {
		return 0;
	}
}

// Enqueue a new item
int stack_enqueue(stack_t* s, int item){
	if(s->count == s->capacity) {
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
	if(s->head == NULL) {
		exit(1);
	} else {
		int removedItem = s->head->data;
		node_t* previousNode = s->head;
		s->head = s->head->next;
		s->count--;
		return removedItem;
	}
}

// Stack Size
unsigned int stack_size(stack_t* s){
	if(s == NULL) {
		exit(1);
	} else {
		return s->count;
	}
}

// Free stack
void free_stack(stack_t* s){
	node_t* previous;
	node_t* iterator = s->head;
	while (iterator != NULL) {
		previous = iterator;
		iterator = iterator->next;
		free(previous);
	}
	free(s);
}

void PrintStack(stack_t* s){
	// Set iterator to the lists head
	node_t* iterator = s->head;
	// Walk through the list and print data
	while(iterator != NULL){
		printf("Data: %d\n", iterator->data);
		iterator = iterator->next;
	}
}
