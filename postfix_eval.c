#include<stdio.h>
#include <ctype.h>
#define SIZE 50
int stack[SIZE];
int top=-1;
void push(char e)       // Function to push an element onto the stack
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
char pop()     // Function to pop an element from the stack
{
    if(top==-1)
    {
        printf("Stack Underflow");
        return 0;
    }
    else
    {
       return stack[top--];
    }
}
int precedence(char symbol)    // Function to return precedence of operators
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
void infix_to_postfix(char infix[],char postfix[])       // Function to convert an infix expression to postfix
{
    int k=-1,i=0;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
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
      while (top!=-1)
      postfix[++k]=pop();

    postfix[++k]='\0';
    printf("Postfix Expression: %s\n", postfix); 
}
void evaluate_postfix(char postfix[])    // Function to evaluate a postfix expression
{
    int i,a,b;
    for(i=0;postfix[i]!='\0';i++) 
	{
        if(isdigit(postfix[i]))      // If operand, push it to stack
		{ 
            push(postfix[i]-'0');
        } 
		else
		{
            b=pop();    // Pop second operand
            a=pop();    // Pop first operand
            switch(postfix[i]) 
			{
                case '+':
				    push(a+b); 
				    break;
                case '-':
				    push(a-b); 
					break;
                case '*':
				    push(a*b); 
					break;
                case '/':
				    push(a/b); 
					break;
            }
        }
    }
    printf("Result=%d\n",pop());
}
void menu()     // Menu function to interact with user
{
    int ch;
    char infix[20],postfix[30];
    do
    {
       printf("\n1.Postfix Evaluation\n2.EXIT\nEnter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter the Expression: ");
            scanf("%s",infix);
            infix_to_postfix(infix,postfix);
            evaluate_postfix(postfix);
            break;
        case 2:
            break;
        default:
            printf("Wrong Choice");
       }
    } while (ch!=2);
}
int main()     //Main function
{
    menu();
    return 0;
}
