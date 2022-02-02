#ifndef MYSTRING_H
#define MYSTRING_H

size_t my_strlen(const char* input);

int my_strcmp(const char* src1, const char* src2);

char* my_strchr(const char* src1, int c);

// Note: Our 'string append' is going to be slightly different
//       than 'strcat'. 
//       I would like you to return a 'heap allocated' string
//       that appends both of src1 and src2 into a new buffer
char* my_string_append(const char* src1, const char* src2);

#endif
