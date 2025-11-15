/*
2.menu-driven program to insert, search, delete and sort elements in an array using functions (use global variables)
@Farsan_Suneer
Date_of_completion: 13/07/2025
*/
#include<stdio.h>
int a[5],n=0;//global variables
void insertArray()//function to insert elements to array
{
	int pos,e;
	if(n>=5)//checking if array is full
	{
        printf("Array is full");
        return;
    }
    printf("Enter the position to insert from 0-%d: ",n);
    scanf("%d",&pos);
    if(pos>n||pos<0)//check if entered position is valid or not
    {
        printf("Array out of bound");
        return;
    }
        printf("Enter the element to insert: ");
        scanf("%d",&e);
        if (pos==n) 
		{
          a[n++]=e;
        } 
		else
		{
          a[pos]=e;
        }
}
void deleteArray()//function to delete from given position 
{
	int dpos,i;
    printf("Enter the position to delete from: ");
    scanf("%d",&dpos);
    if(dpos>=n||dpos<0)//check if entered position is valid or not
    {
        printf("Array out of bound");
    }
    else
    {
      for(i=dpos;i<n;i++)
      {
            a[i]=a[i+1];//shifting elements to the left after deletion
      }
      n--;
    }
}
void sortArray()//function to sort array
{
	int i,j;
	int temp=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>=a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Array after sorting: [\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);//display array after sorting
    }
    printf("]\n");
}
void searchArray()//function to search for elements in the array
{
	int i,e;
    printf("Enter element to search: ");
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
        if(a[i]==e)
        {
            printf("%d found at %dth position\n",e,i);
            return;
        }
    }
   	printf("Element not found\n");
}
void displayArray()//function to display the array
{
    int i;
    printf("[\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("]\n");
}
void choice()//function to handle array operations
{
    int ch;
    do{
        printf("\n1.INSERT\n2.DELETE\n3.SEARCH\n4.SORT\n5.EXIT\n6.DISPLAY\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                  insertArray();
                  break;
            case 2:
                  deleteArray();
                  break;
            case 3:
                  searchArray();
                  break;
            case 4:
                  sortArray();
                  break;
            case 5:
                  break;
            case 6:
            	  displayArray();
            	  break;
            default:
                  printf("WRONG CHOICE");
                  break;
        }
    }while(ch!=5);
    
}
int main()//main function
{
    choice();
    return 0;
}
