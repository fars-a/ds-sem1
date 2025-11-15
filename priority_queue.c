 
/*(priority queue) 
@Farsan_Suneer 
Roll no: 26 
Date: 02-10-2025 
*/ 
#include<stdio.h>
#define size 20
int heap[size];
int n=0;   
void heapify_up(int index)        // Heapify up 
{
    int parent=(index-1)/2;
    if (index&&heap[parent]<heap[index]) 
    {
        int temp=heap[parent];
        heap[parent]=heap[index];
        heap[index]=temp;
        heapify_up(parent);
    }
}
void heapify_down(int index)    // Heapify down
{
    int left=2*index+1;
    int right=2*index+2;
    int largest=index;
    if (left<n&&heap[left]>heap[largest])
        largest=left;
    if (right<n&&heap[right]>heap[largest])
        largest=right;
    if (largest!=index) 
	{
        int temp=heap[index];
        heap[index]=heap[largest];
        heap[largest]=temp;
        heapify_down(largest);
    }
}
void enqueue(int e)       // Insert element into priority queue
{
    if (n==size) 
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    heap[n]=e;
    heapify_up(n);
    n++;
    printf("%d ENQUEUED\n",e);
}
int dequeue()          // Remove element with highest priority
{
    if(n==0) {
        printf("Queue Underflow\n");
        return -1;
    }
    int max=heap[0];
    heap[0]=heap[n - 1];
    n--;
    heapify_down(0);
    printf("%d DEQUEUED\n", max);
    return max;
}
void display()           // Display priority queue
{
    int i;
    if(n==0) 
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    for(i=0;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
}
void menu()              //Function to handle user choices
{
    int ch,e;
    do {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d",&e);
                enqueue(e);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Wrong choice");
        }
    } while(ch!=4);
}
int main()          // Main function
{
    menu();
    return 0;
}

