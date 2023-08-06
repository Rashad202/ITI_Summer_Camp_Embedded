#include "stdio.h"

void main(void)
{
	int num1,num2;
	int result=0;
	while(1)
	{	
		printf("Pleae Enter first number : ");
		scanf("%d",&num1);
		printf("Pleae Enter second number :");
		scanf("%d",&num2);

		result = num1 +num2;
		printf("The result is %d \n\n",result);
	}
}