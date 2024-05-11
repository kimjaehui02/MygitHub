#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char* data;
	/// <summary>
	/// ����
	/// </summary>
	struct node* linkL;
	/// <summary>
	/// ������
	/// </summary>
	struct node* linkR;
} Node;

/// <summary>
/// 1������Ʈ�� ������ �߰� (���� ��� ��� �ٷ� �������߰�)
/// </summary>
/// <param name="head"></param>
/// <param name="item"></param>
/// <returns></returns>
void add_node(Node *head, char* str)
{

	// ���� ���� ���� ��带 �����
	// ��ũL�� �����̳�带
	// ��ũR�� �����̳���� ��ũR�� �ִ´�

	Node* AddNode = (Node*)malloc(sizeof(Node));
	if (AddNode ==NULL)
	{
		exit(1);
	}

	// ��尡 ������ ���̸� �������ɴϴ�
	if (AddNode == NULL)
	{
		exit(1);
	}


	AddNode->data = str;
	AddNode->linkL = head;
	AddNode->linkR = head->linkR;

	head->linkR->linkL = AddNode;
	head->linkR = AddNode;


	//return head;
}

/// <summary>
/// 2�� p �����Ͱ� ����Ű�� ��带 ����Ʈ���� ����
/// </summary>
/// <param name="head"></param>
/// <param name="p"></param>
/// <returns></returns>
void delete_node(Node* head, Node* p)
{
	while (head->linkR->data != NULL)
	{

		if (head->linkR == p)
		{
			Node* dummy = head->linkR;
			head->linkR->linkR->linkL = head;
			head->linkR = head->linkR->linkR;
			free(dummy);
			dummy = NULL;

			printf("���� �Ϸ�\n");

			return;
		}

		head = head->linkR;
	}

	printf("������ �ּҸ� ã�� ���߽��ϴ�");

}

/// <summary>
/// 3��item�� ����Ʈ �ȿ� �ִ����� �˻��Ͽ�, ������TRUE(1)�� �����ϰ� ������ FALSE(0)�� ��ȯ
/// </summary>
/// <param name="head"></param>
/// <param name="str"></param>
/// <returns></returns>
bool is_in_list(Node* head, char* str)
{
	bool test = false;
	//printf(" ������ %s, �����ʹ� %s, %d", str, head->linkR->data, strcmp(head->linkR->data, str));

	//�ǵ� ���̳����� �ݺ��մϴ�
	while (head->linkR->data !=NULL)
	{

		if (strcmp(head->linkR->data , str) == 0)
		{
			printf("%s ã��", str);
			test = true;
			break;
		}


		head = head->linkR;
	}


	return test;
}

/// <summary>
/// 4�� ����Ʈ���� ��� ������ ��ȯ (���� ��� ����)
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
int count_list(Node* head)
{
	int num =0;
	//�ǵ� ���̳����� �ݺ��մϴ�
	while (head->linkR->data != NULL)
	{
		num++;


		head = head->linkR;
	}

	return num--;
}

/// <summary>
/// 5��  ����Ʈ�� ��������� �˻��Ͽ�, ������� TRUE (1)�� ��ȯ�ϰ� �������� �����ϸ� FALSE(0)�� ��ȯ
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
bool is_empty(Node* head)
{
	if (head->linkR->data == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

/// <summary>
/// 6������Ʈ���� ��� �����͵��� ��� ��� �������� ��� (��, �����ֱ� ����� �ۺ��� ���)
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
void print_list(Node* head)
{
	// �����Ͱ� �� ���� �������� ��� �ѱ�ϴ�
	if (head->data == NULL)
	{
		// �ٵ� ������ ���� �����ʹ� �ٷ� ������ �մϴ�
		if (head->linkR == NULL)
		{
			printf("\n �������Դϴ�");
			return;
		}


	}
	if (head->data != NULL)
	{
		printf("%s, ", head->data);
	}


	print_list(head->linkR);
	return;
}

/// <summary>
/// 7������Ʈ���� ��� �����͵��� ���ʴ�� �˻��ؼ� str ���� ��ġ�ϴ� ��尡 ������ �ش� ����� �ּҸ� ��ȯ; ��ġ�ϴ� ��尡 ���� ��� NULL ��ȯ
/// </summary>
/// <param name="head"></param>
/// <param name="str"></param>
/// <returns></returns>
Node* search(Node* head, char* str)
{
	bool test = false;
	//printf(" ������ %s, �����ʹ� %s, %d", str, head->linkR->data, strcmp(head->linkR->data, str));

	//�ǵ� ���̳����� �ݺ��մϴ�
	while (head->linkR->data != NULL)
	{

		if (strcmp(head->linkR->data, str) == 0)
		{
			printf("%s ã��", str);
			test = true;
			break;
		}


		head = head->linkR;
	}
	if (test == true)
	{
		printf("�ش� ����� �ּҴ� %p �Դϴ�", head->linkR);
		return head->linkR;
	}
	else
	{
		printf("�ش� �ּҸ� ã�� ���߽��ϴ�");
	}

	return NULL;
}


int main()
{
	printf("�����մϴ�");
	printf("\n");

	Node* Header = NULL;
	Node* Trailer = NULL;

	Header = (Node*)malloc(sizeof(Node));
	Trailer = (Node*)malloc(sizeof(Node));

	if(Header != NULL)
	{
		Header->data = NULL;
		Header->linkL = NULL;
		Header->linkR = Trailer;

	}


	if (Trailer != NULL)
	{
		Trailer->data = NULL;
		Trailer->linkL = Header;
		Trailer->linkR = NULL;

	}


	int numOfSwich = 0;
	Node* delNode = NULL;
	while (1)
	{
		char* Input = (char*)malloc(sizeof(char) * 100);
		numOfSwich = 0;
		printf("\n");
		printf("1. Add, 2. Del, 3. is_in_list, 4. count_list, 5. is_empty, 6. print_list, 7. search :");
		scanf_s("%d", &numOfSwich);
		switch (numOfSwich)
		{
		case 1:
			printf("���� ������ �̸��� �Է��ϼ��� ");
			scanf_s("%s", Input, 100);
			add_node(Header, Input) ;
			break;
		case 2:			
			if (delNode == NULL)
			{
				printf("������ �ּҰ� ����ֽ��ϴ� ������ �ּҸ� ���� ã���ʽÿ�\n");
			}
			else 
			{
				delete_node(Header, delNode);
			}

			break;
		case 3:	
			printf("ã�� ������ �̸��� �Է��ϼ��� ");
			scanf_s("%s", Input, 100);
			if (is_in_list(Header, Input) == true)
			{
				printf("����Ʈ�� ���� �ֽ��ϴ�");
			}
			  else
			{
				printf("����Ʈ�� ���� �����ϴ�");
			}
			break;
		case 4:
			printf("\n������ %d�� �Դϴ�\n", count_list(Header));
			break;
		case 5:
			if (is_empty(Header) == true)
			{
				printf("����Ʈ�� ������ϴ�");
			}
			else
			{
				printf("����Ʈ�� ���� �ֽ��ϴ�");
			}
			break;
		case 6:
			print_list(Header);
			break;
		case 7:
			printf("ã�� ������ �̸��� �Է��ϼ��� ");
			scanf_s("%s", Input, 100);
			delNode = search(Header, Input);
			break;

		default:
			break;
		}

	}



	return 0;
}