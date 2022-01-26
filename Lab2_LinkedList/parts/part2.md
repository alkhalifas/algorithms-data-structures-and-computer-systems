# Part 2 - Understanding Pointers

<img src="./../media/pointer.png" align="right" alt="Pointer">

- A pointer is a variable stores an address in memory. 
	- So a pointers value stored is some 'address' (i.e. when you printf a pointer, you'll get a hexadecimal value).
- In English you'll hear us often say 'pointer px is pointing to x'. This means, pointer px, is storing x's a memory address.
	- Take a few moments to try to to understand the picture provided to the right.

Here is an example program you can type out and run to help familiarize yourself with pointers.

```cpp
#include <stdio.h>
  
// Using the struct
int main(){
	// A regular variable	
	int x = 10;
	// A pointer that points to 
	// where 'x' is stored in memory.
	// Think of the data type as 'int*' 
	// (i.e. the asterisk or star is stuck to the data type)
	int* pointer_x = &x;
	// So if we print out the value we should get some
	// address in memory.	
	// (Note: You can google what %p is doing)
	// (	  Why do you think we had to cast the value?)
	printf("pointer_x value: %p\n",(void*)pointer_x);

	// Here we 'dereference' pointer_x to extract the value
	// of the 'thing' it points to. That is, what is the value
	// that exists at its address.
	// Note: We 'dereference' by putting an 'asterisk' in
	// front of the variable name of any variable that is a type of pointer.
	printf("dereferencing pointer_x gives us %d\n",*pointer_x); 

	return 0;
}
```

**ASK YOURSELF**: If a pointer can point to one value, and then point to another, do you think those values can be chained together? Let's read on to see if we can make a new data structure

## Further Resources

If you need some more review on pointers:

- There's a 7 minute chunk of information on pointers here: https://youtu.be/yLNWu6AxftI?t=3081
- I think this resource will be helpful: https://www.youtube.com/watch?v=2R5cjpi9Fzw&t (From about the 3 minute mark to 25 minute mark. Note, the tutorial is in C++, but the first 20 minutes apply to C)
