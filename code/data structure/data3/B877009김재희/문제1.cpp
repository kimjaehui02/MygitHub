#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* link;
} Node;

// 경우의 수

// 1. 헤드가 비어있을 경우
// 2. 헤드가 비어있지 않을 경우
Node* add_node(Node *head, int item)
{

	//printf("\n");
	//printf("에드 실행");
	// 헤드가 비어있는지 체크합니다
	if (head == NULL)
	{
		//printf("\n");
		//printf("에드 널");
		head = (Node*)malloc(sizeof(Node));
		
		// 헤드가 아직도 널이면 빠져나옵니다
		if (head == NULL)
		{
			exit(1);
		}

		head->data = item;
		head->link = NULL;

	}
	// 뭔가 있다면 다음으로 넘깁니다
	else
	{
		//printf("\n");
		//printf("에드 링크로이동");
		// 인풋 받은게 현 값보다 작을때만 실시합니다
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
		// 아니면 평범하게 합니다
		else
		{
			head->link = add_node(head->link, item);
		}



	}

	
	//printf("\n");
	//printf("에드 종료");
	//
	return head;
}


// 경우의 수

// 1. 헤드의 유무
// 2. 아이템의 같음과 다름
// 3. 다음 링크의 유무
Node* delete_node(Node* head, int item)
{
	// 1. 헤드의 유무
	if (head == NULL)
	{
		return NULL;

	}

	// 2. 아이템과 같은지 판단

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
	// 대입받은 노드가 비어있는지를 체크합니다
	if (head == NULL)
	{
		// 널이라면 그대로 널을 반환하고 끝냅니다
		return NULL;
	}
	else
	{
		// 그 링크의 노드값도 초기화를 해줍니다
		head->link = clear(head->link);

	}

	// 그다음 자기 자신을 메모리 해제합니다
	free(head);
	head = NULL;
	return NULL;
}

/// <summary>
/// 4번째item이 리스트 안에 있는지를 검사하여, 있으면TRUE(1)를 리턴하고 없으면 FALSE(0)를 반환
/// </summary>
/// <param name="head"></param>
/// <param name="item"></param>
/// <returns></returns>
bool is_in_list(Node* head, int item)
{
	// 하나라도 나왔는지 검사하기위해 불값을 넣습니다
	bool test = false;

	// 1. 헤드의 유무
	if (head == NULL)
	{
		//printf("\n");
		//printf("빈칸에 도달했습니다");
		return false;

	}
	//printf("%d입니다 ", head->data);
	// 2. 아이템과 같은지 판단
	if (head->data == item)
	{
		//printf("\n1호기 %d %d\n", head->data, item);
		test = true;


	}

	if (is_in_list(head->link, item) == true)
	{
		//printf("\n2호기 %d %d\n", head->link->data, item);
		test = true;
	}

	return test;
}

/// <summary>
/// 5번째
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
/// 6번째
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
/// 7번째
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
Node* print_list(Node* head)
{
	
	//printf("\n");
	//printf("리스트 실행");
	if (head == NULL)
	{
		printf("\n");
		printf("끝 입니다");
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
	printf("시작합니다");
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
			printf("Add함수입니다:");
			printf("\n");
			
			scanf_s("%d", &intput);
			node = add_node(node, intput);
			break;
		case 2:
			printf("delete함수입니다:");
			printf("\n");

			scanf_s("%d", &intput);
			node = delete_node2(node, intput);
			break;
			
		case 3:
			printf("전부 지웠습니다");
			node = clear(node);
			break;
		case 4:			
			printf("안에 있는지를 찾는 함수입니다:");
			printf("\n");

			scanf_s("%d", &intput);
			//printf("인풋은 %d 입니다", intput);
			if (is_in_list(node, intput))
			{
				printf("안에 있습니다");
			}
			else
			{
				printf("안에 없습니다");
			}
			break;

		case 5:
			printf("갯수는 %d입니다", count_list(node));

			break;

		case 6:

			if (is_empty(node) == false)
			{
				printf("리스트가 있습니다");
			}
			else
			{
				printf("리스트가 없습니다");
			}
			break;
		case 7:
			printf("\n 리스트의 내용물은 ");
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