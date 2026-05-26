#include <iostream>
#include "Weekend0523.h"

const int MazeHeight = 10;
const int MazeWidth = 20;
const int InvalidPosition = -1;

const char* ShapePlayer = "P ";
const char* ShapeWall = "# ";
const char* ShapePath = ". ";
const char* ShapeStart = "S ";
const char* ShapeEnd = "E ";

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

void Weekend0523_Dungeon()
{
    int PlayerX = InvalidPosition;
    int PlayerY = InvalidPosition;

    FindStart(PlayerX, PlayerY);    // 시작 위치 찾기

    if (PlayerX != InvalidPosition && PlayerY != InvalidPosition)
    {
        // 시작 위치를 잘 찾은 정상적인 경우
        printf("\n\n===== 텍스트 미로 탈출 게임 =====\n\n");

        while (true)
        {
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

