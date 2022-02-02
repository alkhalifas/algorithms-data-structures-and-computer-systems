# Lab C Strings

> "There's no 'string' data type in C"

## Introduction

One of the things that I admire about the C Programming language is how concise the language is. The language and most of its features can be learned in a day. The simplicity comes at a trade off however, in the sense that we do not have a lot of the built-in data structures or data types that you may enjoy in other languages like Java or Python. One notable thing that is missing, is a data type for a 'String'. That said -- even though a native 'String' data type is missing, we do not need anything more than an array of characters to work with strings in C.

## C-Strings

Recall in C that strings are null-terminated character arrays. The simplicity of working with strings makes them quite nice, as we can quickly understand how to work with c-strings. That said, the simplicity also means that we will have to write some functions or otherwise pay careful attention to the operations that we perform with C-Strings. C-Strings themselves are a great example of how to think about the C programming language, a langauge for laying out 'data' in memory--often 1 byte at a time.

```c
// Compile code:
// gcc -Wall -g strings1.c -o prog
// Run Code:
// ./prog

#include <stdio.h> // I/O functions

int main(){

    char name[5];
    name[0] = 'M';
    name[1] = 'i';
    name[2] = 'k';
    name[3] = 'e';
    name[4] = '\0';

    printf("name = %s\n",name);

    return 0;
}
```


## String Literals

While there are no built-in types for 'strings' in C, there is a difference between a character array, and what is known as a 'string literal'. String literals allow us to initialize a string with a sequence of characters. The actual characters (in the example below "mike" and "john" for example) cannot be changed. That is, the contents of a string literal cannot be changed, because they are stored in read-only memory.

Note: We can always change where the pointer (cstring1, and cstring2) actually point however.

```c
// Compile code:
// gcc -Wall -g strings6.c -o prog
// Run Code:
// ./prog

#include <stdio.h> // I/O functions

int main(){
    
    // This creates a 'string-literal'
    // - cstring is a pointer to other characters.
    // - a null-terminator is automatically applied
    // - But, 'string-literals' cannot be changed.
    // - We can however, change where the 'pointer'
    //   points however.
    char* cstring1 = "mike";
    char* cstring2 = "john";

    printf("cstring1: %s\n",cstring1);
    printf("cstring2: %s\n",cstring2);

    // Change what cstring2 'points' to
    // so that it points to the same
    // piece of memory.
    cstring2 = cstring1;
    printf("cstring1: %s\n",cstring1);
    printf("cstring2: %s\n",cstring2);
    
    return 0;
}
```


## #include <string.h>

The C-library itself comes with many functions that allow you to manipulate character arrays. For this lab, you will be implementing several of the string library functions from scratch (what better way to learn them!). You will implement in the [mystring.c](./mystring.c) file the behaviors of the program.

You can then run your program against the 'interactive' unit test selector program.

Compile with: `gcc -g main.c mystring.c -o prog`
Run with: `./prog`

Note: This time there is a new flag `-g` with the compile command. This will allow you to compile your program with debugging symbols, and use a debugger like GDB. We will be learning GDB in lecture/recitation shortly to help with this lab and future assignments.

## More on the string functions

You may notice with the string functions in C (and as you search the internet)--they are notoriously unsafe! The reason is because often we forget things like the NULL byte at the end, and functions will print 'random' contents of memory (which could contain sensitive information). As you research the string functions, you will notice their are string.h functions with an 'n' in the middle, denoting the number of 'bytes' an operation should take. This is a safety check, and can help allow you to use strings more safely.

# Deliverable

- An implementation of the file [mystring.c](./mystring.c):
	- It should match the functionality of the strings.h functions and pass the associated unit tests.

# Resources to help

- [Your Fifth Day in C (Understanding C Strings) - Crash Course in C Programming](https://www.youtube.com/watch?v=v6YrooR5fII&list=PLvv0ScY6vfd8M-Mi_Vyrg7KgISTW3Sklt&index=5)
- [https://www.tutorialspoint.com/cprogramming/c_strings.htm](https://www.tutorialspoint.com/cprogramming/c_strings.htm)
- [http://www.cplusplus.com/reference/cstring/](http://www.cplusplus.com/reference/cstring/)


# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

* (Optional for fun) Take a look at the included [optional](./optional) folder for an optional exercise.
