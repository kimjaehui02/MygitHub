#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack
{
	char stack[MAX];
	int top;
}; 

void init_stack(Stack *s)
{
	s->top = -1;
}

bool is_empty(Stack *s)
{
	if(s->top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_full(Stack *s)
{
	if(s->top == (MAX - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(Stack *s, char item)
{
	if(is_full(s))
	{
		fprintf(stderr, "Full!\n");
		return;
	}
	else
	{
		(s->top)++;
		s->stack[s->top] = item;
		printf("%c is pushed\n", item);
	}

}

int pop(Stack *s)
{
	int temp;

	if(is_empty(s))
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);

	}
	else
	{
		temp = s->stack[s->top];
		(s->top)--;
		printf("%c is popped\n", temp);

		return temp;
	}
}

bool check_matching(const char *in)
{
	Stack s;
	char ch, open_ch;
	int n = strlen(in);
	int i = 0;

	init_stack(&s);

	for(i = 0; i < n; i++)
	{
		ch = in[i];

		switch(ch)
		{
		case '(': 
		case '[':
		case '{':
			push(&s, ch);
			break;

		case ')':
		case ']': 
		case '}':
			if(is_empty(&s))
			{
				return false;
			}
			else
			{
				open_ch = pop(&s);

				if((open_ch == '(' && ch != ')') ||
				   (open_ch == '[' && ch != ']') ||
				   (open_ch == '{' && ch != '}'))
				{
					return false;
				}
				break;
			}

		}

		//if(!is_empty(&s))
		//{
		//	return false;
		//}


	}

	return true;
}

int main()
{
	char p[] = "()";
	const char *input[6] = { "()" ,
						     ")(" ,
							 "{3+(2*5)}",
                             "{}",
                             "{3*4+(6)",
                             "({2+5)}"};

	//char *p = pp;

	for(int i = 0; i < 6; i++)
	{
		if(check_matching(input[i]) == true)
		{
			printf("%s : success\n", input[i]);
		}
		else
		{
			printf("%s : failure\n", input[i]);
		}
	}



	system("pause");

	return 0;
}
