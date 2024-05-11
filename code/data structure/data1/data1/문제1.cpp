#pragma warning(disable:4996)
#include <stdio.h>



// 1번문제

float RecursiveFunction(float n)
{
	// 1 + 1/2 + 1/3 + ... + 1/n

	// n이 1이면 1
	// n이 2이면 1/2 + 1
	// n이 3이면 1/3 + 1/2 + 1

	// n분의 1부터 시작해 함수의 매개변수가 1이 될때까지 n-1분의 1을 계속 더해주는 식이다
	
	

	// n이 1이라면 다음 1/n-1이 나올 수 없으므로 그냥 1을 리턴해줍니다
	if (n == 1)
	{
		printf("1\n");
		return n;
	}

	// n이 1이 아니라면 다음 1/n-1을 매개변수로 넣은 함수를 불러줍니다

	printf("1/%d + ", (int)n);
	return  ( (1 / n) + RecursiveFunction(n-1));
}

int main()
{
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

	// 결과물을 출력합니다
	printf("%f", RecursiveFunction(input));

	return 0;
}

