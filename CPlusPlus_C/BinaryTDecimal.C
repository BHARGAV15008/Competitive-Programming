// Try convert a number binary to Decimal

#include <stdio.h>
#include <math.h>

int main(){
	int bin, dec = 0, rem_val, mul = 0;
	printf("Enter the binary Number: \n");
	scanf("%d", &bin);

	while(bin != 0){
		rem_val = bin % 10;
		bin = bin / 10;
		dec = dec + rem_val*pow(2,mul);
		mul++;
	}

	printf("Decimal value is %d", dec);

	return 0;
}