 
/*(Multiply two polynomials) 
@Farsan_Suneer 
Roll no: 26 
Date: 02-10-2025 
*/ 
 
#include<stdio.h> 
void read_poly(int *d,int p[])                       //Function to read polynomials 
{ 
    int i; 
    printf("DEGREE OF POLYNOMIAL: "); 
    scanf("%d",d); 
    for(i=*d;i>=0;i--) 
    { 
        printf("Coefficient of x^%d: ",i); 
        scanf("%d",&p[i]); 
    } 
} 
void put_poly(int d, int p[])                       //Function to print polynomials 
{ 
    int i,flag=0; 
    printf("POLYNOMIAL: "); 
    for(i=d;i>=0;i--) 
    { 
        if(p[i]!=0) 
        { 
            flag=1; 
            if(i!=d && p[i]>0) 
                printf("+"); 
            printf("%d",p[i]); 
            if(i==1) 
            { 
                printf("x"); 
            }             
            if(i>1) 
            { 
                printf("x^%d",i); 
            } 
        } 
    }
     if(flag==0) 
    { 
        printf("0"); 
    } 
} 
void mul_poly(int a[],int b[],int d1,int d2)                       //Function to multiply two polynomials 
{ 
    int d,i,j,s[40]={0}; 
    d=d1+d2; 
    for(i=0;i<=d1;i++) 
    { 
        for(j=0;j<=d2;j++) 
        { 
            s[i+j]+=a[i]*b[j]; 
        } 
    } 
    put_poly(d,s); 
} 
void menu()              //Function to handle user choices 
{ 
    int a[20]={},b[20]={},ch,d1,d2; 
    do 
    { 
    printf("\n1.READ POLYNOMIALS\n2.MULTIPLY  POLYNOMIALS\n3.EXIT\nENTER 
YOUR CHOICE: "); 
    scanf("%d",&ch); 
    switch(ch) 
    { 
        case 1: 
            read_poly(&d1,a); 
            read_poly(&d2,b); 
            break; 
        case 2: 
            mul_poly(a,b,d1,d2); 
            break; 
        case 3: 
            break; 
        default: 
            printf("WRONG CHOICE"); 
    } 
    } while (ch!=3); 
     
} 
int main()                     //Main function  
{ 
    menu();  return 0; 
} 

