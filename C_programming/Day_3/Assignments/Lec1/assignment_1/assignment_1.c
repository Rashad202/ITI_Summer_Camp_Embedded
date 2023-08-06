#include "stdio.h"

void main()
{
	int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10;
	int val;
	printf("Enter Number 1: ");
	scanf("%d",&num1);
	printf("Enter Number 2: ");
	scanf("%d",&num2);
	printf("Enter Number 3: ");
	scanf("%d",&num3);
	printf("Enter Number 4: ");
	scanf("%d",&num4);
	printf("Enter Number 5: ");
	scanf("%d",&num5);	
	printf("Enter Number 6: ");
	scanf("%d",&num6);
	printf("Enter Number 7: ");
	scanf("%d",&num7);
	printf("Enter Number 8: ");
	scanf("%d",&num8);
	printf("Enter Number 9: ");
	scanf("%d",&num9);
	printf("Enter Number 10: ");
	scanf("%d",&num10);	

	// value to be searched
	printf("Enter the value to search : ");
	scanf("%d",&val);	

	// code for searching
	if (num1 == val )
	 	printf("value is exist at element number %d  ",num1);	
	
	else if (num2 == val )  
	 printf("value is exist at element number %d  ",num2);
	
	else if (num3 == val )    
	 printf("value is exist at element number %d  ",num3);
	
	else if (num4 == val )    
	 printf("value is exist at element number %d  ",num4);
	
	else if (num5 == val ) 
	 printf("value is exist at element number %d  ",num5);
	
	else if (num6 == val )    
	 printf("value is exist at element number %d  ",num6);
	
	else if (num7 == val )    
	 printf("value is exist at element number %d  ",num7);
	
	else if (num8 == val )    
	 printf("value is exist at element number %d  ",num8);
	
	else if (num9 == val )    
	 printf("value is exist at element number %d  ",num9);
	
	else if (num10 == val ) 
	 printf("value is exist at element number %d  ",num10);
	
	else
	 printf("value is not exist at any element  ");
	 
}

