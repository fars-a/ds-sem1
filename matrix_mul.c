/*
9.program to perform multiplication of two matrix
@Farsan_Suneer
Date_of_completion: 23/07/2025
*/
#include<stdio.h>
void read(int m[3][3],int row,int col) //function to read the two matrices
{
	int i,j;
	printf("\nEnter the elemnts:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&m[i][j]); //read matrix a
		}
	}
}
void disp(int m[3][3],int row,int col) //function to display the user entered matrix
{
   int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",m[i][j]); //print matrix 
		}
		printf("\n");
	}	
}
void mul(int a[3][3],int b[3][3],int row1,int col1,int row2,int col2) //function to multiply two matrix
{
	int mul[3][3],k,i,j;
	for(i=0;i<row1;i++) {
        for(j=0;j<col2;j++) {
            mul[i][j] = 0;
        }
    }
	for(i=0;i<row1;i++){
		for(j=0;j<col2;j++){
			for(k=0;k<col1;k++){
				mul[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			printf("%d ",mul[i][j]); //print the product of two matrices
		}
		printf("\n");
	}
}
void menu() //function to handle the user choices
{
	int a[3][3],b[3][3],row1,col1,row2,col2,ch;
	printf("Enter the number of rows and columns for MATRIX 1: ");
	scanf("%d%d",&row1,&col1);
	printf("Enter the number of rows and columns for MATRIX 2: ");
	scanf("%d%d",&row2,&col2);
	if(col1!=row2)
	{
		printf("number of columns in first matrix should be equal to number of rows in second matrix");
	}
	else
	{
	  do
      {
		printf("\n1.READ MATRICES\n2.DISPLAY MATRICES\n3.MATRIX MULTIPLICATION\n4.EXIT\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				read(a,row1,col1);
				read(b,row2,col2);
				break;
			case 2:
				printf("MATRIX 1\n");
				disp(a,row1,col1);
				printf("MATRIX 2\n");
				disp(b,row2,col2);
				break;
			case 3:
				mul(a,b,row1,col1,row2,col2);
				break;
			case 4:
				break;
			default:
				printf("INVALID CHOICE!");
		}
	  }while(ch!=4); //menu displayed util user wants to exit
	}
}
int main() //main function
{
    menu(); 
	return 0;
}
