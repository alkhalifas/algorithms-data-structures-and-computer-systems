#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int printResults(int roundList[]) {
	
	printf("=================================================\n");
	printf(" Here are the results of your guessing abilities \n");
	printf("=================================================\n");
	
	int i;
	
	// Iterate over the users guesses and print results
	for (i=0; i<5; i++) {
		printf("Game %d took you %d guesses\n", i, roundList[i]);
	}

	return 0;
}


int main() {
	
	int roundList[5];	
	int round = 0;
	
	// First loop to go through 5 rounds of the guessing game	
	while (round < 5) {
		
		// Generate pseudo-random number between 1 and 10
		srand(time(NULL));
		int random = rand() %10 + 1;
		
		// Start the round with the user
		printf("===============================\n");
		printf("         Round %d / 5          \n", round + 1);
		printf(" CPU Says: Pick a Number 1-10: \n");	
		printf("===============================\n");
		
		int guesses = 0;

		// Second loop until the user guesses correctly		
		while (1) {
			
			int userGuess;
			
			// Get user input
			printf("Make a guess: ");
			scanf("%d", &userGuess);
			
			// Evaluate user input
			if (userGuess > random) {
				printf("No Guess lower!\n");
				guesses += 1;

			} else if (userGuess < random) {
				printf("No Guess higher!\n");
				guesses += 1;

			} else if (userGuess == random) {
				printf("You got it!\n");
				guesses += 1;
				roundList[round] = guesses;
				break;
	
			}
		
		}
		
		// Increment rounds	
		round += 1;

	}

	// Call print results
	printResults(roundList);
	
	return 0;
}
