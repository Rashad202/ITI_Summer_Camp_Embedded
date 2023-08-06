#include <stdio.h>

void swap(int **p , int **q , int **r);

void main (void)
{
	int x = 1 , y = 2 , z  = 3;
	int *p = &x , *q = &y , *r =&z;
	
	printf("x = %d\n" , x);
	printf("y = %d\n" , y);
	printf("z = %d\n" , z);

	
	printf("p = %p\n" , p);
	printf("q = %p\n" , q);
	printf("r = %p\n" , r);
	

	printf("*p = %d\n" , *p);
	printf("*q = %d\n" , *q);
	printf("*r = %d\n" , *r);
	
	
	printf ("\n\nSwapping pointers \n");
	swap(&p , &q , &r);
	
	printf("x = %d\n" , x);
	printf("y = %d\n" , y);
	printf("z = %d\n" , z);

	printf("p = %p\n" , p);
	printf("q = %p\n" , q);
	printf("r = %p\n" , r);
	
	printf("*p = %d\n" , *p);
	printf("*q = %d\n" , *q);
	printf("*r = %d\n" , *r);
	
	

}

void swap(int **p , int **q , int **r)
{
	int *temp ;
	temp = *r ;
	*r = *p ;
	*p = *q ;
	*q = temp;
}

