 
/*(circular queue) 
@Farsan_Suneer 
Roll no: 26 
Date: 02-10-2025 
*/ 
#include<stdio.h>
#define size 5
int a[size],rear=-1,front=-1;
void enqueue(int e)      //Function to enqueue the elements
{
	if((rear+1)%size==front)
	{
		printf("QUEUE OVERFLOW");
	}
	else
	{
		if(rear==-1)
	    	front=0;
	    rear=(rear+1)%size;
	    a[rear]=e;
	}
}
void dequeue()           //Function to dequeue the elements
{
	if(front==-1)
	{
		printf("QUEUE UNDERFLOW");
	}
	else
	{
		printf("%d is DEQUEUED",a[front]);
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%size;
		}
	}
}
void disp()           //Function to display the elements
{
	int i=front;
	if(front==-1)
	{
		printf("QUEUE UNDERFLOW");
	}
	else
	{
		while(1)
		{
			printf("%d\t",a[i]);
			if(i==rear)
			{
				break;
			}
			i=(i+1)%size;
		}
		printf("\n");
	}
	
}
void menu()             //Function to handle user choices
{
	int ch,e;
	do
	{
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to enqueue: ");
				scanf("%d",&e);
				enqueue(e);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				disp();
				break;
			case 4:
				break;
			default:
				printf("WRONG CHOICE");
		}
	}while(ch!=4);
}
int main()           //Main Function
{
	menu();
	return 0;
}
