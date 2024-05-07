
#define _CRT_SECURE_NO_WARNINGS

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

bool Palindrome(Stack *s, char *p)
{
	// Ȧ���� ¦���� �����ϴ�

	// ¦���� ������ �ɰ� �ΰ��� �����մϴ�

	// Ȧ���� ����Ÿ� �����ϰ� �ɰ��� �ΰ��� �����մϴ�

	int i = 0; 


	while(i < strlen(p))
	{
		char charOfStack = p[i];

		if(charOfStack >= 'a' && charOfStack <= 'z')
		{
			push(s, charOfStack);
		}
		else if(charOfStack >= 'A' && charOfStack <= 'Z')
		{
			push(s, charOfStack + 32);
		}
		i ++;

	}

	


	//push(s, '\n');

	// �˻��մϴ�
	bool Ok = true;


	//int sizeOfStack = sizeof(s->stack);

	// 0�Ǵ� 1�Դϴ�
	//if(s->top == 0)
	//{
	//	return Ok;
	//}
	//
	
	

	if(s->top == 1)
	{
		if(s->stack[0] == s->stack[1])
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	// ¦���Դϴ�
	if(s->top %2 == 0)
	{

		for(int i =0; i< s->top /2; i++)
		{

			char check = s->stack[i];
			char check2 = s->stack[s->top - i];
			if(check != check2)
			{
				Ok = false;
			}
		}
	}

	// Ȧ���Դϴ�
	if(s->top %2 == 1)
	{
		for(int i = 0; i < (s->top / 2) -1; i++)
		{
			char check = s->stack[i];
			char check2 = s->stack[s->top - i];
			if(check != check2)
			{
				Ok = false;
			}
		}
	}


	return Ok;

}

int main()
{
	char *p = new (char[100]);
	printf("Enter a string:");
	scanf("%s", p);

	Stack s;
	init_stack(&s);

	if(Palindrome(&s, p) == true)
	{
		printf("����");
	}
	else
	{
		printf("����");
	}


	system("pause");

	delete[] p;
	p = nullptr;

	return 0;
}

