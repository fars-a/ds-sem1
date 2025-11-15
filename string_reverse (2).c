/*
16.program to reverse a string using Stack
@Farsan_Suneer
Date_of_completion: 27/07/2025
*/
#include<stdio.h>
char a[100];
int top=-1;
void push(char e) //function to push charcters into the stack
{
	if(top+1==100) //check if stack is full
	{
		printf("STACK OVERFLOW");
	}
	else
	{
		a[++top]=e;
	}
	
}
void disp() //function to display the reverse of string
{
	int i;
	if(top==-1)
	{
		printf("STACK UNDERFLOW");
	}
	else
	{
		for(i=top;i>-1;i--)
		{
			printf("%c",a[i]);
		}
	}
}
void menu() //function to handle user choices
{
	int ch,i;
	char e;
	do
	{
		printf("\n\n1.PUSH\n2.DISPLAY REVERSE\n3.EXIT\nEnter your choice: ");
		scanf(" %d",&ch);
		getchar();
		switch(ch)
		{
			case 1:
				top=-1;
				printf("Enter the string: ");
				gets(a);
			    for(i=0;a[i]!='\0';i++) 
	            {
                  push(a[i]);
                }
				break;
			case 2:
				disp();
				break;
			case 3:
				break;
			default:
				printf("WRONG CHOICE");
		}
		
	}while(ch!=3); //menu displayed until user wants to exit
	
}
int main() //main function
{
	menu();
	return 0;
}
