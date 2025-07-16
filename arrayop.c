/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
int a[5],pos=-1,temp=0,i=0,j=0;;
void insert(int e)
{
	if(pos+1==5)
	{
		printf("ERROR:array is full");
	}
	else
	{
		a[++pos]=e;
	}
}
void delete()
{
	if(pos==-1)
	{
		printf("ERROR:array is empty");
	}
	else
	{
		printf("\n%d",a[pos--]);
	}
}
int menu()
{
	int c;
	printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.SORT\n5.EXIT\nENETR YOUR CHOICE: ");
	scanf("%d",&c);
	return c;
}
void display()
{
	int i;
	for(i=0;i<=pos;i++)
	{
		printf("a[%d]=%d",i,a[i]);
	}
	printf("\n");
}
void sort()
{
   
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<=4;j++)
        {
            if(a[i]>=a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    	for(i=0;i<=4;i++)
	{
		printf("\t%d\t",a[i]);
	}
}
void processArray()
{
	int ch,c;
	int pos=-1;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1: 
			      printf("Enter the value to be inserted: ");
			      scanf("%d",&c);
			      insert(c);
			      break;
			case 2:
				  delete(pos);
				  break;
			case 3:
				  display();
				  break;
			case 4:
				  sort();
				  break;
			default:
				  printf("ERROR: wrong choice");
				  break;
		}
}
}
int main()
{
	processArray();
	return 0;
}
