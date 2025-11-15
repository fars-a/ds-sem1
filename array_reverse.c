/*
7.program to display array elements in reverse order using a recursive function .
@Farsan_Suneer
Date_of_completion: 23/07/2025
*/
#include<stdio.h>
int a[10],pos=0,n;
int read(int a[]) //function to read array elements
{
	int i,n;
	printf("Enter size of the arary: ");
	scanf("%d",&n);
	printf("Enter the values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	return n;
}
void disp(int a[],int pos) //recursive function to display reverse of the array
{
	if(pos==-1)
	{
		return;
	}
	else
	{
		printf("%d  ",a[pos--]); //print current element
     	disp(a,pos); //recursive call to print the previous element
	}
}
int main() //main function
{
  int a[10],n;
  n=read(a); //calling read() function
  printf("Reverse of array is: ");
  disp(a,n-1);
  return 0;
}
