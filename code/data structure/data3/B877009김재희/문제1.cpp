#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* link;
} Node;

// ����� ��

// 1. ��尡 ������� ���
// 2. ��尡 ������� ���� ���
Node* add_node(Node *head, int item)
{

	//printf("\n");
	//printf("���� ����");
	// ��尡 ����ִ��� üũ�մϴ�
	if (head == NULL)
	{
		//printf("\n");
		//printf("���� ��");
		head = (Node*)malloc(sizeof(Node));
		
		// ��尡 ������ ���̸� �������ɴϴ�
		if (head == NULL)
		{
			exit(1);
		}

		head->data = item;
		head->link = NULL;

	}
	// ���� �ִٸ� �������� �ѱ�ϴ�
	else
	{
		//printf("\n");
		//printf("���� ��ũ���̵�");
		// ��ǲ ������ �� ������ �������� �ǽ��մϴ�
		if (head->data > item)
		{
			Node* dummy = (Node*)malloc(sizeof(Node));
			if (dummy == NULL)
			{
				
				exit(1);
			}

			dummy->data = item;
			dummy->link = head;
			head = dummy;

		}
		// �ƴϸ� ����ϰ� �մϴ�
		else
		{
			head->link = add_node(head->link, item);
		}



	}

	
	//printf("\n");
	//printf("���� ����");
	//
	return head;
}


// ����� ��

// 1. ����� ����
// 2. �������� ������ �ٸ�
// 3. ���� ��ũ�� ����
Node* delete_node(Node* head, int item)
{
	// 1. ����� ����
	if (head == NULL)
	{
		return NULL;

	}

	// 2. �����۰� ������ �Ǵ�

	if (head->data == item)
	{


		if (head->link != NULL)
		{
			Node* dummy = head;
			head = head->link;
			free(dummy);
			dummy = NULL;


			//return head;
		}
		else
		{
			head->link = delete_node(head->link, item);
			return NULL;
		}

	}

	head->link = delete_node(head->link, item);
	head->link = delete_node(head->link, item);



	return head;
}

Node* delete_node2(Node* head, int item)
{
	head = delete_node(head, item);
	head = delete_node(head, item);
	return head;
}


Node* clear(Node* head)
{
	// ���Թ��� ��尡 ����ִ����� üũ�մϴ�
	if (head == NULL)
	{
		// ���̶�� �״�� ���� ��ȯ�ϰ� �����ϴ�
		return NULL;
	}
	else
	{
		// �� ��ũ�� ��尪�� �ʱ�ȭ�� ���ݴϴ�
		head->link = clear(head->link);

	}

	// �״��� �ڱ� �ڽ��� �޸� �����մϴ�
	free(head);
	head = NULL;
	return NULL;
}

/// <summary>
/// 4��°item�� ����Ʈ �ȿ� �ִ����� �˻��Ͽ�, ������TRUE(1)�� �����ϰ� ������ FALSE(0)�� ��ȯ
/// </summary>
/// <param name="head"></param>
/// <param name="item"></param>
/// <returns></returns>
bool is_in_list(Node* head, int item)
{
	// �ϳ��� ���Դ��� �˻��ϱ����� �Ұ��� �ֽ��ϴ�
	bool test = false;

	// 1. ����� ����
	if (head == NULL)
	{
		//printf("\n");
		//printf("��ĭ�� �����߽��ϴ�");
		return false;

	}
	//printf("%d�Դϴ� ", head->data);
	// 2. �����۰� ������ �Ǵ�
	if (head->data == item)
	{
		//printf("\n1ȣ�� %d %d\n", head->data, item);
		test = true;


	}

	if (is_in_list(head->link, item) == true)
	{
		//printf("\n2ȣ�� %d %d\n", head->link->data, item);
		test = true;
	}

	return test;
}

/// <summary>
/// 5��°
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
int count_list(Node* head)
{
	int number = 0;

	if(head == NULL)
	{
		return 0;
	}
	number++;
	if (head->link != NULL)
	{

		number += count_list(head->link);
	

	}


	return number;
}

/// <summary>
/// 6��°
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
bool is_empty(Node* head)
{
	if (head == NULL)
	{
		return true; 
	}

	return false;
}

/// <summary>
/// 7��°
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
Node* print_list(Node* head)
{
	
	//printf("\n");
	//printf("����Ʈ ����");
	if (head == NULL)
	{
		printf("\n");
		printf("�� �Դϴ�");
	}
	else
	{
		//printf("\n");
		printf("%d, ", head->data);
		print_list(head->link);
	}

	return head;
}

int main()
{
	printf("�����մϴ�");
	printf("\n");

	Node* node = NULL;

	while (true)
	{
		printf("\n 1. Add; 2. Delete; 3. Clear; 4. is_in_list; 5. count_list; 6. is_empty; 7. print_list;");
		int inputttttt;
		int intput;
		scanf_s("%d", &inputttttt);
		switch (inputttttt)
		{
		case 1:
			printf("Add�Լ��Դϴ�:");
			printf("\n");
			
			scanf_s("%d", &intput);
			node = add_node(node, intput);
			break;
		case 2:
			printf("delete�Լ��Դϴ�:");
			printf("\n");

			scanf_s("%d", &intput);
			node = delete_node2(node, intput);
			break;
			
		case 3:
			printf("���� �������ϴ�");
			node = clear(node);
			break;
		case 4:			
			printf("�ȿ� �ִ����� ã�� �Լ��Դϴ�:");
			printf("\n");

			scanf_s("%d", &intput);
			//printf("��ǲ�� %d �Դϴ�", intput);
			if (is_in_list(node, intput))
			{
				printf("�ȿ� �ֽ��ϴ�");
			}
			else
			{
				printf("�ȿ� �����ϴ�");
			}
			break;

		case 5:
			printf("������ %d�Դϴ�", count_list(node));

			break;

		case 6:

			if (is_empty(node) == false)
			{
				printf("����Ʈ�� �ֽ��ϴ�");
			}
			else
			{
				printf("����Ʈ�� �����ϴ�");
			}
			break;
		case 7:
			printf("\n ����Ʈ�� ���빰�� ");
			print_list(node);
			break;

		default:
			printf("???:");
			printf("%d", (int)inputttttt);
			break;
		}

	}

	return 0;
}