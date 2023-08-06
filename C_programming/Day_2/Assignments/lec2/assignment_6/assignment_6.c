#include <stdio.h>

void main(void)
{
	int height,i,j;
	
	printf("Please Enter the hieght of the pyramid: ");
	scanf("%d",&height);
	
	/* Every iteration print a line */
	for (i = 0; i < height; i ++)
	{
		/* Print spaces */
		for (j=0; j<height-1-i; j++)
		{
			printf(" ");
		}
		
		/* then Print stars */
		for (j=0; j<2*i+1; j++)
		{
			printf("*");
		}
		
		/* then go to the next line to print the next row */
		printf("\n");
	}
}