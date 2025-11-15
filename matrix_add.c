/*
8.program to Perform the addition of two matrix and Subtraction of one matrix from another
@Farsan_Suneer
Date_of_completion: 23/07/2025
*/
#include<stdio.h>
void read(int a[10][10],int b[10][10],int row,int col) //function to read the two matrices
{
	int i,j;
	printf("Enter the elemnts:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]); //read matrix a
		}
	}
	printf("Enter the elemnts:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&b[i][j]); //read matrix b
		}
	}
}
void disp(int a[10][10],int b[10][10],int row,int col) //function to display the user entered matrix
{
   int i,j;
   printf("ARRAY 1\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",a[i][j]); //print matrix a
		}
		printf("\n");
	}	
	printf("ARRAY 2\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",b[i][j]); //print matrix b
		}
		printf("\n");
	}	
}
void sum(int a[10][10],int b[10][10],int row,int col) //function to add two matrices
{
	int i,j;
	printf("MATRIX SUM \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",a[i][j]+b[i][j]); //print matrix after addition
		}
		printf("\n");
	}	
}
void sub(int a[10][10],int b[10][10],int row,int col) //function to perform matrix subtraction
{
	int i,j;
		printf("MATRIX SUBTRACTION \n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",a[i][j]-b[i][j]); //print matrix after subtraction
		}
		printf("\n");
	}	
}
void menu() //function to handle user choices
{
	
	int a[10][10],b[10][10],row=0,col=0,ch;
	printf("Enter the number of rows and columns: ");
	scanf("%d%d",&row,&col);
	do
	{
		printf("\n1.READ MATRICES\n2.DISPLAY MATRICES\n3.MATRIX ADDITION\n4.MATRIX SUBTRACTION\n5.EXIT\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				read(a,b,row,col);
				break;
			case 2:
				disp(a,b,row,col);
				break;
			case 3:
				sum(a,b,row,col);
				break;
			case 4:
				sub(a,b,row,col);
				break;
			case 5:
				break;
			default:
				printf("INVALID CHOICE!");
		}
	}while(ch!=5); //menu displayed util user wants to exit
}
int main()
{
	menu();
	return 0;
}
