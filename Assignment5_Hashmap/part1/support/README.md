# README

Please see the support code and the support video here: https://youtu.be/gPqDJALdJVQ

- Covers hash map data structure
- partial implementation
- function pointer discussion
- array of lists discussion (node_t**)
- structure of hashmap

## F.A.Q

1. Why did you not realloc for the value in the video?
  - The value is an 'integer' which will always take the same size in memory, thus no need to realloc.
  - If your value is a 'char*'(i.e. C-string) you will need to realloc.
