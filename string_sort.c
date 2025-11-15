/*
15.program to read n Strings and display them in the ascending order.
@Farsan_Suneer
Date_of_completion: 27/07/2025
*/
#include <stdio.h>
#include <string.h>
void readstr(char a[50][50],int n) //function to read the strings
{
	int i;
    printf("Enter the strings:\n");
    for(i=0;i<n;i++)
    	{
       	 scanf("%s",a[i]);
    	}
}
void sort(char a[50][50],int n) //function to sort the strings in ascending order
{
    int i,j;
    char temp[50];
    for(i=0;i<n-1;i++) 
	{
        for(j=0;j<n-i-1;j++) 
		{
            if(strcmp(a[j],a[j+1])>0) 
			{
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }
    printf("ASCENDING ORDER:\n");
    for(i=0;i<n;i++)
    	{
      	  printf("%s\n",a[i]);
    	}
}
void menu() //function to handle user choices
{
	int ch,n;
	char a[50][50];
	do
	{
		printf("\n1.ENTER STRINGS\n2.ASCENDING ORDER\n3.EXIT\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the number of strings: ");
                scanf("%d",&n);
				readstr(a,n);
				break;
			case 2:
				sort(a,n);
				break;
			case 3:
				break;
			default:
				printf("INVALID CHOICE\n");
		}
	}while(ch!=3); //menu displayed until user choose to exit
}
int main() //main function
{
    menu();
    return 0;
}


