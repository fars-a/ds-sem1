/*
18.program to convert an expression from infix expression to prefix using stack
@Farsan_Suneer
Date_of_completion: 05/09/2025
*/
#include<stdio.h>
#include <ctype.h>
#include<string.h>
#define SIZE 50
char stack[SIZE];
int top = -1;
void push(char e)     // Function to push an element onto the stack
{
    if(top==SIZE-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top]=e;
    }
}
char pop()    // Function to pop an element from the stack
{
    if(top==-1)
    {
        printf("Stack Underflow");
        return '\0';
    }
    else
    {
       return stack[top--];
    } 
}
int precedence(char symbol)  // Function to return precedence of operators
{
    switch (symbol) 
    {
      case '^': 
            return 3;
      case '*': 
      case '/': 
            return 2;
      case '+': 
      case '-':
            return 1;
      default: 
            return 0;
    }
}
void reverse(char str[])   // Function to reverse a string
{
	int i;
    int len=strlen(str);
    for(i=0;i<len/2;i++) 
	{
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}
void infix_to_prefix(char infix[])  // Function to convert an infix expression to prefix
{
    int k=-1,i=0;
    char prefix[30];
    reverse(infix);
    while(infix[i]!='\0')
    {
    	if(infix[i]=='(')
    	{
    		infix[i]=')';
		}
		else if(infix[i]==')')
		{
			infix[i]='(';
		}
		i++;
	}
	i=0;    //Convert the modified infix to postfix
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
        prefix[++k]=infix[i];
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while (top!=-1 && stack[top]!='(')
            {
                prefix[++k]=pop();
            }
            pop();
        }
        else
        {
          while (top!=-1 && precedence(stack[top])>=precedence(infix[i]))
            {
                prefix[++k]=pop();
            }
            push(infix[i]);
        }  
        i++;
    }
      while (top!=-1)       //Pop remaining operators from stack
        prefix[++k]=pop();

    prefix[++k]='\0';
    reverse(prefix);      //Reverse postfix result to get prefix
    printf("prefix Expression: %s\n", prefix); 
}
void menu()     // Menu function for user interaction
{
    int ch;
    char infix[20];
    do
    {
       printf("\n1.Infix to prefix Conversion\n2.EXIT\nEnter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter the Expression: ");
            scanf("%s",infix);
            infix_to_prefix(infix);
            break;
        case 2:
            break;
        default:
            printf("Wrong Choice");
       }
    } while (ch!=2);
}
int main()    // Main function
{
    menu();
    return 0;
}
