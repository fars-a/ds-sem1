/*
11.program to find determinant of a matrix (2x2 and 3x3)
@Farsan_Suneer
Date_of_completion: 27/07/2025
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
void det(int a[10][10],int m,int n) //function to find the determinant of the matrix
{
    int d;
    if(m==2&&n==2)
	{
       d=a[0][0]*a[1][1]-a[0][1]*a[1][0]; //determinant of a 2x2 matrix
       printf("Determinant of 2x2 matrix:%d\n", d);
    }
    else if (m==3&&n==3) 
	{
        d=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
        printf("Determinant of 3x3 matrix:%d\n",d); //determinant of a 3x3 matrix
    }
}
void menu() //function to handle the user choices
{
	  int ch,m,n,a[10][10];
	  do
      {
		printf("\n1.READ MATRIX\n2.DISPLAY MATRIX\n3.DETERMINANT\n4.EXIT\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter number of rows and col(2x2 or 3x3): ");
             	scanf("%d%d",&m,&n);
             	if(m!=n||m>3)
	            {
	            	printf("INVALID");
             	}
            	else
             	{
				read(a,m,n);
		     	}
				break;
			case 2:
				printf("MATRIX\n");
				disp(a,m,n);
				break;
			case 3:
				det(a,m,n);
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
