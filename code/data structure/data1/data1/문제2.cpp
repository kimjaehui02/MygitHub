#pragma warning(disable:4996)
#include <stdio.h>



// 2������



int main()
{
	int sum;
	sum = 0;

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

	for (int i = 0; i < input; i++)
	{
		sum += i + 1;
	}

	printf("����� : %d", sum);

	return 0;
}


