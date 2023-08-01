#include <stdio.h>

/* Proto type */
int Get_Max (int x1, int x2, int x3, int x4);
int Get_Min (int x1, int x2, int x3, int x4);

void main(void)
{
	int a,b,c,d,max,min;
// Get numbers
	printf("Please Enter Value 1: ");
	scanf("%d",&a);
	
	printf("Please Enter Value 2: ");
	scanf("%d",&b);

	printf("Please Enter Value 3: ");
	scanf("%d",&c);
	
	printf("Please Enter Value 4: ");
	scanf("%d",&d);
	
	max = Get_Max(a,b,c,d);
	min = Get_Min(a,b,c,d);

	printf("The Maximum value is  : %d\n",max);
	printf("The Minimum value is  : %d\n",min);
}

// Functions definition 
int Get_Max (int x1, int x2, int x3, int x4)
{
	int max;
	
	if (x1>x2 && x1>x3 && x1>x4)
		max = x1;
	else if (x2>x1 && x2>x3 && x2>x4)
		max = x2;
	else if (x3>x1 && x3>x2 && x3>x4)
		max = x3;
	else if (x4>x1 && x4>x2 && x4>x3)
		max = x4;


	return max;
	
}


int Get_Min (int x1, int x2, int x3, int x4)
{
	int min;
	if (x1<x2 && x1<x3 && x1<x4)
		min = x1;
	else if (x2<x1 && x2<x3 && x2<x4)
		min = x2;
	else if (x3<x1 && x3<x2 && x3<x4)
		min = x3;
	else if (x4<x1 && x4<x2 && x4<x3)
		min = x4;

	return min;
	
}
