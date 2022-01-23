#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
	
	// Generate pseudo-random number using rand()
	srand(time(NULL));
	int random = rand() %10 + 1;
	
	// GUI Printing
	printf("===============================\n");
	printf(" CPU Says: Pick a Number 1-10: \n");
	printf("===============================\n");

	// Getting User Input
	int userGuess;
	
	printf("Make a guess: ");
	scanf("%d", &userGuess);	
	printf("User Guess: %d\n", userGuess);
	printf("CPUs Guess: %d\n", random);

	// Comparing the Values:
	
	if (userGuess == random) {
		printf("---- Correct!\n");
	} else {
		printf("---- Incorrect!\n");
	}

	return 0;
}
