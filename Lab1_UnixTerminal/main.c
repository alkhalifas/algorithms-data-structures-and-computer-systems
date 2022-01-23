#include <stdio.h>


double power(double base, double n) {

	double answer = 1;
	int i;

	for (i = 0; i<n; i++) { 
		answer *= base;
	}
	return answer;
}


int main() {
	
	int i;
	for (i = 0; i < 11; i++) 
		printf("2^%d= %f\n", i, power(2,i));

	return 0;	
}

