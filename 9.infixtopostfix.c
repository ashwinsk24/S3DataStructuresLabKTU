#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char infixstr[20],postfixstr[20];
int tos = -1;
char stack[50];
int n=50;
char pop();
int is_operator(char op);
int op_priority(char op);
int is_Empty();
void infixtopostfix();
void push(char op);

void push(char item)
{
	if(tos >= n-1)
	{
		printf("\nStack Overflow. ");
	}
	else
	{
		tos = tos + 1;
		stack[tos] = item;
	}
}

char pop()
{
	char item ;

	if(tos==-1)
	{
		printf("\nStack underflow. ");
  }
	else
	{
		item = stack[tos];
		tos = tos-1;
		return(item);
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int op_priority(char symbol)
{

	if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void infixtopostfix(char infixstr[], char postfixstr[])
{
	int i, j;
	char item;
	char x;
	push('(');
	strcat(infixstr,")");

	i=0;
	j=0;
	item=infixstr[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfixstr[j] = item;
					j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && op_priority(x)>= op_priority(item))
			{
				postfixstr[j] = x;
				j++;
				x = pop();
			}
			push(x);


			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfixstr[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;
		item = infixstr[i];
	}
	if(tos>0)
	{
		printf("\nInvalid infix Expression.\n");
		exit(1);
	}
	if(tos>0)
	{
		printf("\nInvalid infix Expression.\n");
	}
	postfixstr[j] = '\0';
}

int main()
{
	char infix[50], postfix[50];
	printf("\nEnter Infix expression : ");
	gets(infix);
	infixtopostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);

	return 0;
}
