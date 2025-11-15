/*
5.program to sort the array elements in ascending order (minimum three functions: read, disp and sort)
@Farsan_Suneer
Date_of_completion: 23/07/2025
*/
#include<stdio.h>
int read(int a[]) //function to read array
{
	int i,n;
	printf("\nEnter the size of array: ");
    scanf("%d",&n);
	printf("Enter the values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	return n; //return number of elements
}
void disp(int a[],int n) //function to display the array
{
	int i;
	printf("Array is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void sort(int a[],int n) //function to sort the array
{ 
  int temp=0,i,j=0;
  for(i=0;i<n;i++)
  {
  	for(j=i+1;j<n;j++)
  	{
  		if(a[i]>a[j])
  		{
  		  temp=a[i];
		  a[i]=a[j];
		  a[j]=temp; //swap a[i] and a[j] using temp
		}
	  }
  }
  printf("\nSorted "); //display the sorted array
  disp(a,n);
}
void menu() //function to handle user choices
{
	int ch,a[10],n=0;
    do{
        printf("\n1.READ ARRAY\n2.DISPLAY ARRAY\n3.SORT ARRAY IN ASCENDING ORDER\n4.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                  n=read(a);
                  break;
            case 2:
                  disp(a,n);
                  break;
            case 3:
                  sort(a,n);
                  break;
            case 4:
                  break;
            default:
                  printf("WRONG CHOICE");
                  break;
        }
    }while(ch!=4); //repeat the menu until user wants to exit
}
int main() //main function
{
  menu();
  return 0;	
}
