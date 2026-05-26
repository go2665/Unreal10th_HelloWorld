#include <iostream>
#include <stdlib.h>
#include "Weekend0523.h"

const int MazeHeight = 10;
const int MazeWidth = 20;
const int InvalidPosition = -1;

const char* ShapePlayer = "P ";
const char* ShapeWall = "# ";
const char* ShapePath = ". ";
const char* ShapeStart = "S ";
const char* ShapeEnd = "E ";

const float BattleRate = 0.1f;
const int InitHealth = 100;

// 미로 배열
int Maze[MazeHeight][MazeWidth] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
    {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void Weekend0523()
{
    // 5번
    Weekend0523_Dungeon();
    int Number = 0;
    std::cin >> Number;
    printf("입력받은 숫자는 %d입니다.\n", Number);
    printf("각 자리수의 합은 %d입니다.\n", GetSum(Number));

    // 2번
    std::string NumberString;
    std::cin >> NumberString;
    printf("입력받은 숫자는 %s입니다.\n", NumberString.c_str());
    int Result = GetSum(NumberString.c_str());
    if (Result >= 0)
    {
    	printf("각 자리수의 합은 %d입니다.\n", Result);
    }
    else
    {
    	printf("숫자가 아닙니다.\n");
    }
}

void Weekend0523_Dungeon()
{
    int PlayerX = InvalidPosition;
    int PlayerY = InvalidPosition;
    int PlayerHealth = InitHealth;

    FindStart(PlayerX, PlayerY);    // 시작 위치 찾기

    if (PlayerX != InvalidPosition && PlayerY != InvalidPosition)
    {
        // 시작 위치를 잘 찾은 정상적인 경우
        printf("\n\n===== 텍스트 미로 탈출 게임 =====\n\n");

        while (true)
        {
            printf("진행을 위해 아무키나 눌러주세요");
            int Temp = getchar();

            system("cls"); // 화면 깨끗이 지우기

            // 화면 출력
            PrintMaze(PlayerX, PlayerY);
            
            // 출구에 도달했는지 확인
            if (IsGoal(PlayerX, PlayerY))
            {
                printf("축하합니다! 미로를 탈출했습니다!\n\n");
                break;
            }

            // 입력 처리
            MoveDirection Direction = GetMoveInput(PlayerX, PlayerY);
            switch (Direction)
            {
            case DirUp:
                PlayerY--;
                break;
            case DirDown:
                PlayerY++;
                break;
            case DirLeft:
                PlayerX--;
                break;
            case DirRight:
                PlayerX++;
                break;
            case DirNone:
            default:
                printf("ERROR!!! 비정상적인 방향입니다!!!!\n");
                break;
            }

            // 랜덤 인카운터 처리
            if (RandomIncounter())
            {
                // 전투 시작
                if (Battle(PlayerHealth))
                {
                    printf("승리! 탐색을 계속합니다.\n");
                }
                else
                {
                    printf("당신은 패배했습니다.\nGame Over...\n");
                    break;
                }
            }
        }
    }
    else
    {
        // 시작 위치를 찾지 못한 비정상적인 경우
        printf("ERROR!!!!! 맵에 시작위치를 찾을 수 없습니다.!!!\n");
    }
}

void FindStart(int& OutX, int& OutY)
{
    // 이중 for를 통해서 미로 전체를 순회하기
    for (int y = 0; y < MazeHeight; y++)
    {
        for (int x = 0; x < MazeWidth; x++)
        {
            if (Maze[y][x] == MazeStart)    // 플레이어 시작점을 찾았으면
            {
                OutX = x;   
                OutY = y;
                return;     // 저장하고 함수 종료
            }
        }
    }
    OutX = InvalidPosition; // 여기는 잘못된 곳이라고 의도를 명확히 써놓는 의미
    OutY = InvalidPosition;
}

void PrintMaze(int PlayerX, int PlayerY)
{
    // 이중 for를 통해서 미로 전체를 순회하기
    for (int y = 0; y < MazeHeight; y++)
    {
        for (int x = 0; x < MazeWidth; x++)
        {
            // 현재 위치에 맞는 모양 찍어주기
            if (PlayerX == x && PlayerY == y)
            {
                printf(ShapePlayer);    //printf("P ");와 같음                
            }
            else if (Maze[y][x] == MazeWall)
            {
                printf(ShapeWall);
            }
            else if (Maze[y][x] == MazePath)
            {
                printf(ShapePath);
            }
            else if (Maze[y][x] == MazeStart)
            {
                printf(ShapeStart);
            }
            else if (Maze[y][x] == MazeEnd)
            {
                printf(ShapeEnd);
            }
        }
        printf("\n");   // 줄바꿈 추가
    }
}

bool IsGoal(int PlayerX, int PlayerY)
{
    return Maze[PlayerY][PlayerX] == MazeEnd;
}

int PrintAvailableMoves(int PlayerX, int PlayerY)
{
    int Flags = DirNone;

    // w(↑) s(↓) a(←) d(→)
    if (!IsWall(PlayerX, PlayerY - 1))
    {
        printf("w(↑) ");
        Flags |= DirUp;
    }
    if (!IsWall(PlayerX, PlayerY + 1))
    {
        printf("s(↓) ");
        Flags |= DirDown;
    }
    if (!IsWall(PlayerX - 1, PlayerY))
    {
        printf("a(←) ");
        Flags |= DirLeft;
    }
    if (!IsWall(PlayerX + 1, PlayerY))
    {
        printf("d(→) ");
        Flags |= DirRight;
    }
    printf("\n");

    return Flags;
}

bool IsWall(int X, int Y)
{    
    return (X < 0 || X >= MazeWidth || Y < 0 || Y >= MazeHeight || Maze[Y][X] == MazeWall);
}

MoveDirection GetMoveInput(int PlayerX, int PlayerY)
{
    printf("이동할 방향을 선택하세요 (w:위, s:아래, a:왼쪽, d:오른쪽):\n");
    int AvailableFlags = PrintAvailableMoves(PlayerX, PlayerY);

    MoveDirection Result = DirNone;
    char Input = 0;
    while (true)
    {
        printf("방향 입력 : ");
        std::cin >> Input;

        if ((Input == 'w' || Input == 'W') && (AvailableFlags & DirUp))
        {
            Result = DirUp;
            break;
        }
        if ((Input == 's' || Input == 'S') && (AvailableFlags & DirDown))
        {
            Result = DirDown;
            break;
        }
        if ((Input == 'a' || Input == 'A') && (AvailableFlags & DirLeft))
        {
            Result = DirLeft;
            break;
        }
        if ((Input == 'd' || Input == 'D') && (AvailableFlags & DirRight))
        {
            Result = DirRight;
            break;
        }

        printf("잘못된 입력입니다. 이동 가능한 방향 중에서 선택하세요.\n");
    }

    return Result;
}

float GetRandom()
{
    return rand() / (float)RAND_MAX;   // 0.0f ~ 1.0f
}

int GetRandomRange(int Min, int Max)
{
    return Min + rand() % (Max - Min + 1);  // Min ~ Max(양끝 포함)
}

bool RandomIncounter()
{
    return GetRandom() < BattleRate;    // BattleRate보다 랜덤값이 적으면 전투 발생
}

bool Battle(int& PlayerHealth)
{
    const float CriticalRate = 0.1f;
    const int PlayerMinAttackPower = 5;
    const int PlayerMaxAttackPower = 15;
    const int EnemyMinAttackPower = 5;
    const int EnemyMaxAttackPower = 10;

    int EnemyHealth = 20;

    printf("고블린이 나타났다!! 전투 시작!\n");
    int Turn = 1;
    while (PlayerHealth > 0 && EnemyHealth > 0)
    {
        // 전투 턴 진행
        printf("------------턴 %d------------\n", Turn);
        printf("| Player : %3d  Enemy : %3d |\n", PlayerHealth, EnemyHealth);
        printf("-----------------------------\n");
        int Damage = GetRandomRange(PlayerMinAttackPower, PlayerMaxAttackPower);
        printf("당신의 공격 : %d의 데미지를 주었다.\n", Damage);
        EnemyHealth -= Damage;
        if (EnemyHealth > 0)
        {
            Damage = GetRandomRange(EnemyMinAttackPower, EnemyMaxAttackPower);
            printf("적의 공격 : %d의 데미지를 받았다.\n", Damage);
            PlayerHealth -= Damage;
        }
    }

    return PlayerHealth > 0;    // 플레이어의 체력이 남은채 while이 끝났으면 플레이어가 이긴것
}

int GetSum(int Number)
{
    int Sum = 0;
    while (Number > 0)
    {
        Sum += Number % 10;     // 1/10로 나눈 나머지는 따로 저장하기
        Number /= 10;           // 계속 1/10로 나누기
    }
    return Sum;
}

int GetSum(const char* NumberString)
{
    int Size = 0;    
    while (NumberString[Size] != '\0')
    {
        Size++;
    }
    //const char* p = NumberString;
    //while (*p != '\0')
    //{
    //    p++;
    //    Size++;
    //}

    int Sum = 0;
    for (int i = 0; i < Size; i++)
    {
        if (NumberString[i] >= '0' && NumberString[i] <= '9')
        {
            Sum += NumberString[i] - '0';
        }
        else
        {
            Sum = -1;
            break;
        }
        
    }
    
    return Sum;
}

