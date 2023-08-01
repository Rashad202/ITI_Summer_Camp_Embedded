#include <stdio.h>

void main(void)
{
	int class_1[10],class_2[10],class_3[10];
	int arr[30] ;
	
	int i,j;
	int passed=0,failed=0;
	int min=0,max=0,sum=0;
	
	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i] = class_1[i];
	}

	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i+10] = class_2[i];
	}

	for (int i = 0 ; i < 10 ; i++)
	{
		arr[i+20] = class_3[i];
	}
	


	for ( i =1 ; i <= 3 ; i++)
	{
		for (j=0 ; j<10 ; j++)
		{

			printf("Enter grade for student number %d in class %d: ",j+1,i);
			if (i==1)
				{
					scanf("%d",&class_1[j]);
					
					if(j==9)
						printf("\n");
				}	
			else if (i==2)
				{	
					scanf("%d",&class_2[j]);
					
					if(j==9)
						printf("\n");
				}
			else if (i==3)
				{
					scanf("%d",&class_3[j]);
					
					if(j==9)
						printf("\n");
				}

		}
	}


	for ( i =1 ; i <= 3 ; i++)
	{
		for (j=0 ; j<10 ; j++)
		{
			if (i==1)
			{
				if (class_1[j] > max)
					max = class_1[j];
				else if (class_1[j] < min)
					min=class_1[j];
				
				if (class_1[j] >= 50 )
					passed++;
				else
					failed++;
				sum+=class_1[j];
			}
			
			if (i==2)
			{
				if (class_2[j] > max)
					max=class_2[j];
				else if (class_2[j] < min)
					min=class_2[j];
				
				if (class_2[j] >= 50)
					passed++;
				else
					failed++;
				sum+=class_2[j];
			}
			if (i==3)
			{
				if (class_3[j] > max)
					max=class_3[j];
				else if (class_3[j] < min)
					min=class_3[j];
				
				if (class_3[j] >= 50)
					passed++;
				else
					failed++;
				sum+=class_3[j];
			}
		}

	}

	printf("Number of passed students = %d \n",passed);
	printf("Number of failed students = %d \n",failed);
	printf("Highest grade = %d \n",max);
	printf("Lowest grade = %d \n",min);
	printf("Average grade = %f \n",(float)(sum/30));

}
