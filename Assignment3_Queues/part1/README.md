# Building Data Structures - Queue
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/450px-Data_Queue.svg.png" alt="Queue picture">

We have previously learned about Linked Lists and array data structures. Now we will introduce another data structure, known as the 'queue'.

A 'queue' data structure is analogous to waiting in line at a grocery store. The first person to the checkout counter is served, followed by the next person, and then the next until the line is empty. A queue is what is known as a 'first-in first-out' (FIFO) data structure. Thus queues have a strict policy about how information is stored and accessed.

For this assignment, you are going to implement a specific implementation of a queue using an array in the [queue_t.c](./queue_t.c) file. This data structure is also called a circular queue (specifically a ring buffer when the maximum storage size is fixed).

## Part 1 - Queue implementation as an array (Ring Buffer).

A circular buffer has a fixed sized, or maximum number of elements that it can hold. This is advantageous if we know how many elements are typically stored in a data structure (If we do not know, then a queue with a linked list implemetation is needed so we can expand the queue). 

For more information on the Circular buffer, see here: https://en.wikipedia.org/wiki/Circular_buffer

This animation below gives an idea about how the data structure 'wraps' around. Think about what mathematical operator has a *wrap around behavior* that could be useful in your implementation when enqueuing and dequeuing items in your queue (*hint* this operator will save you from writing many if-statements in your code!).

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)

**Your task** will be to implement the functions in the [queue_t.c](./queue_t.c) to have a working implementation of queue.

## Part 2 - What is a file that ends in .h.

A file that ends in .h is known as a header file. A header file typically is a file that contains an 'interface' for a set of functions to perform some task. The actual implementation (i.e. the loops, if-statements, arrays, and tools that do work) are found in a .c file. 

For this assignment, our 'queue_t' "library" of functions is quite small, but we will still use good programming practice and have an implementation file(.c) and an interface(.h) as you would see in real world codebases. It can be useful to first look at the header file(.h) and use the header file as documentation to get a high level overview of the data structure. You'll notice in the header file(.h) I have included the actual comments that would be important for a client to see if they were to use this data structure.

* More information on header files
	* https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html

## Part 3 - Why is a ring buffer/circular queue useful?

Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and edit this section of the readme answering specifically: Why is a ring buffer useful and/or when should it be used?

# TODO: Put your answer in this file here

[edit the exercise.md file](./exercise.md)


# Unit Tests

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working queue implementation. A sample unit tests is given in [queue_test.c](./queue_test.c):

```c
void unitTest1(){
	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
}
```

You *may* also consider writing some unit tests to test your implementation (In fact, I would strongly encourage you to do so). Note that you can include your unit tests in your submission, and we will have our own test suite. Some example tests we might come up with include:

* Fill a queue, empty the queue, and fill the queue again.
* Create an empty queue and attempt to add something to it.
* Make sure your queue does not overwrite any data.
* etc.

## Provided Tests

You are provided a file called [queue_test.c](./queue_test.c) which you can compile separately and test your implementation of your queue functions from your header and implmentation file. Doing so does not guareentee a perfect assignment, but it will give you some confidence your implementation is working.

* Compile: `gcc queue_t.c queue_test.c -o prog`
* Run: `./prog`


# Resources to help

- This is a nice interactive tutorial for learning C
  - http://www.learn-c.org/
- Queue Data Type High level description
  - https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
  
# Going Further
(An optional task to extend this assignment--not for bonus, but just for fun)

* Add additional functions like:
  * queue_peek - Returns the first value in the queue
  * queue_back - Returns the last value in the queue
  * queue_equals - Checks if two queues are equal
  
  
* Information on pros/cons of our header only design
	* https://softwareengineering.stackexchange.com/questions/305618/are-header-only-libraries-more-efficient
* Some examples (Revisit this again in a few weeks)
	* https://github.com/nothings/single_file_libs  
  
# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

- Investigate/Review more data strutures on this webpage: https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
  - There are visuals for the linked list and array based queue here!
  - Use them as a *rough* guide for the basic concepts. Do make sure to follow the specifications for our assignment above.

