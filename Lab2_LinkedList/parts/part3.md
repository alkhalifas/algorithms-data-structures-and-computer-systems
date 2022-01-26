**NOTE** Please make sure you have read through [part1.md - Understanding structs](./part1.md) and [part2.md - Understanding Pointers](./part2.md) first.

# Part 3 - The Linked List - a new data structure!

## Question

> How many students will I have in my class this semester?

^The above question is something I often do not know the answer to! So it becomes difficult for me to just allocate an array of students (i.e. `Student_t class[87]`). Students often add after the deadline for example. Hmm, there must be a better data structure for me to then be able to add students to the course (And why wouldn't you want to add this course--we're learning some cool low level stuff!)

## Review of previous parts

In our previous examples (Part 1) we created a 'struct Student' (or Student_t with the typedef). But often we have many Students in a class, in fact an unknown number (at least at compile-time when we write our code). A powerful tool we have however, is a *pointer*! So using what we learned in Part 2, we could actually create pointers while our program is running, and then link all of the students together as needed. This means we will need to build a new data structure, the linked list.

## The Singly Linked List

The linked list is a data structure that can grow or expand. The way in which linked lists 'change size' is by 'pointing' to other nodes and forming a chain (You can think of this as holding hands with someone next to you, and then them holding hands with someone else next to them, etc.).

Conceptually a linked list is a user-defined data type typically consisting of a 'node_t' that stores some data, and the location of the next node.

(Image from zentut)
<img src="http://www.zentut.com/wp-content/uploads/2013/04/linked-list-node.png" alt="Linked List visual">

From a coding perspective, a *node struct* may look something like this.

```cpp
typedef struct node{ // Note typedef saves us some typing so we do not have to type 'struct' everytime.
    int data;		// 'data' is the actual data we are interested in
    struct node* next;  // 'next' is a pointer to the next node in our linked list
} node_t;	// Here is where the 'typedef' name is specified as 'node_t'
```

Everytime we create a node, we point the 'next' pointer to that node. This stores the location of the next node.

(Image from zentut)
(Note the first node is typically called the 'head' and the end is the 'tail')
<img src="http://www.zentut.com/wp-content/uploads/2013/04/c-linked-list.png" alt="Linked List visual">

Here is one example of connecting together several node_t's and linking them together. 

```cpp
#include <stdio.h>

typedef struct node{
	int myData;
	struct node* next;
}node_t;
  
// Using the struct
int main(){
	
	// (Step 1) ===== Create our Nodes =====
	// Create a first node and assign the field myData to a value
	node_t node1;
	node1.myData = 100;
	// Create a second node and assign the field myData to a value
	node_t node2;
	node2.myData = 200;

	// (Step 2) ===== Linking our Nodes =====
	// Link together the nodes
	// node1 points to the address of node2
	node1.next = &node2;
	// node2 does not have a next node, so set it to 
	// NULL.
	node2.next = NULL;	

	// (Step 3) ===== Do something useful =====
	// ... do some work here

	return 0;
}
```

Note, that we are creating all of our nodes on the stack (i.e. we are not using 'malloc' whic allocates on the heap). 

## Iterator Pattern

So what can we do that is useful now that we have connected all of our nodes? What if we want to traverse (i.e. visit) all of our nodes in order from the start to the end?

We can do so by using an 'iterator' pattern. 

1. We use a temporary node (usually called *iterator* or *iter*) that points to the first node in our chain of nodes.
2. Each iteration we access the data of the node we point to by the 'iterator node_t'.
3. At the end of the loop we update our iterator node_t
	- We point (i.e. reassign) the current `node_t` to node_t.next 
	- We continually do this until the *next* is NULL.

Here is an example you can try to program. 

**TIP on Learning C** This example is a fun one to draw out on paper to understand how it is working. In general, drawing on a piece of paper can help you confirm your understanding of the language.

```cpp
#include <stdio.h>

typedef struct node{
	int myData;
	struct node* next;
}node_t;
  
// Using the struct
int main(){

	// (Step 1) ===== Create our Nodes =====
	// Create a first node and assign the field myData to a value
	node_t node1;
	node1.myData = 100;
	// Create a second node and assign the field myData to a value
	node_t node2;
	node2.myData = 200;

	// (Step 2) ===== Linking our Nodes =====
	// Link together the nodes
	// node1 points to the address of node2
	node1.next = &node2;
	// node2 does not have a next node, so set it to 
	// NULL.
	node2.next = NULL;	

	// (Step 3) ===== Iterator pattern =====
	// Create an iterator node
	node_t* iterator;
	// The iterator needs to point to the first node (i.e. the head of the list)
	iterator = &node1; // Remember iterator is a pointer, so it points to an address(thus 'address of node1')
	
	// Now we want to look through everything, so we will use a loop.
	// While the iterator is not NULL, continue pointing to new things.
	while(iterator != NULL){
		// Print myData, which is the head in the first iteration.
		printf("%d\n",iterator->myData);
		// Then move our iterator to whatever our 'next' node is in the linked list.
		iterator = iterator->next;
		// If our iterator is NULL, this loop terminates.
	}

	return 0;
}
```


