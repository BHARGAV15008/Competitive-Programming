// Reverse the Array

#include <stdio.h>

int main(){
	int n, nums[10], j = 0, i, t_num;
	printf("How many element you want to enter in Array: \n");
	scanf("%d", &n);

	printf("Enter the element in Array: \n");
	for(i = 0; i < n; i++)
		scanf("%d", &nums[i]);
	i = n-1;

	while(i > j){
		t_num = nums[i];
		nums[i] = nums[j];
		nums[j] = t_num;
		j++;
		i--;
	}

	printf("Reverse Array is ");
	for(i = 0; i < n; i++)
		printf("%d  ", nums[i]);

	return 0;
}