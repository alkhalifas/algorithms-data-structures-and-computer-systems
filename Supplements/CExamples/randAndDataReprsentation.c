// The following example shows how to generate some random numbers and also pay careful
// attention to how we cast values to different representations.
//
// Part 1 - Random numbers
//
// There are two key principles with random numbers:
// - srand() which is a function that provides a 'seed' value from
// 			 which we generate random numbers
// - rand()  which generates a random value between 0 and MAX_INT 
// 			 (MAX_INT is however large an integer is that we can represent)
// 
// As an example:
// srand(time(0)) (or sometimes srand(NULL)) gives us a seed at the
// current time. This is fairly random.
//
// rand() % 255 generates some value between 0-255, because the mod operator
// returns some remainder between 0-255.
//
// Part 2 - Data Representation
//
// Remember that in 'C' that it is a 'typed' language. This means we have
// to declare what the type is. This includes even more specifically if
// the number is 'signed' or 'unsigned' (i.e. can we store negative values, or // can we store positive ones too--in fact, twice as many positive numbers 
// since we only have to store positives).
//
// So if there is a difference between sigend and unsigned, we have to be
// a little careful.
// 
// The follow example will demonstrate how we can generate some random numbers
// and then store the value in the correct data type. There is some danger
// when casting, especially if we are going to a representation that cannot
// store the full range of values we are casting too. Too be very explicit,
// see if something happens when we convert to a 'signed char' from an integer
// with a value bigger than '128'. Hmm.
#include <stdio.h>
#include <stdlib.h>

int main(){

	// Set 
	srand(time(0));
	
	
	// Loop to generate 10 random numbers
	int i=0;
	for(i =0; i < 10; i++){
		// Produce a random number in the range of 0-255
		int mySignedRandomNumber = rand() % 255;
		int myUnsignedRandomNumber = rand() % 255;
		printf("Random Signed: %d\t\tRandom unsigned:  %d \n",mySignedRandomNumber,myUnsignedRandomNumber);	

		signed char charSignedCast = mySignedRandomNumber;
		unsigned char charUnsignedCast = myUnsignedRandomNumber;

		printf("char signed: %c\t\t\tchar unsigned: %c \n",charSignedCast, charUnsignedCast);	
		
		printf("Cast as int: char signed: %d\tchar unsigned: %d \n",(int)charSignedCast, (int)charUnsignedCast);	

		printf("\n");
}



	return 0;
}
