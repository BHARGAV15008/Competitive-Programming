// find the number prime number between range.

#include <stdio.h>
#include <math.h>

int main(){
	int to, from, fact_count = 0, prime_count = 0;
	printf("Enter the Number you want to check prime number from : \n");
	scanf("%d", &from);

	printf("Enter the Number you want to check prime number to : \n");
	scanf("%d", &to);

	for(int j = from; j <= to; j++){
		for(int i = 2; i <= sqrt(j); i++)
			if(j % i == 0)
				fact_count++;

		if(fact_count == 0)
			prime_count++;

		fact_count = 0;
	}

	printf("The number of prime Number is %d", prime_count);

	return 0;
}