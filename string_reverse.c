/*
13.program to read a String and Just print it in the reverse order
@Farsan_Suneer
Date_of_completion: 27/07/2025
*/
#include<stdio.h>
#include<string.h>
void readstr(char a[]) //function to read string from the user
{
	printf("Enter the sring: ");
	gets(a);
}
void printstr(char a[]) //function to print the entered string
{
	printf("%s",a);
}
void reverse(char a[]) //function to reverse the string
{
	int i,l=0;
	l=strlen(a); //find length of the string
	for(i=l-1;i>=0;i--)
	{
		printf("%c",a[i]); //printing the reverse of the string
	}
}
void menu() //function to handle user choices
{
	int ch;
	char a[10];
	do
	{
		printf("\n\n1.ENTER STRING\n2.DISPLAY STRING\n3.REVERSE\n4.EXIT\nEnter Your Choice: ");
		scanf("%d",&ch);
		getchar();
		switch(ch)
		{
			case 1:
				readstr(a);
				break;
			case 2:
				printstr(a);
				break;
			case 3:
				reverse(a);
				break;
			case 4:
				break;
			default:
				printf("INVALID CHOICE\n");
		}
	}while(ch!=4); //menu displayed until user choose to exit
}
int main() //main function
{
	menu();
	return 0;
}
