/*
17.program to convert an expression from infix expression to postfix using stack
@Farsan_Suneer
Date_of_completion: 05/09/2025
*/
#include<stdio.h>
#include <ctype.h>
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
char pop()       //Function to pop an element from the stack
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
int precedence(char symbol)       // Function to defining precedence of operators
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
void infix_to_postfix(char infix[])        // Function to convert infix expression to postfix expression
{
    int k=-1,i=0;
    char postfix[30];
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))             // if operand (digit/letter), add directly to postfix
        {
        postfix[++k]=infix[i];
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while (top!=-1 && stack[top]!='(')
            {
                postfix[++k]=pop();
            }
            pop();
        }
        else
        {
          while (top!=-1 && precedence(stack[top])>=precedence(infix[i]))
            {
                postfix[++k]=pop();
            }
            push(infix[i]);
        }  
        i++;
    }
      while (top!=-1)          // Pop any remaining operators in stack
        postfix[++k]=pop();

    postfix[++k]='\0';
    printf("Postfix Expression: %s\n", postfix); 
}
void menu()
{
    int ch;
    char infix[20];
    do
    {
       printf("\n1.Infix to Postfix Conversion\n2.EXIT\nEnter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter the Expression: ");
            scanf("%s",infix);
            infix_to_postfix(infix);
            break;
        case 2:
            break;
        default:
            printf("Wrong Choice");
       }
    } while (ch!=2);
}
int main()
{
    menu();
    return 0;
}
