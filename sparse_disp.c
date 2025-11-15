/*( Read and display a sparse matrix) 
@Farsan_Suneer 
Roll no: 26 
Date: 01-10-2025 
*/
#include<stdio.h>
#define size 20
int a[size][size];
//Function to read matrix from the user
void read_matrix(int r, int c)
{
    int i,j;
    printf("----Enter the matrix----\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
//Function to display the triplet form 
void triplet_form(int m[size][size],int r,int c,int t[size][3])
{
    int i,j,k=1,count=0;
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            if(m[i][j]!=0) {
                t[k][0]=i; 
                t[k][1]=j;
                t[k][2]=m[i][j];
                k++;
                count++;
            }
        }
    }
    t[0][0]=r;
    t[0][1]=c;
    t[0][2]=count;
    for(i=0;i<=count;i++)
    {
        printf("%d\t%d\t%d\n",t[i][0],t[i][1],t[i][2]);
    }
}
//Function to display the original sparse matrix
void disp_matrix(int r, int c)
{
    int i,j;
    printf("----Original matrix----\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void menu() //Function to handle user input
{
    int r=0,c=0,ch;
    do
    {
       int t[size][3];
       printf("\n1.MATRIX\n2.SPARSE\n3.ORIGINAL\n4.EXIT\nYOU CHOICE: ");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter the order of the matrix: ");
            scanf("%d%d",&r,&c);
            read_matrix(r,c);
            break;
        case 2:
            triplet_form(a,r,c,t);
            break;
        case 3:
            disp_matrix(r,c);
            break;
        case 4:
            break;
        default:
            printf("WRONG CHOICE");
       }
    } while (ch!=4);
    
}
//Main function
int main()
{
	menu();
	return 0;
}
