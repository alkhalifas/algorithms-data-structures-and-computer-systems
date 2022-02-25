# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap? Explain.
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer, but justify how your hashing function works.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity when you resize? (Explain why)
4. What is 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. *The average case for hashmaps across all operations will be generally very good. In the cases of Insert, Update, Delete, and Search, we will generally see a cost of O(1) and O(n) for most given hashmaps, depending on the hashfunction. In our particular implementation, we are using strings which changes this perspective a bit. When traversing a string, we iterate over the characters until we reach the null terminator. With that in mind, as we traverse longer strings, we will see the cost of these functions approach O(n) since it depends more on the string length.*
2. *edit your answer here for Part 2 question 1*
3. *edit your answer here for Part 2 question 1*
4. *edit your answer here for Part 2 question 1*


