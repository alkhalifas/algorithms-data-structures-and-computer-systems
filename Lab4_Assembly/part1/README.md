# Debugging

> How to debug C Code

# Logistics

You will be learning and practicing some debugging skills. Please work on this on Khoury to ensure you have GDB and Valgrind (pronounced Val-grinn).

# Resources to help

Some additional resources to help you through this lab assignment

**Note** You should be using Linux :) (But I've provided some other resources here for future reference, as you'll use a debugger on every platform).

- For Linux Users
	- [GDB Beginner Masterclass](https://www.youtube.com/watch?v=MTkDTjdDP3c)
- For Mac users	
 	- [My LLDB Debugging tutorial](https://www.youtube.com/watch?v=v_C1cvo1biI) 
 	- A mapping of LLDB to GDB commands: https://lldb.llvm.org/use/map.html
	- [Quick and Dirty LLDB: All you need in 5 minutes.
](https://www.youtube.com/watch?v=3BkEOvI36Ds)
- For Windows users
	- (Same as my gdb tutorial if working on command line)
	- If using Visual Studio try: https://www.youtube.com/watch?v=0ebzPwixrJA

# Description

Debugging is an essential skill for programmers. For this portion of the lab, I want you to explore using a debugger. For some of you this may be the first time using such a tool, so I want you to have some exposure at the least. Debuggers can be a more powerful way to debugging rather than using 'printf' functions everywhere in your code (and while that can also be effective, it is often tedious).

## Task 1 - Debugging

Please watch the first video if you have not previously [GDB Beginner Masterclass
](https://www.youtube.com/watch?v=MTkDTjdDP3c&list=PLvv0ScY6vfd-GGT-aUH31X2yXgBSYXo6t&index=2&)

* Some notes:
	* Compile your program with the '-g' option
	* gdb ./prog 
		* This will run the program
	* gdb ./prog --tui
		* This will run the program and start the Text User Interface (Otherwise, just hit ctrl+x then 1)
    * layout src - This is another way to view the source code from within GDB. 
	* start 
		* Starts your program
	* n or 'next'
		* moves to the next line that is visible
	* s or 'step'
		* Steps into a function
    * f will finish the function you are executing
    * bt - This will give you a trace of your program.
    * p - This will 'print' out a value (e.g. p x)
	* br *function or line*
		* insert a breakpoint
		* 'info breakpoints' will display our breakpoints.
        * 'delete #' will delete an old breakpoint
	* c or 'continue'
		* continues

## Your Task

Now that you have learned a bit about debugging, let's try an exercise. Open the [bug1.c](./bug1.c) program, and try to fix the bug using GDB and any memory leaks using valgrind.

My suggestion to get the maximum value out of this lab, is to compile and run the program, observe the results, and then walk through the program using GDB to uncover the bugs!

### Deliverables

- Commit the fixed [bug1.c](./bug1.c) program
    - Note: The program should properly report the average of 5 total students and have no memory leaks.

# Going Further

What is that, you finished Early? Did you enjoy this assigment? Here are some (optional) ways to further this assignment.

- Try more debugging tutorials

# F.A.Q. (Instructor Anticipated Questions)

- Q: None so far!
	- A: TBD

# Found a bug?

If you found a mistake (big or small, including spelling mistakes) in this lab, kindly send me an e-mail. It is not seen as nitpicky, but appreciated! (Or rather, future generations of students will appreciate it!)

- Fun fact: The famous computer scientist Donald Knuth would pay folks one $2.56 for errors in his published works. [[source](https://en.wikipedia.org/wiki/Knuth_reward_check)]
- Unfortunately, there is no monetary reward in this course :)

