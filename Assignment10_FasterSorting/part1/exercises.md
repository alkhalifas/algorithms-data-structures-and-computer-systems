**Instructions** 

- Discuss and answer the following questions (Make sure to elaborate and justify your responses):
- If you would like to hand write or draw your answers, then scan or take a picture of a file called exercises.pdf or exercises.png and put it in this directory.


# Exercises

1. Explain: Take a moment and write down the intuition as to what the Big-O (worst-case) complexity of the merge sort algorithm is and why? 

*We can explain this based on the logic behind mergeSort. The algorithm operates by dividing a given array into two using the midpoint and calling mergeSort in a recursive fashion on each of the individual arrays. This process accounts of O(log(n)). On the other hand, the process of merging the subarrays together in a correct order is O(n) since it depends on the number of elements in the array. Therefore, we arrive at O(nlog(n)) is the final Big-O complexity.*

2. Explain: What do you think the best-case complexity of the merge sort algorithm is and why?

*Within the confines of how the algorithm works, I would assume that the best, worst, and average cases are going to be the same with a big-o notation of O(nlog(n)), because of the fact that the splitting and merging is done regardless of whether the list is sorted or not. So theoretically you would have the same complexity of a sorted or unsorted list using this algorith.*

3. Does merge sort require any additional storage beyond the original array? If so how much and why? Make sure to answer in regards to Big-O.

*Yes, unlike some of its other counter parts, this algorithm requires additional storage for the subarrays created after each array is split in half. The space complexity within the confines of this question is likely going to be O(n).*

4. How much time in Big-O does it take to merge all of the subarrays together? Explain or draw why?

*Ultimately the Big-O for merging all the arrays together will be O(n), and this is because of the number of elements included in the array. As the array is split into multiple subarrays. This is because merging is dependent on the number of elements, n, as seen in the diagram below:*


<img src="./media/Capture.JPG"/>



## Interview Prep (Optional +1% Bonus on assignment)

> **Rules** 
> 
> This is for bonus--and you may not ask TA's, Professors, or anyone about the question until after the homework is due.
> 
> Stratigically, you should not attempt this problem until you complete the rest of the homework (1% is less than 100% :) )

A bit ago a student asked me about this course, CS 5800, and other courses and how they may prepare you for interviews. I was recently talking to a Google, now Microsoft Engineer who told me that the reality is having a lot of LeetCode practice will truly help folks beyond an algorithms course. LeetCode is a website to practice solving algorithmic challenges. (Some advice: At some point in your CS career, before either your co-op search or full-time job serach, it will be worth it to practice some problems. Often this is easier to do with a study group, even if it's 1 or 2 problems a week. Point your friends to this text in the future, and form a study group!)

Let's finish off this exercise with a small C programming sample.

###

Solve the following: https://leetcode.com/problems/merge-sorted-array/

**Copy and paste your code into** a file in this directory called [challenge.c](./challenge.c) that solves the following problem.

**Given:** Two sorted integer arrays `nums1` and `nums2`, merge nums2 into nums1 as one sorted array and return the sorted array as a new array.

The number of elements initialized in `nums1` and `nums2` are *m* and *n* respectively.

Example 1:

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

Example 2:

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

Constraints:

```
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
```
