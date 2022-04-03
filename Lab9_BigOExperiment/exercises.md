Please edit this document below with your responses. Each question is worth 1/8 of your lab.

# Exercise 1

Record here how long it took you to run bubblesort and csort (Note: If you want to run several trials, say '10' and take an average that is an even better result!).

*On average across three trials, the results of Bubble Sort and CSort are as follows:*

*Bubble:*

    real: 0.385s
    user: 0.380s
    sys: 0.003s
    
*CSort:*

    real: 0.008s
    user: 0.007s
    sys: 0.001s


# Exercise 2

What is the Big-O complexity of bubblesort?

*In the best case scenario, Bubble Sort has a complexity of O(n) where n depends on the number of elements being sorted. On the other hand, the averege and worst case complexities are O(n^2) since the algorithm performs O(n) operations on an O(n) number of elements.*

# Exercise 3

Do a little research and discover what algorithm qsort is in the C standard library. What is the algorithm? https://en.wikipedia.org/wiki/Qsort

1. *This qsort algorithm is an implementation of a polymorphic sorting algorithm for arrays, and a derivative of the QuickSort algorithm. An element of this algorithm worth mentioning is the comparison function taht is called which compares two elements, allowing the user to define type, thus expanding its use to many datatypes. Another interesting aspect of quick sort is the use of a pivot, which partitions the array and each partition is then sorted in a similar recursive manner.*

# Exercise 4

What is the Big-O complexity of 'qsort' that we use in the csort program?

1. *When it comes to quick sort, the average complexity is O(nlogn). However, the worst-case complextiy is O(n^2).*

# Exercise 5

Is qsort's Big-O complexity better or worse than bubblesort? (Answer: Yes it is better/ No it is worse/ It is equal)

1. *It depends. From what I have read they appear to be the same assuming we only care about the worst case scenario. If we include the average case scenario as well, then quick sort is better than its bubblesort counterpart.*

# Exercise 6

List the following functions in terms of their Big-O complexity from **smallest** to **largest**.
<img src="./media/bigo.jpg"/>

1. *log(N)   -   N   -   N^2   -   N^3   -   2^N   -   N!*

# Exercise 7

- Given: f(n) = 3n^3 + n^2 + 27
- What is the O(n) of f(n)?

1. *edit your answer here for question 7*

# Exercise 8

- Given: f(n) = 3n^3 + n^2 + 27
- What are two constants c and k that prove your answer in exercise 7.
