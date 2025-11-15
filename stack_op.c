/*
12.program to implement stack operations using arrays
@Farsan_Suneer
Date_of_completion: 19/07/2025
*/
#include<stdio.h>
int a[5],top=-1;
void push(int e) //function to push an element into the stack
{
	if(top+1==5) //check if stack is full
	{
		printf("STACK OVERFLOW");
	}
	else
	{
		a[++top]=e;
		printf("%d PUSHED",e);
	}
	
}
void pop() //function to pop an element from the stack
{
	if(top==-1) //check if stack is empty
	{
		printf("STACK UNDERFLOW");
	}
	else
	{
		printf("%d POPPED",a[top]); //element popped from top
		top-=1;
	}
}
void peek() //function to peek the element at the top
{
	if(top==-1)
	{
		printf("STACK UNDERFLOW");
	}
	else
	{
		{
			printf("%d\t",a[top]);
		}
	}
}
void disp() //function to display the stack
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
			printf("%d\t",a[i]);
		}
	}
}
void menu() //function to handle user choices
{
	int ch,e;
	do
	{
		printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY STACK\n5.EXIT\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the item to push: ");
				scanf("%d",&e);
				push(e);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				disp();
				break;
			case 5:
				break;
			default:
				printf("WRONG CHOICE");
		}
		
	}while(ch!=5); //menu displayed until user wants to exit
	
}
int main() //main function
{
	menu();
	return 0;
}
