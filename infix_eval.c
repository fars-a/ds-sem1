#include<stdio.h>
#include<ctype.h>
int precedence(char symbol)     // Function to return precedence of operators
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
int operation(int a,int b,char symbol)   // Function to perform arithmetic operations
{
	switch(symbol)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}
void infix_evaluation(char expr[])     // Function to evaluate an infix expression using two stacks
{
	int i=0,vstack[100],vtop=-1,otop=-1,a,b,op;
	char ostack[100];
	while(expr[i]!='\0')
	{
		if(isdigit(expr[i]))
		{
			vstack[++vtop]=expr[i]-'0';
		}
		else if(expr[i]=='(')
		{
			ostack[++otop]=expr[i];
		}
		else if(expr[i]==')')
		{
			while(otop!=-1 && ostack[otop]!='(')
			{
				b=vstack[vtop--];
				a=vstack[vtop--];
				op=ostack[otop--];
				vstack[++vtop]=operation(a,b,op);
			}
			if(otop!=-1 && ostack[otop]=='(')
			{
				otop--;
			}
		}
		else    // pop operators of higher or equal precedence
		{
			while(otop>=-1 && precedence(ostack[otop])>=precedence(expr[i]))
			{
				b=vstack[vtop--];
				a=vstack[vtop--];
				op=ostack[otop--];
				vstack[++vtop]=operation(a,b,op);
			}
			ostack[++otop]=expr[i];
		}
		i++;
	}
	while(otop!=-1)     	// pop remaining operators
	{
			b=vstack[vtop--];
			a=vstack[vtop--];
			op=ostack[otop--];
			vstack[++vtop]=operation(a,b,op);
	}
	printf("Result=%d\n",vstack[vtop]);
}
void menu()    // Menu-driven function for user input
{
    int ch;
    char expr[20];
    do
    {
       printf("\n1.Infix Evaluation \n2.EXIT\nEnter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
        case 1:
            printf("Enter the Expression: ");
            scanf("%s",expr);
            infix_evaluation(expr);
            break;
        case 2:
            break;
        default:
            printf("Wrong Choice");
       }
    } while (ch!=2);
}
int main()       // Main function
{
	menu();
	return 0;
}
