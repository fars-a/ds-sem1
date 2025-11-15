 
/*(heapsort) 
@Farsan_Suneer 
Roll no: 26 
Date: 02-10-2025 
*/ 
#include <stdio.h>
int heap[50];
void heapify(int heap[],int n)
{
   int i,j,c,root,temp;
   for(j=n-1;j>=0;j--)
   {
      temp=heap[0];
      heap[0]=heap[j];       // swap max element with rightmost leaf element
      heap[j]=temp;
      root=0;
      do {
         c=2*root+1;        // left node of root element
         if((heap[c]<heap[c+1])&&c<j-1)
            c++;
         if(heap[root]<heap[c]&&c<j) 
		 { // again rearrange to max heap array
            temp=heap[root];
            heap[root]=heap[c];
            heap[c]=temp;
         }
         root=c;
      } while(c<j);
   }
   printf("\nThe sorted array is: ");
   for (i=0;i<n;i++)
      printf("%d ",heap[i]);
    printf("\n");
}
void maxheap(int heap[],int n)
{
   int i,j,c,r,t;
   for (i=1;i<n;i++) 
   {
      c=i;
      do {
         r=(c-1)/2;
         if (heap[r]<heap[c]) 
		 { // to create MAX heap array
            t=heap[r];
            heap[r]=heap[c];
            heap[c]=t;
         }
         c=r;
      }while(c!=0);
   }
   printf("Heap tree: ");
   for(i=0;i<n;i++)
      printf("%d ",heap[i]);
   heapify(heap,n);
}
void menu()
{
	int ch,n,i;
	do
	{
		printf("\n1.ENTER ELEMENTS\n2.HEAP SORT\n3.EXIT\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter number of elements: ");
                scanf("%d",&n);
                printf("Enter %d elements: ",n);
                for (i=0;i<n;i++)
                {
                	scanf("%d",&heap[i]);
				}
                break;
            case 2:
            	if(n==0)
                    printf("Please enter elements first!\n");
                else
                    maxheap(heap,n);
                break;
            case 3:
            	break;
            default:
            	printf("WRONG CHOICE");
		}
	}while(ch!=3);
}
int main()
{
	menu();
	return 0;
}
