#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int top=-1, stack[100];

void push(int n)
{
	stack[++top]=n;
}

int pop()
{
	return stack[top--];
}

int val(int a, int b, char c)
{
	if(c=='+')
	return a+b;
	else if(c=='-')
	return a-b;
	else if(c=='*')
	return a*b;
	else if(c=='/')
	return a/b;
	else
	return a^b;
}

int main()
{
	char exp[100], num[10];
	int i=0, p, a, b;
	printf("Enter the expression: ");
	gets(exp);
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
		{
			p=0;
			while(1)
			{
				num[p++]=exp[i++];
				if(exp[i]==' ')
				break;
			}
			num[p]='\0';
			push(atoi(num));
		}
		else if(exp[i]== ' ')
		i++;
		else
		{
			b=pop();
			a=pop();
			push(val(a,b,exp[i++]));
		}
	}
	printf("Value of the expression: %d", pop());
	return 0;
}

