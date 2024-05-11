#pragma warning(disable:4996)
#include <stdio.h>



// 2번문제



int main()
{
	int sum;
	sum = 0;

	int input;
	input = 0;

	// 처음에 값을 받습니다
	printf("양의 정수 n을 입역하시오 :");
	scanf_s("%d", &input);

	// n이 양의정수가 아니면반복합니다(input이 음수거나 0이거나 정수가아님)
	while (input < 0 || input == 0)
	{
		input = -1;
		printf("양의 정수 n을 입역하시오 :");
		scanf_s("%d", &input);
	}

	for (int i = 0; i < input; i++)
	{
		sum += i + 1;
	}

	printf("결과는 : %d", sum);

	return 0;
}


