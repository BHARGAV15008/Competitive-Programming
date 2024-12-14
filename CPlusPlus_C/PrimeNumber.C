// find the prime number.

#include <stdio.h>
#include <math.h>

int main(){
	int num, fact_count = 0;
	printf("Enter the Number you want to check prime number : \n");
	scanf("%d", &num);

	for(int i = 2; i <= sqrt(num); i++)
		if(num % i == 0)
			fact_count++;

	if(fact_count == 0)
		printf("This number is Prime Number...");
	else
		printf("This number is not Prime Number...");

	return 0;
}