#include <stdio.h>

void Sort(int *arr , int n );

void main (void)
{
	int array[100];
	int n ;
	
	
	printf("Enter length max 100 : ");
	scanf("%d" , &n);
	

	for (int i = 0 ; i < n ; i++)
	{
		printf("Please enter number %d:" , i+1);
		scanf("%d" , &array[i]);
	}

	printf("array elements before sorting\n");
	for (int i = 0 ; i < n ; i++)
	{
		printf("%d   " , array[i]);
	}
	printf("\n\n\n");
	Sort(array , n);
	
}

void Sort(int *arr , int n )
{
	int temp ;
	
	for(int i = 0; i < (n - 1) ; i++ )
	{	
		for (int j = 0 ; j < (n-1-i) ; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j+1] ;
				arr[j+1] = arr[j];
				arr[j] = temp ;
			}
		}
	}
	

	printf("array elements after sorting\n");
	for (int i = 0 ; i < n ; i++)
	{
		printf("%d   " , arr[i]);
	}
}