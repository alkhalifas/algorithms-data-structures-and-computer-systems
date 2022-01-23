#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
	
	// Generate pseudo-random number using rand()
	srand(time(NULL));
	int random = rand() %10 + 1;

	// Record the rounds
	int roundList[5];
	
	// GUI Printing
	printf("===============================\n");
	printf(" CPU Says: Pick a Number 1-10: \n");
	printf("===============================\n");
	

	int rounds = 1;

	while (rounds < 6) {

		int userGuess;
		printf("Make a guess: ");
		scanf("%d", &userGuess);
		
		if (userGuess > random) {
			printf("No Guess lower!\n");
			rounds += 1;

		} else if (userGuess < random) {
			printf("No Guess higher!\n");
			rounds += 1;
		} else if (userGuess == random) {
			printf("You got it!\n");
			break;	
		}
	}

	return 0;
}
