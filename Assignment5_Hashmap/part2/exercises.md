# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap? Explain.
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer, but justify how your hashing function works.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity when you resize? (Explain why)
4. What is 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. *The average case for hashmaps across all operations will be generally very good. In the cases of Insert, Update, Delete, and Search, we will generally see a cost of O(1) and O(n) for most given hashmaps, depending on the hashfunction. In our particular implementation, we are using strings which changes this perspective a bit. When traversing a string, we iterate over the characters until we reach the null terminator. With that in mind, as we traverse longer strings, we will see the cost of these functions approach O(n) since it depends more on the string length.*
2. *Having never really used hash functions before this assignment, I would like to take a moment to explore a creative alternative based on an assignment I had in CS5004 and propose the use of fibonacci sequencing. In this implementation, we would be going after a form of multiplicative hashing such that **2^W / phi** in which  **w** is the word length, and **phi** is golden ratio (5/3 ~ 1.666). The idea here would be to uniformly distribute the data over the table in an attempt to avoid many collisions.*
3. *In order to resize the hashmap to add more buckets, we would need to iteratively copy over every node in the hashmap to the newly sized hashmap. Since this would depend on the number of nodes we have, the complexity would likely be O(n).*
4. *We can define open addressing as a method of collision resolution. Within the confines of hash tables, one can say that using this method a hash collision can be resolved by probing of which there are multiple types such as linear probing and quadratig probing. Ultimately, the main idea here is to search through an array until a target item is identified. There is a general trade-off based on the method selected; for example, linear probing has the best cache performance but sensitive to clustering.*


