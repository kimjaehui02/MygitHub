#pragma warning(disable:4996)
#include <stdio.h>



// 1������

float RecursiveFunction(float n)
{
	// 1 + 1/2 + 1/3 + ... + 1/n

	// n�� 1�̸� 1
	// n�� 2�̸� 1/2 + 1
	// n�� 3�̸� 1/3 + 1/2 + 1

	// n���� 1���� ������ �Լ��� �Ű������� 1�� �ɶ����� n-1���� 1�� ��� �����ִ� ���̴�
	
	

	// n�� 1�̶�� ���� 1/n-1�� ���� �� �����Ƿ� �׳� 1�� �������ݴϴ�
	if (n == 1)
	{
		printf("1\n");
		return n;
	}

	// n�� 1�� �ƴ϶�� ���� 1/n-1�� �Ű������� ���� �Լ��� �ҷ��ݴϴ�

	printf("1/%d + ", (int)n);
	return  ( (1 / n) + RecursiveFunction(n-1));
}

int main()
{
	int input;
	input = 0;

	// ó���� ���� �޽��ϴ�
	printf("���� ���� n�� �Կ��Ͻÿ� :");
	scanf_s("%d", &input);

	// n�� ���������� �ƴϸ�ݺ��մϴ�(input�� �����ų� 0�̰ų� �������ƴ�)
	while (input < 0 || input == 0)
	{
		input = -1;
		printf("���� ���� n�� �Կ��Ͻÿ� :");
		scanf_s("%d", &input);
	}

	// ������� ����մϴ�
	printf("%f", RecursiveFunction(input));

	return 0;
}

