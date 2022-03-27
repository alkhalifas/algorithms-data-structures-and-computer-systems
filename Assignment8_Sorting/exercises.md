# Exercises

Discuss and answer the following questions (Please make sure to elaborate and justify your responses):

1. Explain what do you think the Big-O (worst-case) complexity of this algorithm is? Why?
2. What do you think the best-case (i.e. best case analysis, do a litlte research) complexity of this algorithm is?
   - Provide an example of an array of elements that fit the best-case in your answer below.
3. Does insertion sort require any additional storage beyond the original array? Explain why or why not.
4. What is a 'stable sorting' algorithm? Is insertion sort a 'stable' algorithm, why or why not?

## Answers:

1. *When it comes to Insertion Sort, the worst case complexity is O(n^2) because if the list was in a complete opposite order, the algorithm would need to iterate oer the entire array and compare every element to its neighbour in order to arrive at a sorted list. This double iterative nature is why we would arrive at O(N^2).*
2. *When it comes to Insertion Sort, the best case complexity is O(n), because if the list is already sorted ahead of time, the algorithm would only need to iterate over the array once without actually swapping any elements which is why we arrive at O(n). An example of this could be an array like [0, 1, 2, 3, 4, 5], as opposed to an array like [5, 0, 2, 4, 1, 3].*
3. *No, Insertion Sort is an in-place algorithm, and does not require any additional storage*
4. *Stable Sorting is a case when two adjacent elements in a list are of equal value and remain in the same order. When it comes to Insertion Sort, this is a stable algorithm since when two adjacent elements are of equal value, the algorithm proceeds to the next comparison without any other movements.*
