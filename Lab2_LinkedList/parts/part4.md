# Part 4 - Our task-- Implement a linked list function

Now that you understand a bit more about structs, pointers, and the idea of chaining multiple nodes together, we are ready to build a *linked list*!

**Your task is to**:
- Read the interface for the linked list in [linkedlist.h](./../linkedlist.h).
- I then **strongly** suggest just drawing a linked list on a piece of paper.
	- Draw what you think should happen when you connect a node.
- Build a linked list data structure by completing the implementation in [linkedlist.c](./../linkedlist.c)
- In [main.c](./../main.c) review the unit tests. I **strongly suggest** adding at least one more unit test.
	- e.g.
		- Create a linked list
		- Store at least 10 nodes in the linked list.
		- Print out the linked list
		- Free the linked list without any memory leaks 
			- (You can test this by running your program on Khoury with `valgrind ./prog`
- (Optionally) You can create any helper functions you like (e.g. `node_t CreateNode(int data)`)

## Notes and help on building your first linked list data structure

1. This lab is introdcing a new data structure, and it perhaps is a big enough ramp up that you'll need some assistance.
	- However, I recommend you get started as soon as possible, perhaps working through 1 part each day to break up the work.
	- I am going to **unlock a solution for this lab** on the Jan. 29, 2022 at midnight at the following link: https://youtu.be/v3z38SJuU28d
		- This will give you a few days to try, then you can lean on the solution if needed.
			- Note: The solution will probably only *make sense* to you if you tried to implement it yourself, and also understand Day 1, Day 2, and Day 3 in this series: https://www.youtube.com/playlist?list=PLvv0ScY6vfd8M-Mi_Vyrg7KgISTW3Sklt
		- *Since we are early in the semester*--do not try to take shortcuts and simply copy & paste (in fact you cannot copy & paste because it's a video...). Pause if you get stuck, draw, and take a few notes, and work through one step at a time. Take a look at my lesson if you need, or seek out other resources on pointers, structs, and understanding the linked list data structure.
		- Note: An older walkthrough from a previous iteration of this course may be helpful here on connecting nodes: https://www.youtube.com/watch?v=SB9si64asSk&index=8&list=PLvv0ScY6vfd8qupx0owF78ZcbvySvbWfx 
	

# (Optional) Going Further Task:

(This is an ungraded task--only work on this if you finish the deliverable). You will have to do a little bit of work to figure out how to open and read from files for this task. Generally speaking, this is a self-exercise for folks who want to experiment more.

**In the past** folks have wanted to try out their linked lists out by loading some real world data. You are welcome to do this if you like.

Below is the year and the amount of wins that each year the Red Sox baseball team had (Note for Professor Shah: Cheers for Ohio-based teams). Your goal would be to read this data from a .txt file, and populate a linked list with the following output. 

```
2021, 92 wins
2020, 24 wins (short season)
2019, 84 wins
2018, 108 wins
2017, 93 wins
2016, 93 wins
2015, 78 wins
2014, 71 wins
```

[Red Sox Data source](http://www.espn.com/mlb/history/teams/_/team/Bos) (Add more data if you like)

Your guidelines for this task are:
1. Create a 'node_t' struct that can store the red sox data (it can have type 'node_t' for instance storing wins and the year).
2. Write a function (CreateLinkedList) that creates a Linked list that populates a linked list with the win data. 
	1. It should return a pointer which will be the head of the list.
	2. *Hint* This means within your function you must allocate on the heap.
3. Create a second function (PrintLinkedList) that iterates through the linked list and prints out the data.
	1. The data should be output it in some meaningful way.
	2. Think about what the input parameters should be to the function.
4. Write a third function(FreeLinkedList) that free's your linked list.
	1. This means you are calling 'free' on each node you have malloc'd. Think carefully about how to do this. How will you know this works?
	2. You can try running with the tool 'valgrind' if you get stuck.

**Hints**
- What does this code do? ``` node_t* new_node = (node_t*)malloc(sizeof(node_t));```
- Would it be useful to make a ```node_t* create_node(int data, node_t* next)``` function?
  - You may use the http://www.zentut.com/c-tutorial/c-linked-list/ resource as a reference. Cite sources in your source file if you use them.


## Obtaining some data

Provided within the lab is a shell script (**data.sh**) to obtain some real world data. Provided below are some examples for obtaining some data that we can read in using shell scripts. You can choose whichever data you and your partner like. 

Running the script with `sh data.sh` will bring in the data and save it to a text file or a spreadsheet. You could then read this data into a linked list and display it.

```shell
# Column selector for Red Sox data (prints out index and column name):
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/red_sox_history.csv | awk -F ',' '{ if (NR ==1)  for (i=1; i<=NF; i++){ print i, $i } }

# Win column from Red Sox historical data:
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/red_sox_history.csv | awk -F ',' '{ if (NR > 2)  { print $5 } }' > sox_wins.txt

# An alternative win column selector (Now you know about curl and wget)
wget -O - http://www.mshah.io/comp/Fall18/Systems/Lab/2/baseballdata.csv | cut -d ',' -f 5 | tail -n +2 > data.txt

# There are more public domain texts at the Guttenberg project https://www.gutenberg.org/ 
# Below are some other examples.

# US Declaration of Independence broken up at each comma:
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/usdeclar.txt | awk -F ',' '{ if (NR > 6)  for (i=1; i<=NF; i++) { print $i } }' > doi-segment.txt

# US Declaration of Independence word by word:
curl -s http://www.ccs.neu.edu/home/awjacks/cs3650f18/Labs/2/usdeclar.txt | awk '{ if (NR > 6)  for (i=1; i<=NF; i++) { print $i } }' > doi-word.txt

```

Notes:
- Depending on the data you read in, it may be text or integer based--adapt your function signatures as needed.
