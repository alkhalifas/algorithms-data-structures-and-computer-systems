# Building Data Structures - Stack
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Lifo_stack.png/350px-Lifo_stack.png" alt="Stack picture">

A 'stack' data structure is analogous to how you might wash dishes at a restaurant. A dirty dish is placed near the sink, and you pick it up to begin washing it. As customers bring in more dirty dishes, they are stacked on top of each other. With this ordering, the newest dirty-dish is placed on the top. This makes a stack a  'last-in first-out' (LIFO) data structure. Thus stacks have a strict policy about how information is stored and accessed.

For this assignment, you are going to implement a specific implementation of a stack using a linked list in the [stack_t.h](./stack_t.h) file.

## Part 1 - Stack implementation as a linked list.

Our stack has two fundamental operations that it can perform:

1. push - Add a new element to the top of the stack.
2. pop  - Remove a single element from the top of the stack.

You will notice, both of these operations (push and pop) happen at *the top of the stack* (Again, to continue our dirty dishes analogy, you can only add or remove dishes on the top of your stack). Sometimes, we also refer to the operations 'push and pop' as 'enqueue and dequeue' so we have a consistent langauge for our data structures.

Our stack that we are implementing can expand dynamically, thus a linked list is a good foundational data struturre to use in our implementation.

Additional notes on our [stack_t.h](./stack_t.h):

- Our stack can push elements onto it, until `MAX_DEPTH` is reached. 
	- MAX_DEPTH is something that we have arbitrarily defined as 32 for our implementation. 
	- Remember however, we only have a finite amount of memory on our systems, so if we had very large stacks that allocated lots of memory on the heap, we could run out of memory! 
	- (Note: A related problem when we run out of 'stack memory' when allocating variables automatically is called a  [stack overflow](https://en.wikipedia.org/wiki/Stack_overflow).)

For more information on the stack, see: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

**Your task** will be to implement the functions in the [stack_t.c](./stack_t.c) for the data type stack_t and have a working implementation of stack_t.

## Part 2 - Implementation detail -- What is a file that ends in .h.

A file that ends in .h is known as a header file. A header file typically is a file that contains an 'interface' for a set of functions to perform some task. The actual implementation (i.e. the loops, if-statements, arrays, and tools that do work) are found in a .c file. 

For this assignment, our 'stack_t' "library" of functions is quite small, but we will still use good programming practice and have an implementation file(.c) and an interface(.h) as you would see in real world codebases. It can be useful to first look at the header file(.h) and use the header file as documentation to get a high level overview of the data structure. You'll notice in the header file(.h) I have included the actual comments that would be important for a client to see if they were to use this data structure.

* More information on header files
	* https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html

### Note: Stack memory versus stack_t the data structure

(This is an aside, but I want to tie in the 'computer systems' concept for you. This may also motivate to you why a stack is such an important data structure!)

We have (or will soon) talked about 'stack memory' in this course. Stack memory is where variables are stored when we initialize them between a set of {}'s (i.e. the block scope). A 'stack' data structure could be used thus to 'pop' off all of the memory that we have allocated within the {}'s. This is a very efficient and fast operation to push and pop off memory from the stack, and ensures that we can reuse some of that memory later on!

So remember, whenever you are creating a local variable (i.e. something between curly braces), that is temporary storage (pushed onto a stack), and that storage will be lost (i.e. popped off the stack) when your variable goes out of scope.

## Part 3 - Why is a stack a useful data structure?

We are going to see stacks and the stack data structure several times in this course. Stacks will be important to understand, but I think it will be useful for you to also explore *the great Internet* and practice doing a little outside research. [Edit the exercise.md file answering](./exercise.md): Why is a stack a useful data structure and/or when do you think it could be used(i.e. to solve a particular problem or in a specific context)?

# TODO: Put your answer in this file here

[edit the exercise.md file](./exercise.md)

# Unit Tests

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working stack implementation. A sample unit tests is given and more are provided in [stack_test.c](./stack_test.c):

```cpp
void unitTest1(){
	stack_t* test1 = create_stack(MAX_DEPTH);
	printf("Attempting to add %d\n",1);
	stack_enqueue(test1,1);	
	printf("Removing: %d\n",stack_dequeue(test1));	

	free_stack(test1);
}
```

You *may* also consider writing some unit tests to test your implementation (In fact, I would strongly encourage you to do so). Note that you can include your unit tests in your submission, and we will have our own test suite. Some example tests we might come up with include:

* Fill a stack, empty the stack, and fill the stack again.
* Create an empty stack and pop an item to add something to it.
* etc.

## Provided Tests

You are provided a file called queue_test.c which you can compile separately and test your implementation of your queue functions from your header file. Doing so does not guareentee a perfect assignment, but it will give you some confidence your implementation is working.

* Compile: `gcc stack_test.c stack_t.c -o prog`
* Run: `./prog


# Resources to help

- This is a nice interactive tutorial for learning C
  - http://www.learn-c.org/
- Stack Data Type High level description
  - https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
  
# Going Further
(An optional task to extend this assignment--not for bonus, but just for fun)

* Add additional functions like:
  * stack_peek - Returns the top value of the stack (without removing it)
  * stack_equals - Checks if two stacks are equal
  * You are also welcome to add any helper functions that you like to help you complete the assignment.
  	* (Do not however change any of the provided functions signatures)
  
  
* Information on pros/cons of our header only design
	* https://softwareengineering.stackexchange.com/questions/305618/are-header-only-libraries-more-efficient
* Some examples (Revisit this again in a few weeks)
	* https://github.com/nothings/single_file_libs  
  
# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

- Investigate/Review more data strutures on this webpage: https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
  - There are visuals for the linked list and array based stack here!
  - Use them as a *rough* outline for the genearl concept. Do make sure to follow the specifications above.

