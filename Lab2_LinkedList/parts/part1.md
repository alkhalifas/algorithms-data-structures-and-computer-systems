# Part 1 - Understanding a struct - Creating Custom Data Types

In this lab we are going to be creating a *singly linked list*. Because we are creating a new data type, we need to use the C programming construct to build a custom data type. That data type is known as a 'struct'. Read on to understand structs.

## Struct basics

A struct is a user defined data type (i.e. You are creating a new type that does not exist natively in C). A struct can store multiple pieces of data, thus we call structs a composite data type . Here is an example of a struct in C:

```cpp
  // The C language keyword 'struct' is followed by our new data type name.
  // We now have a new datatype called 'Student'.
  // Notice how the 'Student' is composed of two primitive types (both ints) to build a new type.
struct Student{
    int age;      // A field called 'age' that holds integer values is stored.
    int userID;   // An additional field 'userID' also holds integer values.
};
  

int main(){
    // The following is an example of using our struct

    // We create a new variable of type 'struct Student' named 'mike'
    // Note the 'struct' keyword is followed by the data type we defined above.
    struct Student mike;
    // We set the fields for our variable 'mike', which were previously not initialized.
    mike.age = 100;
    mike.userID = 123456789;
  
    return 0;
}
```

**TIP on learning C**: If you read the above example, and you have never created a struct before **PAUSE**. Type out the example (creating a 'struct Student') and try to compile the example. See if you can use 'printf' in your example to print out mike's age and userID. 

## struct typedef

If you noticed in our example where we created a student, we had to type `struct Student` which can become cumbersome to type. So we can use another C language keyword to save us some typing. Observe the change on line '3' with the word [typedef](https://www.tutorialspoint.com/cprogramming/c_typedef.htm). Next observe line '6' with 'Student_t'. This gives us a new type name that we can use within our main program, instead of constantly typing out `struct Student mike` we instead type `Student_t mike` to create a new Student_t.

```cpp
  // The C language keyword 'struct' is followed by our new data type name.
  // We now have a new datatype called 'Student'
  typedef struct Student{
    int age;      // A field called 'age' that holds integer values is stored.
    int userID;   // An additional field 'userID' also holds integer values.
  }Student_t;
  
  // Using the struct
  int main(){
    // We create a new struct named 'mike'
    // Note the 'struct' keyword is followed by the data type we defined above.
    Student_t mike;
    // We set the fields for our variable 'mike', which were previously not initialized.
    mike.age = 100;
    mike.userID = 123456789;
  
    return 0;
  }
```

**Note**: Giving our Student type a suffix of `_t` is a standard practice that indicates this is a user-defined type (i.e. a struct)

