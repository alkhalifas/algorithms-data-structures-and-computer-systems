Below are some brief notes I have written. For full style guides it is useful to see what actual companies are doing. Here is an example of code style conventions: http://google.github.io/styleguide/

# Github conventions

1. Commit your code changes to the repository often, this is best practice.
2. Do not commit your .o file, your executable file, or any other binary to the repository--this is considered bad practice! 
	- In fact, committing any binary file is bad practice! Othere tools have been developed to more efficiently handle revisions of binary files.
4. On Functionality/Style
	1. You should have comments in your code to explain what is going on, and use good style (80 characters per line maximum for example, functions that are less than 50 lines, well named variables, well named functions etc.).

# Code Style Guide

1. [Core C++ Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
	- Living document on best practices in modern C++
2. [Bungie Studios](https://www.bungie.net/en/News/Article/50666) | [Archived Link](https://web.archive.org/web/20210910222942/https://www.bungie.net/en/News/Article/50666)
	- Example of a Game Studios C++ Deadlines. Likely whatever company you work at will have such guidelines somewhere (or otherwise you should perhaps initiate such guidelines to keep the codebase clean).

### Some Quick Tips

1. Do not duplicate code (i.e. Use functions)
2. Typically keep your functions to less than 50 lines.
3. Name your functions and variables consistently. Meaning if you start them with uppercase letters, do so. If you use conventsion such as iMyVariable (the 'i' prefix indiciating an integer as the type), then do so consistently.
4. Write comments liberally. Comments are more useful when they explain 'why' you are doing something. The 'what' is seen from the code.
5. Indent your code for each nested block. This makes the code easier to follow.
