#pragma warning(disable:4996)
#include <stdio.h>

// 3번문제


/// <summary>
/// 노래
/// </summary>
struct Song
{
	/// <summary>
	/// 가수이름
	/// </summary>
	char artist[25] = "                        ";

	/// <summary>
	/// 곡명
	/// </summary>
	char title[30] = "                             ";
};

/// <summary>
/// 재생목록
/// </summary>
struct PlayList
{
	/// <summary>
	/// 플레이리스트에 있는 곡 수
	/// </summary>
	int no_of_songs;

	/// <summary>
	/// Song 구조체 타입 배열
	/// </summary>
	Song songs[10];

};



int main()
{
	/// <summary>
	/// 내가 사용할 플레이리스트
	/// </summary>
	/// <returns></returns>
	PlayList playList;

	// 초기화를 해 줍니다
	playList.no_of_songs = 0;
	// 다음으로 넘어갈지를 묻습니다
	bool Next = false;

	// true거나 갯수가 10이 되면 루프를 중지합니다
	// false면서 10이 아니면 반복합니다
	while (Next == false && playList.no_of_songs != 10)
	{
		printf("계속 입력하시겠습니까? 입력하려면 y를 입력하십시오(현재갯수 : %d, 최대갯수 10)", playList.no_of_songs);
		char input = 'n';
		int ints  = scanf(" %c", &input);

		// 대답이 예스가 아니면 빠져나갑니다
		if (input != 'y')
		{
			break;
		}
		input = 'n';

		// 가수의 이름을 받습니다
		printf("\n가수 이름 : \n");
		scanf(" %s", &playList.songs[playList.no_of_songs].artist);
		printf("\n입력된 가수 이름 : %s\n", playList.songs[playList.no_of_songs].artist);

		// 곡의 이름을 받습니다
		printf("\n곡 이름 : \n");
		scanf(" %s", &playList.songs[playList.no_of_songs].title);
		printf("\n입력된 곡 이름 : %s\n", playList.songs[playList.no_of_songs].title);

		// 재생목록에 1개가 추가되엇습니다
		playList.no_of_songs++;
	}

	printf("No     Artist                    Title                    ");
	printf("\n");
	printf("==     ======                    =====                    ");

	// 저장소의 곡들을 하나하나 읽어옵니다
	for (int i = 0; i < playList.no_of_songs; i++)
	{
		printf("\n");
		printf("%d      %s           %s", i, playList.songs[i].artist, playList.songs[i].title);
	}

	printf("\nA total number of songs in the list: %d\n", playList.no_of_songs);

	return 0;
}

