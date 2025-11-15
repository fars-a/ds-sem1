/*
4.program to search for all the occurrences of an element in an integer array (positions)
@Farsan_Suneer
Date_of_completion: 26/07/2025
*/
#include<stdio.h>
int a[10],counter,n;//global variables
void read()//function to read the array
{
    int i;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the values: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void count()//function to count the occurrences of elements
{
	int i,e;
	char ch;
   do
   {
   counter=0;
   printf("\nEnter the element to search: ");
   scanf("%d",&e); 
   for(i=0;i<n;i++)
   {
     	if(a[i]==e)//loop through the array to find matches
     	{
     		printf("%d found at postion %d\n",e,i);
     		counter++;//count the number of occurences of the element
		}
   }
   printf("NUMBER OF OCCURANCE:%d",counter);
   printf("\nDo you want to search again?(y/n): ");
   scanf(" %c",&ch);	
   }while(ch!='n');//continue until user enters 'n'
}
int main()//main function
{
	read();
	count();
	return 0;
}
