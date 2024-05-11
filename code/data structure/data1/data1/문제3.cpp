#pragma warning(disable:4996)
#include <stdio.h>

// 3������


/// <summary>
/// �뷡
/// </summary>
struct Song
{
	/// <summary>
	/// �����̸�
	/// </summary>
	char artist[25] = "                        ";

	/// <summary>
	/// ���
	/// </summary>
	char title[30] = "                             ";
};

/// <summary>
/// ������
/// </summary>
struct PlayList
{
	/// <summary>
	/// �÷��̸���Ʈ�� �ִ� �� ��
	/// </summary>
	int no_of_songs;

	/// <summary>
	/// Song ����ü Ÿ�� �迭
	/// </summary>
	Song songs[10];

};



int main()
{
	/// <summary>
	/// ���� ����� �÷��̸���Ʈ
	/// </summary>
	/// <returns></returns>
	PlayList playList;

	// �ʱ�ȭ�� �� �ݴϴ�
	playList.no_of_songs = 0;
	// �������� �Ѿ���� �����ϴ�
	bool Next = false;

	// true�ų� ������ 10�� �Ǹ� ������ �����մϴ�
	// false�鼭 10�� �ƴϸ� �ݺ��մϴ�
	while (Next == false && playList.no_of_songs != 10)
	{
		printf("��� �Է��Ͻðڽ��ϱ�? �Է��Ϸ��� y�� �Է��Ͻʽÿ�(���簹�� : %d, �ִ밹�� 10)", playList.no_of_songs);
		char input = 'n';
		int ints  = scanf(" %c", &input);

		// ����� ������ �ƴϸ� ���������ϴ�
		if (input != 'y')
		{
			break;
		}
		input = 'n';

		// ������ �̸��� �޽��ϴ�
		printf("\n���� �̸� : \n");
		scanf(" %s", &playList.songs[playList.no_of_songs].artist);
		printf("\n�Էµ� ���� �̸� : %s\n", playList.songs[playList.no_of_songs].artist);

		// ���� �̸��� �޽��ϴ�
		printf("\n�� �̸� : \n");
		scanf(" %s", &playList.songs[playList.no_of_songs].title);
		printf("\n�Էµ� �� �̸� : %s\n", playList.songs[playList.no_of_songs].title);

		// �����Ͽ� 1���� �߰��Ǿ����ϴ�
		playList.no_of_songs++;
	}

	printf("No     Artist                    Title                    ");
	printf("\n");
	printf("==     ======                    =====                    ");

	// ������� ����� �ϳ��ϳ� �о�ɴϴ�
	for (int i = 0; i < playList.no_of_songs; i++)
	{
		printf("\n");
		printf("%d      %s           %s", i, playList.songs[i].artist, playList.songs[i].title);
	}

	printf("\nA total number of songs in the list: %d\n", playList.no_of_songs);

	return 0;
}

