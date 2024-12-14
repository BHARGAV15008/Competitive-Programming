// Armstrong proving number by sum of cube of the digit in number.
#include <stdio.h>

int main(){
	int num, val, nVal, sum = 0;
	printf("Enter the Number you want to check Armstrong : \n");
	scanf("%d", &num);
	nVal = num;

	do{
		val = num % 10;
		sum = sum + val*val*val;
		num = num / 10;

	}while(val != 0);

	if(sum == nVal)
		printf("Number is Armstrong...");
	else
		printf("Number is not Armstrong...");

	return 0;
}