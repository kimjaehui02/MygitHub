#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char* data;
	/// <summary>
	/// 왼쪽
	/// </summary>
	struct node* linkL;
	/// <summary>
	/// 오른쪽
	/// </summary>
	struct node* linkR;
} Node;

/// <summary>
/// 1번리스트에 데이터 추가 (더미 헤드 노드 바로 다음에추가)
/// </summary>
/// <param name="head"></param>
/// <param name="item"></param>
/// <returns></returns>
void add_node(Node *head, char* str)
{

	// 먼저 새로 넣을 노드를 만든다
	// 링크L에 헤드더미노드를
	// 링크R에 헤드더미노드의 링크R을 넣는다

	Node* AddNode = (Node*)malloc(sizeof(Node));
	if (AddNode ==NULL)
	{
		exit(1);
	}

	// 헤드가 아직도 널이면 빠져나옵니다
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
/// 2번 p 포인터가 가리키는 노드를 리스트에서 삭제
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

			printf("제거 완료\n");

			return;
		}

		head = head->linkR;
	}

	printf("삭제할 주소를 찾지 못했습니다");

}

/// <summary>
/// 3번item이 리스트 안에 있는지를 검사하여, 있으면TRUE(1)를 리턴하고 없으면 FALSE(0)를 반환
/// </summary>
/// <param name="head"></param>
/// <param name="str"></param>
/// <returns></returns>
bool is_in_list(Node* head, char* str)
{
	bool test = false;
	//printf(" 대입은 %s, 데이터는 %s, %d", str, head->linkR->data, strcmp(head->linkR->data, str));

	//맨뒤 더미노드까지 반복합니다
	while (head->linkR->data !=NULL)
	{

		if (strcmp(head->linkR->data , str) == 0)
		{
			printf("%s 찾음", str);
			test = true;
			break;
		}


		head = head->linkR;
	}


	return test;
}

/// <summary>
/// 4번 리스트내의 노드 개수를 반환 (더미 노드 제외)
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
int count_list(Node* head)
{
	int num =0;
	//맨뒤 더미노드까지 반복합니다
	while (head->linkR->data != NULL)
	{
		num++;


		head = head->linkR;
	}

	return num--;
}

/// <summary>
/// 5번  리스트가 비었는지를 검사하여, 비었으면 TRUE (1)를 반환하고 아이템이 존재하면 FALSE(0)를 반환
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
/// 6번리스트내의 노드 데이터들을 헤드 노드 다음부터 출력 (즉, 가장최근 사용한 앱부터 출력)
/// </summary>
/// <param name="head"></param>
/// <returns></returns>
void print_list(Node* head)
{
	// 데이터가 빈 더미 데이터일 경우 넘깁니다
	if (head->data == NULL)
	{
		// 근데 마지막 더미 데이터는 바로 끝내야 합니다
		if (head->linkR == NULL)
		{
			printf("\n 마지막입니다");
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
/// 7번리스트내의 노드 데이터들을 차례대로 검색해서 str 값과 일치하는 노드가 있으면 해당 노드의 주소를 반환; 일치하는 노드가 없을 경우 NULL 반환
/// </summary>
/// <param name="head"></param>
/// <param name="str"></param>
/// <returns></returns>
Node* search(Node* head, char* str)
{
	bool test = false;
	//printf(" 대입은 %s, 데이터는 %s, %d", str, head->linkR->data, strcmp(head->linkR->data, str));

	//맨뒤 더미노드까지 반복합니다
	while (head->linkR->data != NULL)
	{

		if (strcmp(head->linkR->data, str) == 0)
		{
			printf("%s 찾음", str);
			test = true;
			break;
		}


		head = head->linkR;
	}
	if (test == true)
	{
		printf("해당 노드의 주소는 %p 입니다", head->linkR);
		return head->linkR;
	}
	else
	{
		printf("해당 주소를 찾지 못했습니다");
	}

	return NULL;
}


int main()
{
	printf("시작합니다");
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
			printf("더할 어플의 이름을 입력하세요 ");
			scanf_s("%s", Input, 100);
			add_node(Header, Input) ;
			break;
		case 2:			
			if (delNode == NULL)
			{
				printf("삭제할 주소가 비어있습니다 어플의 주소를 먼저 찾으십시오\n");
			}
			else 
			{
				delete_node(Header, delNode);
			}

			break;
		case 3:	
			printf("찾을 어플의 이름을 입력하세요 ");
			scanf_s("%s", Input, 100);
			if (is_in_list(Header, Input) == true)
			{
				printf("리스트에 값이 있습니다");
			}
			  else
			{
				printf("리스트에 값이 없습니다");
			}
			break;
		case 4:
			printf("\n갯수는 %d개 입니다\n", count_list(Header));
			break;
		case 5:
			if (is_empty(Header) == true)
			{
				printf("리스트가 비었습니다");
			}
			else
			{
				printf("리스트에 값이 있습니다");
			}
			break;
		case 6:
			print_list(Header);
			break;
		case 7:
			printf("찾을 어플의 이름을 입력하세요 ");
			scanf_s("%s", Input, 100);
			delNode = search(Header, Input);
			break;

		default:
			break;
		}

	}



	return 0;
}