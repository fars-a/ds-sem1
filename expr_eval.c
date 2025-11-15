 
/*(In the sequence "E A S * Y * Q U E * * * S T * * * I O * N * * *", letters push onto a stack 
and * pops; give the pop results.) 
@Farsan_Suneer 
Roll no: 26 
Date: 15-09-2025 
*/
#include<stdio.h>
#include <ctype.h>
#define SIZE 50
char stack[SIZE];
int top = -1;
void push(char e)    // Function to push a character onto the stack
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
char pop()     // Function to pop a character from the stack
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
void process_expr(char expr[])   // Function to process the input 
{
    int k=-1,i=0;
    char result[30];
    printf("Resultant Expression: "); 
    while(expr[i]!='\0')
    {
        if(expr[i]=='*')
        {
            char val = pop();
            if(val!='\0')
               printf("%c ",val);
        }
        else 
        {
            push(expr[i]);
        }
        i++;
    }
      while (top!=-1)   // Pop remaining elements
        result[++k]=pop();

    result[++k]='\0';
}
void menu()   // Menu function to take user input 
{
    int ch;
    char expr[20];
    do
    {
       printf("\n1.Enter the Expression \n2.EXIT\nEnter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter the Expression: ");
            scanf("%s",expr);
            process_expr(expr);
            break;
        case 2:
            break;
        default:
            printf("Wrong Choice");
       }
    } while (ch!=2);
}
int main()   //Main function
{
    menu();
    return 0;
}
