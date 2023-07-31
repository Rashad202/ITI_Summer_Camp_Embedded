#include "stdio.h"

void main (void)
{
	int num1,num2;
	int sum,sub,AND,OR,XOR;

	sum=sub=AND=OR=XOR=0;

	// get numbers
	printf("Please enter a : " );
	scanf("%d",&num1);
	printf("Please enter b : " );
	scanf("%d",&num2);

	
	// operations
	sum = num1+num2;
	sub = num1-num2;
	AND = num1&num2;
	OR  = num1|num2;
	XOR = num1^num2;
	
	// print results
	printf(" a + b = %d \n", sum);
	printf(" a - b = %d \n", sub);
	printf(" a & b = %d \n", AND);
	printf(" a | b = %d \n", OR );
	printf(" a ^ b = %d \n", XOR);
}