// Find the first N fibonacci

#include <stdio.h>

int main(){
	int n, a = 0, b = 1, c;
	printf("How many fibonaci you want to find: \n");
	scanf("%d", &n);

	printf("First %d Fibonacci series is ", n);
	printf("%d  %d  ", a, b);
	while(n != 2){
		c = a + b;
		a = b;
		b = c;
		printf("%d  ", c);
		n--;
	}

	return 0;
}