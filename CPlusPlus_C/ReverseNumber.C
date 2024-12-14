// Reverse the Number

#include <stdio.h>

int main(){
	int num, rem, rev_num = 0;
	printf("Enter the Number you want to reverse them: \n");
	scanf("%d", &num);

	while(num != 0){
		rem = num % 10;
		num /= 10;
		rev_num = rev_num*10 + rem;
	}

	printf("Reverse Number is %d", rev_num);

	return 0;
}