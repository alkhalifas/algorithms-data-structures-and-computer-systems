# Exercises

In order to start thinking a bit algorithmically, modify this file and answer the following questions. Be sure to add/commit/push any changes made to this file to our repository.

1. In the worst case in our guessing game--how many guesses could it take to get the right number if we had no hint at all? Explain.
2. In the worst case in our guessing game--how many guesses does it take to get the right number if we get a hint of 'higher or lower' when guessing numbers 1-10 **and** guess intelligently (always picking in the middle of the remaining set of numbers) ? *Hint* In your answer show this mathematically with the [log function](https://www.mathsisfun.com/algebra/logarithms.html).

## Answers

1. *Assuming no hints at all, since there are 10 possible options ranging from 1-10 inclusively, I would assume that we would need at least 9 guesses.*
2. *Since there are 10 possible answers, using the hint of higher or lower we can eliminate half the options on each round by selecting the middle value. For example in this an array of 10 options, we can select the middle value, and eliminate half the options. We can do this three more times giving us a total of four guesses. We can show this logarithmically by taking log2(10), in which we arrive at a value of 3.3 Rounding this upwards gets us to a total of 4, which is the total number of guesses needed.*
