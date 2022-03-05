# TODO Please edit the following information in your assignment

- Name: Saleh ALkhalifa
- How many hours did it take you to complete this assignment? Quite a few, I had to spread this across many days (more than 10-12 hours)
- Did you collaborate with any other students/TAs/Professors? Juan answered a few questions on Piazza
- Did you use any external resources? (Cite them below)
  - [Shells in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
  - [Reversing a linked list](https://www.geeksforgeeks.org/reverse-a-linked-list/)
  - [Fork in C Language](https://www.section.io/engineering-education/fork-in-c-programming-language/)
- (Optional) What was your favorite part of the assignment? I really enjoyed creating a shell in general! It was alot of fun.
- (Optional) How would you improve the assignment? More guidance on using pipe would be appreciated. I got very lost and confused, and at this point I am OK with losing the 10% because I have no idea why its not working and I would rather spend my time studying for the midterm.

# Logistics

For this assignment (and every assignment/lab), you must login into the servers through `your_khoury_name@login.khoury.neu.edu` to complete and test your work. The reason is the examples I will provide below are compiled strictly for our machines architecture, and this is a consistent architecture where your submission will be graded.

# Part(s) to this assignment!

See the folder [part1](./part1/)

# Rubric

 <table>
  <tbody>
    <tr>
      <th>Points</th>
      <th align="center">Description</th>
    </tr>
     <tr>
      <td>100% for completing Part 1 Task 2 - Mini-Shell (rough rubric below)</td>
      <td align="left"><ul><li>20% 1 Built-in history command (and documentation in README.md)</li><li>10% A working signal handler</li><li>40% A shell that runs forever and has the 'mini-shell>' prompt and properly parses programs.<ul><li> You should avoid <a href="https://en.wikipedia.org/wiki/Fork_bomb">fork bombs</a>. As you are learning the fork command, it will be helpful to test on virtual box as opposed to the Khoury servers. :)</li></ul></li><li>20% Can successfully execute processse in the foreground.<li> 10% for a working pipe.<ul><li>Note: I notice a lot of students spend a great deal of time on pipe early on and get stuck. Leave this towards the end, it's worth 10% of the grade, and perhaps the most challenging part of the assignment.</li></ul></li></li></ul></td>
    </tr>
  </tbody>
</table>

### Important notes

* Note: Your code **must** compile and run on the Khoury machines. Make sure you test your programs on these machines, as this is where we grade your assignments.
* Note: You must commit any additional files(if any) into your repository so we can test your code.
  * Points will be lost if you forget!
* And do not forget, if we do not see your most recent changes 'pushed into this repository' (i.e. what you see on github.com), then we cannot grade them. Updates to the repository must be before the assignment deadline!
