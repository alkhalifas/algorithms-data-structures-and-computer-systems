<img src="./media/list.png">

# Lab 2 - Linked List

> "A first non-trivial data structure"

Data structures are a way for us to store information. Most programming languages come with support for an 'array' data structure for instance. As a reminder, an array is a data structure which stores homogenous datatypes in a contiguous piece of memory. That is a fancy way of saying:

```c
int array1[100];          // This array1 holds strictly integers (Exactly 100 of integers).
unsigned int array2[100]; // This array2 holds strictly unsigned ints (Exactly 100 unsigned integers).
float array3[100];        // This array3 holds strictly floats(Exactly 100 floats).
```

Arrays such as the arrays in the above example are *statically allocated*. That is, at compile-time (before a program is run), we know exactly how much memory is is allocated to the given array (This is calcuated by the size, 100 multipled by the number of bytes needed to store the data type).

Here are some more examples of statically allocated arrays:
```c
int numbers[10];      // 'numbers' is large enough to store exactly 10 integers.
char firstName[15];   // 'firstName' stores up to 15 char's
float piDigits[5000]; // 'piDigits' holds 3.1415....well, up to 5000 digits.
```

Again, the *statically allocated* portion means that there is a fixed number of elements in the arrays. This value is decided when we write our source code and compile it at compile-time. From the example above, we may thus only store the first 5000 digits of pi, or first names that are 15 characters or less.

## What if we do not know the 'fixed-size' that we want to store?

Often however, we do not know how many elements need to be stored, or the number of elements may need to be reduced over time. For this problem, a data structure that can *expand and contract*.

- Expand: This means we could insert new elements to the beginning (i.e. prepend), middle, or end (i.e. append) of our data structure.
- Contract (verb - decrease in size): This means we could remove (i.e. delete) data that we know longer need.

We use data structures that can expand and contract when we do not need to know exactly how many elements we need to store, and being able to contract (i.e. remove elements) means we can save the finite amount of memory on our computers.

For today's lab, we will be implementing a data structure known as the **singly linked list** (Often abbreviated to linked list). This exercise will give you practice with:

1. struct's
2. pointers
3. Building a real data structure

# Parts

The following parts to this lab are presented, and it is suggested to read and complete them in order.

1. [part0.md - ssh and git pull](./parts/part0.md)
2. [part1.md - Understanding structs](./parts/part1.md)
3. [part2.md - Understanding Pointers](./parts/part2.md)
4. [part3.md - The Linked List Data Structure](./parts/part3.md)
5. [part4.md - Implementing a Linked List](./parts/part4.md)
    - [Some notes of interest are found here](./parts/part4.md#notes-and-help-on-building-your-first-linked-list-data-structure).


# Deliverable

- Modify the file called [linkedlist.c](./linkedlist.c) demonstrating an example of a linked list following the guidelines in [part4.md - Implementing a Linked List](./parts/part4.md).

# More resources to help

- C Programming Video Series: https://www.youtube.com/playlist?list=PLvv0ScY6vfd8M-Mi_Vyrg7KgISTW3Sklt
- Structs: https://www.tutorialspoint.com/cprogramming/c_structures.htm
- Pointers: https://www.tutorialspoint.com/cprogramming/c_pointers.htm
- Linked List: http://www.zentut.com/c-tutorial/c-linked-list/ or https://www.cprogramming.com/tutorial/c/lesson15.html
- Typedef: https://en.wikipedia.org/wiki/Typedef
