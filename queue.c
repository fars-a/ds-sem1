 
/*(Queue Operations) 
@Farsan_Suneer 
Roll no: 26 
Date: 02-10-2025 
*/ 
#include<stdio.h>
#define size 20
int a[size],rear=-1,front=-1;
void enqueue(int e)           //Function to enqueue elements to the queue
{
	if(rear+1==size)
	{
		printf("Queue Overflow");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		a[++rear]=e;
		printf("%d is ENQUEUED\n",e);
	}
}
void dequeue()           //Function to enqudequeue elements from the queue
{
	if(front==-1)
	{
		printf("Queue Underflow");
	}
	else
	{
		printf("%d is DEQUEUED\n",a[front]);
		front+=1;     
		if(front>rear)
		{
			front=rear=-1;  
		}
	}
}
void disp()           //Function to display the queue
{
	int i;
	if(front==-1)
	{
		printf("Queue Underflow");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
	}
}
void menu()      //Menu to handle user choices
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
int main()        //Main function
{
	menu();
	return 0;
}
