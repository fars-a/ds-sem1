 
/*( Write a program to add two sparse matrix) 
@Farsan_Suneer 
Roll no: 26 
Date: 01-10-2025 
*/
#include<stdio.h>
#define size 20
int a[size][size],b[size][size],r=0,c=0;
//Get matrix from the user
void get_matrix(int m[size][size],int r,int c) 
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
}
//convert matrix to corresponding triplet form
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
    printf("\n");
}
// Function to add two sparse matrices
void addition(int t1[size][3],int t2[size][3])
{
    int t3[size][3];
    int i=1,j=1,k=1;
    int r=t1[0][0],c=t1[0][1];
    if(t1[0][0]!=t2[0][0]||t1[0][1]!=t2[0][1])    // Check if addition is possible 
    {
        printf("\nADDITION NOT POSSIBLE");
        return;
    }
    while(i<=t1[0][2]&&j<=t2[0][2])      // Merge the two triplet matrices
    {
        if(t1[i][0]==t2[j][0]&&t1[i][1]==t2[j][1])    // Add values if same row and column
        {
            t3[k][0]=t1[i][0];
            t3[k][1]=t1[i][1];
            t3[k][2]=t1[i][2]+t2[j][2];
            i++; 
            j++; 
            k++;
        }
        else if(t1[i][0]<t2[j][0]||(t1[i][0]==t2[j][0]&&t1[i][1]<t2[j][1])) 
        {
            t3[k][0]=t1[i][0];
            t3[k][1]=t1[i][1];
            t3[k][2]=t1[i][2];
            i++; 
            k++;
        }
        else 
        {
            t3[k][0]=t2[j][0];
            t3[k][1]=t2[j][1];
            t3[k][2]=t2[j][2];
            j++; 
            k++;
        }
    }
    while(i<=t1[0][2]) // Copy remaining terms
    {
        t3[k][0]=t1[i][0];
        t3[k][1]=t1[i][1];
        t3[k][2]=t1[i][2];
        i++; 
        k++;
    }
    while(j<=t2[0][2]) 
    {
        t3[k][0]=t2[j][0];
        t3[k][1]=t2[j][1];
        t3[k][2]=t2[j][2];
        j++; 
        k++;
    }
    t3[0][0]=r;
    t3[0][1]=c;
    t3[0][2]=k-1;
    printf("\n------A+B------\n");
    for(i=0;i<=t3[0][2];i++)
    {
        printf("%d\t%d\t%d\n",t3[i][0],t3[i][1],t3[i][2]);
    }
}
void menu() //Menu to handle user choice
{
    int ch,r,c,t1[size][3],t2[size][3];
    do
    {
       printf("\n1.GET MATRIX\n2.ADDITION\n3.EXIT\nENTER YOUR CHOICE: ");
       scanf("%d",&ch);
       switch(ch)
       {
          case 1:
              printf("Enter order of matrix 1: "); scanf("%d%d",&r1,&c1);
              printf("Enter matrix 1:\n"); get_matrix(a,r1,c1);

    printf("Enter order of matrix 2: "); scanf("%d%d",&r2,&c2);
    printf("Enter matrix 2:\n"); get_matrix(b,r2,c2);
    break;
          case 2:
          	 printf("\nMATRIX A\n");
          	 triplet_form(a,r,c,t1);
          	 printf("\nMATRIX B\n");
          	 triplet_form(b,r,c,t2);
             addition(t1,t2);
             break;
          case 3:
               break;
          default:
               printf("WRONG CHOICE");
       }
    } while (ch!=3);
}
int main() // Main function
{
    menu();
    return 0;
}



void sparse_mul(int t1[size][3],int t2[size][3]) 
{ 
    int t3[size][3],k=1,i,j,p; 
    int r=t1[0][0],c=t2[0][1]; 
    if(t1[0][1]!=t2[0][0])  
    { 
        printf("Multiplication not possible\n"); 
        return; 
    }   
    for(i=1;i<=t1[0][2];i++)  
 { 
        for(j=1;j<=t2[0][2];j++)  
        { 
            if(t1[i][1]==t2[j][0])  
            { // Column of t1 matches row of t2 
                // Check if already exists in t3 
                int found=0; 
                for(p=1;p<k;p++)  
    { 
                    if(t3[p][0]==t1[i][0]&&t3[p][1]==t2[j][1])  
                    { 
                        t3[p][2]+=t1[i][2]*t2[j][2]; 
                        found=1; 
                        break; 
                    } 
                } 
                if(!found)  
                { 
                    t3[k][0]=t1[i][0]; 
                    t3[k][1]=t2[j][1]; 
                    t3[k][2]=t1[i][2]*t2[j][2]; 
                    k++; 
                } 
            } 
        } 
    } 
    t3[0][0]=r; 
    t3[0][1]=c; 
    t3[0][2]=k-1; 
    printf("\nResult of A x B in triplet form:\n"); 
    for(i=0;i<=t3[0][2];i++) 
    { 
        printf("%d\t%d\t%d\n", t3[i][0], t3[i][1], t3[i][2]); 
    } 
} 
