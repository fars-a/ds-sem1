/*
10.program to find transpose of a matrix
@Farsan_Suneer
Date_of_completion: 06/07/2025
*/
#include<stdio.h>
void read(int a[10][10],int m,int n) //function to read matrix
{
	int i,j;
	printf("Enter the elemnts:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]); //read matrix
		}
	}
}
void disp(int a[10][10],int m,int n) //function to display the user entered matrix
{
   int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]); //print matrix 
		}
		printf("\n");
	}	
}
void transpose(int a[10][10],int m,int n) //function to find the matrix transpose
{
	int i,j;
	printf("\nTRANSPOSE\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
}
void menu() //function to handle the user choices
{
	  int ch,m,n,a[10][10];
	  do
      {
		printf("\n1.READ MATRIX\n2.DISPLAY MATRIX\n3.MATRIX TRANSPOSE\n4.EXIT\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter number of rows: ");
             	scanf("%d",&m);
            	printf("Enter number of columns: ");
             	scanf("%d",&n);
				read(a,m,n);
				break;
			case 2:
				printf("MATRIX\n");
				disp(a,m,n);
				break;
			case 3:
				transpose(a,m,n);
				break;
			case 4:
				break;
			default:
				printf("INVALID CHOICE!");
		}
	  }while(ch!=4); //menu displayed util user wants to exit
}
int main() //main function
{
   menu();
   return 0;
}
