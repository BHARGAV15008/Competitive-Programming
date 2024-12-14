// Check the Palindrome number

#include <stdio.h>

int main(){
	int num, val, rev_num = 0, rem;
	printf("Enter the Number you want to check palindrome: \n");
	scanf("%d", &num);
	val = num;

	while(val != 0){
		rem = val % 10;
		val /= 10;
		rev_num = rev_num*10 + rem;
	}

	if(num == rev_num)
		printf("Given number is Palindrome...");
	else
		printf("Given number is not Palindrome...");

	return 0;
}