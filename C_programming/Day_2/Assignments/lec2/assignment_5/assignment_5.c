#include <stdio.h>

void main (void)
{
int ID, pass;
	
	printf("Please Enter Your ID: ");
	scanf("%d",&ID);
	
		switch(ID)
	{
		case 1234: 
			printf("Please Enter Password: ");
		    for (int i= 0; i<3; i++)
			{
				scanf ("%d",&pass);
				if(pass == 7788)
					printf("Welcome Ahmed");
				   
				else if (i<2)
				    printf("Try again: ");
				
				else if (i == 2)
					printf("Incorrect password for 3 times, No more tries");
			}
			
			break;
				   
		case 5678: 
			printf("Please Enter Password: ");
		    for (int i = 0; i <3; i++)
			{
			   scanf ("%d",&pass);
			   if(pass == 5566)
				   printf("Welcome Amr");	      

				else if (i<2)
				    printf("Try again: ");
				
				else if (i == 2)
					printf("Incorrect password for 3 times, No more tries");
			}	
			break;
				   
		case 9870: 
			printf("Please Enter Password: ");
		    for (int i = 0; i <3; i++)
			{
			   scanf ("%d",&pass);
			   if(pass == 1122)
				   printf("Welcome Wael");			      

				else if (i<2)
				    printf("Try again: ");
				
				else if (i == 2)
					printf("Incorrect password for 3 times, No more tries");
			}
			break;
				   
		default  : 
			printf("You are not registered");
		    
	}
	
}