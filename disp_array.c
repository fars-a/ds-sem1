/*
6.program to display the array elements in the same order using a recursive function
@Farsan_Suneer
Date_of_completion: 23/07/2025
*/
#include<stdio.h>
int read(int a[]) //function to read array
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
void disp(int a[],int n,int pos) //function to display the array using recursion
{
	if(pos==n) //check if pos and number of elements are equal
	{
		return;
	}
	else
	{
		printf("%d  ",a[pos++]); //print current element
     	disp(a,n,pos); //recursive call to disp()
	}
}
int main() //main function
{
  int a[10],n;
  n=read(a); //calling read() function
  printf("Array elements are: ");
  disp(a,n,0);
  return 0;
}
