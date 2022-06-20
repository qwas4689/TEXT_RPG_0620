
#include "define.h"
using namespace std;

void screenClaer()
{
	system("cls");
}

struct Player
{
	int		hp;
	int		damage;
	int		gold;
} player;

struct SmallMonster
{
	int		hp;
	int		damage;
	int		gold;
} smallMonster;

struct Monster
{
	int		hp;
	int		damage;
	int		gold;
} monster;

struct Bos
{
	int		hp;
	int		damage;
} bos;

// 플레이어 정보
void playerInfo()
{
	cout << "Hp : " << player.hp << "\n" << "Damage : " << player.damage << "\n" << "Gold : " << player.gold << endl;
	cout << endl;
}

// 맵
void map()
{
	cout << endl << endl;
	cout << "1. 집으로 가기" << "\n" << "2. 강화하기" << "\n" << "3. 던전입장" << "\n";
	cout << endl;
	cout << "하고싶은것은 : ";

}

// 선택지
int pickNum = 0;


// 맵 이동 선택하기
void mapEnhance()
{
	cout << "강화기 앞" << "\n";
	cout << endl << endl << endl;
	cout << "1. 강화하기" << endl;
	cout << "2. 나가기" << endl;
}

int enhanceNum;

int enhanceInputNum()
{
	srand(time(nullptr));


	enhanceNum = rand() % 100 + 1;

	return enhanceNum;
}

int main()
{
	int nothing;
	system("mode con cols=100 lines=20 | title 강화해서 사냥하기 RPG ");

rePlay:

	string name;

	cout << "당신의 이름을 입력하세요 : ";
	cin >> name;

	screenClaer();

	string weaponName;

	cout << "무기의 이름을 입력하세요 : ";
	cin >> weaponName;

	screenClaer();

	cout << name << " 당신은 " << "\n" << "무기 " << weaponName << "을(를) 가지고 보스를 잡아 집으로 돌아가야 합니다." << "\n" << "건투를 빕니다.";
	cout << endl << endl;
	cout << "1을 입력하시오 : ";
	cin >> nothing;


	player.hp = 100;
	player.damage = 10;
	player.gold = 0;

	smallMonster.hp = 50;
	smallMonster.damage = 5;
	smallMonster.gold = 10;

	monster.hp = 200;
	monster.damage = 20;
	monster.gold = 100;

	bos.hp = 1000;
	bos.damage = 45;

outToMap:
outEnhance:
	screenClaer();

	playerInfo();

	map();

	cin >> pickNum;

	screenClaer();

endGame:

	if (player.hp <= 0)
	{
		cout << "당신은 죽었습니다. 다시 하시겠습니까 ?" << endl;
		cout << "1. 예    2. 아니오" << endl;

		cin >> pickNum;
		screenClaer();
		switch (pickNum)
		{
		case 1:
			goto rePlay;
			break;

		case 2:
			cout << "게임 종료";
			return 0;
			break;
		}
	}

	switch (pickNum)
	{
	case 1:
		cout << "체력이 회복되었다" << endl << endl;

		cout << "계속하려면 1을 입력하세요 : ";

		player.hp = 100;

		cin >> pickNum;

		goto outToMap;

		break;

		// 강화하기
	case 2:

		mapEnhance();
		cout << endl;

		cout << "무엇을 하시겠습니까? : ";

		cin >> pickNum;

		switch (pickNum)
		{
		case 1:

		enhance:

			enhanceInputNum();

			if (player.gold >= ENHANCECOST)
			{
				if (enhanceNum > 10)
				{
					player.damage += UPDAMAGE;
					cout << "강화가 성공했습니다." << "\n" << "Damage : " << player.damage << endl << endl;

					cout << "1. 다시 강화하기" << endl;
					cout << "2. 나가기" << endl << endl;

					cout << "무얼 하시겠습니까 : ";

					cin >> pickNum;

					if (pickNum == 1)
					{
						screenClaer();
						player.gold -= ENHANCECOST;
						goto enhance;
					}
					else
					{
						screenClaer();
						goto outEnhance;
					}
				}
				else
				{
					screenClaer();
					cout << "무기가 터졌습니다.. 다시 하시겠습니까?" << "\n" << "1. 예    2. 아니오" << endl;

					cin >> pickNum;
					screenClaer();

					if (pickNum == 1)
					{
						goto rePlay;
					}

					else
					{
						screenClaer();
						goto outEnhance;
					}
				}
			}
			else
			{
				screenClaer();
				cout << "gold가 모자랍니다." << "\n" << "던전에 들어가 돈을 더 모아오세요";
				cout << endl << endl;
				cout << "계속하시려면 1을 입력하세요 : ";

				cin >> pickNum;
				screenClaer();
				goto outEnhance;

			}
			break;

		case 2:

			goto outEnhance;

			break;
		}

		break;

	case 3:

	outSmallMonster:
	outMonster:
		outBos:

		smallMonster.hp = 50;
		monster.hp = 200;
		bos.hp = 1000;

		cout << "던전" << "\n";
		cout << endl << endl;

		cout << "1. 고블린" << endl;
		cout << "2. 오우거" << endl;
		cout << "3. 마왕" << endl;
		cout << "4. 나가기" << endl;

		cout << endl;

		cout << "무엇을 하시겠습니까 : ";
		cin >> pickNum;

		screenClaer();

		switch (pickNum)
		{
		case 1:
			cout << "고블린" << endl;
			cout << "Hp : " << smallMonster.hp << endl;
			cout << "Damage : " << smallMonster.damage << endl;
			cout << endl << endl;

			playerInfo();

			cout << "1. 공격하기" << endl;
			cout << "2. 나가기" << endl;

			cout << endl;

			cin >> pickNum;
			cout << "무엇을 하시겠습니까 : ";

			switch (pickNum)
			{
			case 1:
				while (1)
				{
					screenClaer();

					cout << "고블린" << endl;
					cout << "Hp : " << smallMonster.hp - player.damage << endl;
					cout << "Damage : " << smallMonster.damage << endl;
					cout << endl << endl;

					player.hp -= smallMonster.damage;

					playerInfo();

					cout << "1. 공격하기" << endl;
					cout << "2. 나가기" << endl;

					cin >> pickNum;

					screenClaer();

					switch (pickNum)
					{
					case 1:
						smallMonster.hp -= player.damage;
						player.hp -= smallMonster.damage;
						break;

					case 2:
						player.hp -= smallMonster.damage;
						goto outSmallMonster;
						break;
					}

					if (smallMonster.hp <= 10)
					{
						player.gold += smallMonster.gold;

						playerInfo();
						cout << endl;
						cout << "몬스터를 잡았습니다. 돌아가세요." << endl;
						cout << "1. 나가기" << endl;
						cout << endl;
						cin >> pickNum;

						screenClaer();

						goto outSmallMonster;
					}

					if (player.hp <= 1)
					{
						screenClaer();
						goto endGame;
					}
				}
				break;

			case 2:
				screenClaer();
				goto outSmallMonster;
				break;
			}
			break;

		case 2:
			cout << "오우거" << endl;
			cout << "Hp : " << monster.hp << endl;
			cout << "Damage : " << monster.damage << endl;
			cout << endl << endl;

			playerInfo();

			cout << "1. 공격하기" << endl;
			cout << "2. 나가기" << endl;

			cout << endl;

			cin >> pickNum;
			cout << "무엇을 하시겠습니까 : ";

			switch (pickNum)
			{
			case 1:
				while (1)
				{
					screenClaer();

					cout << "오우거" << endl;
					cout << "Hp : " << monster.hp - player.damage << endl;
					cout << "Damage : " << monster.damage << endl;
					cout << endl << endl;

					player.hp -= monster.damage;

					playerInfo();

					cout << "1. 공격하기" << endl;
					cout << "2. 나가기" << endl;

					cin >> pickNum;

					screenClaer();

					switch (pickNum)
					{
					case 1:
						smallMonster.hp -= player.damage;
						player.hp -= monster.damage;
						break;

					case 2:
						player.hp -= monster.damage;
						goto outMonster;
						break;
					}

					if (smallMonster.hp <= 10)
					{
						player.gold += monster.gold;

						playerInfo();
						cout << endl;
						cout << "몬스터를 잡았습니다. 돌아가세요." << endl;
						cout << "1. 나가기" << endl;
						cout << endl;
						cin >> pickNum;

						screenClaer();

						goto outMonster;
					}

					if (player.hp <= 1)
					{
						screenClaer();
						goto endGame;
					}
				}
				break;

			case 2:
				screenClaer();
				goto outMonster;
				break;
			}
			break;

			break;

		case 3:

			if (bos.hp <= 10)
			{
				cout << "마왕은 이미 죽었습니다." << endl;
				goto outBos;
			}


			cout << "마왕" << endl;
			cout << "Hp : " << bos.hp << endl;
			cout << "Damage : " << bos.damage << endl;
			cout << endl << endl;

			playerInfo();

			cout << "1. 공격하기" << endl;
			cout << "2. 나가기" << endl;

			cout << endl;

			cin >> pickNum;
			cout << "무엇을 하시겠습니까 : ";

			switch (pickNum)
			{
			case 1:
				while (1)
				{
					screenClaer();

					cout << "마왕" << endl;
					cout << "Hp : " << bos.hp - player.damage << endl;
					cout << "Damage : " << bos.damage << endl;
					cout << endl << endl;

					player.hp -= bos.damage;

					playerInfo();

					cout << "1. 공격하기" << endl;
					cout << "2. 나가기" << endl;

					cin >> pickNum;

					screenClaer();

					switch (pickNum)
					{
					case 1:
						bos.hp -= player.damage;
						player.hp -= bos.damage;
						break;

					case 2:
						player.hp -= bos.damage;
						goto outBos;
						break;
					}

					if (smallMonster.hp <= 10)
					{
						playerInfo();
						cout << endl;
						cout << "몬스터를 잡았습니다. 돌아가세요." << endl;
						cout << "1. 나가기" << endl;
						cout << endl;
						cin >> pickNum;

						screenClaer();

						goto outBos;
					}

					if (player.hp <= 1)
					{
						screenClaer();
						goto endGame;
					}
				}
				break;

			case 2:
				screenClaer();
				goto outBos;
				break;
			}
			break;

			break;

		case 4:
			goto outToMap;
			break;
		}

		break;
	}
}