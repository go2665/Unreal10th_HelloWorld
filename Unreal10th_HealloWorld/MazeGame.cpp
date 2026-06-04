#include <iostream>
#include <fstream>
#include "MazeGame.h"
#include "Player.h"
#include "Enemy.h"

void MazeGame::GameStart()
{
    Cleanup();  // 시작전 초기화

    std::string MapDataString = ReadFile(MapFilePath);  // 읽고
    if (!ParseMaze(MapDataString))      // 파싱하고 검증
    {
        printf("ERROR!!! 맵 정보가 올바르지 않습니다. \n");
        return;
    }    

    User = new Player();
    if (!User)
    {
        printf("ERROR!!! User 메모리 할당에 실패했습니다.\n");
        return;
    }

    FindStart();    // 시작 위치 찾기

    if (User && User->IsPlayerValidLocation())
    {
        // 시작 위치를 잘 찾은 정상적인 경우
        printf("\n\n===== 텍스트 미로 탈출 게임 =====\n\n");
        bool IsGameOver = false;

        while (!IsGameOver)
        {
            printf("진행을 위해 아무키나 눌러주세요");
            int Temp = getchar();

            system("cls"); // 화면 깨끗이 지우기

            // 화면 출력
            PrintMaze(User);
            User->PrintStatus();
            
            // 출구에 도달했는지 확인
            if (IsGoal(User))
            {
                printf("축하합니다! 미로를 탈출했습니다!\n\n");
                break;
            }

            // 입력 처리(리팩토링 여지 있음)
            MoveDirection Direction = GetMoveInput(User->GetLocation());
            Position NewLocation;
            switch (Direction)
            {
            case DirUp:
                NewLocation.Y = -1;
                break;
            case DirDown:
                NewLocation.Y = 1;
                break;
            case DirLeft:
                NewLocation.X = -1;
                break;
            case DirRight:
                NewLocation.X = 1;
                break;
            case DirNone:
            default:
                printf("ERROR!!! 비정상적인 방향입니다!!!!\n");
                break;
            }
            NewLocation = User->GetLocation() + NewLocation;
            User->SetLocation(NewLocation);

            // 랜덤 인카운터 처리
            switch (RandomIncounter())
            {
            case RI_Battle:
                // 전투 시작
                if (EventBattle(User))
                {
                    printf("승리! 탐색을 계속합니다.\n");
                    Temp = getchar();
                }
                else
                {
                    Temp = getchar();
                    printf("당신은 패배했습니다.\nGame Over...\n");
                    IsGameOver = true;
                }
                break;
            case RI_Heal:
                EventRestoreHealth(User);
                Temp = getchar();
                break;
            case RI_Treasure:
                EventTreasure(User);
                Temp = getchar();
                break;
            case RI_None:
            default:
                break;
            }
        }
    }
    else
    {
        // 시작 위치를 찾지 못한 비정상적인 경우
        printf("ERROR!!!!! 맵에 시작위치를 찾을 수 없습니다.!!!\n");
    }

    Cleanup();

    printf("게임 종료\n");
}

void MazeGame::FindStart()
{
    if (User)   // User가 만들어진 상황에서만 처리
    {
        // 이중 for를 통해서 미로 전체를 순회하기
        for (unsigned int y = 0; y < Height; y++)
        {
            for (unsigned int x = 0; x < Width; x++)
            {
                if (GetMazeData(x,y) == MazeStart)    // 플레이어 시작점을 찾았으면
                {
                    User->SetLocation(x, y);
                    return;     // 저장하고 함수 종료
                }
            }
        }

        // 여기는 잘못된 곳이라고 의도를 명확히 써놓는 의미
        User->SetInvalidLocation();
    }
}

void MazeGame::PrintMaze(const Player* InPlayer)
{
    // MazeTile 표시용
    const char* ShapePlayer = "P ";
    const char* ShapeWall = "# ";
    const char* ShapePath = ". ";
    const char* ShapeStart = "S ";
    const char* ShapeEnd = "E ";

    // 이중 for를 통해서 미로 전체를 순회하기
    for (unsigned int y = 0; y < Height; y++)
    {
        for (unsigned int x = 0; x < Width; x++)
        {
            // 현재 위치에 맞는 모양 찍어주기
            if (InPlayer->GetLocation().X == x 
                && InPlayer->GetLocation().Y == y)
            {
                printf(ShapePlayer);    //printf("P ");와 같음                
            }
            else if (GetMazeData(x, y) == MazeWall)
            {
                printf(ShapeWall);
            }
            else if (GetMazeData(x, y) == MazePath)
            {
                printf(ShapePath);
            }
            else if (GetMazeData(x, y) == MazeStart)
            {
                printf(ShapeStart);
            }
            else if (GetMazeData(x, y) == MazeEnd)
            {
                printf(ShapeEnd);
            }
        }
        printf("\n");   // 줄바꿈 추가
    }
}

int MazeGame::PrintAvailableMoves(const Position& InLocation)
{
    int Flags = DirNone;
    
    // w(↑) s(↓) a(←) d(→)
    if (!IsWall(InLocation.X, InLocation.Y - 1))
    {
        printf("w(↑) ");
        Flags |= DirUp;
    }
    if (!IsWall(InLocation.X, InLocation.Y + 1))
    {
        printf("s(↓) ");
        Flags |= DirDown;
    }
    if (!IsWall(InLocation.X - 1, InLocation.Y))
    {
        printf("a(←) ");
        Flags |= DirLeft;
    }
    if (!IsWall(InLocation.X + 1, InLocation.Y))
    {
        printf("d(→) ");
        Flags |= DirRight;
    }
    printf("\n");
    
    return Flags;
}

MoveDirection MazeGame::GetMoveInput(const Position& InLocation)
{
    printf("이동할 방향을 선택하세요 (w:위, s:아래, a:왼쪽, d:오른쪽):\n");
    int AvailableFlags = PrintAvailableMoves(InLocation);
    
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

RandomIncounterType MazeGame::RandomIncounter()
{
    // 랜덤 인카운터 종류별 확률
    const float BattleRate = 0.1f;
    const float HealRate = 0.1f;
    const float TresureRate = 0.1f;

    RandomIncounterType Result = RI_None;
    float Rate = GetRandom();
    if (Rate < BattleRate)
    {
        Result = RI_Battle;     // 0.0 ~ 0.1 사이다.
    }
    else if (Rate < (BattleRate + HealRate))
    {
        Result = RI_Heal;       // 0.1 ~ 0.2 사이다.
    }
    else if (Rate < (BattleRate + HealRate + TresureRate))
    {
        Result = RI_Treasure;   // 0.2 ~ 0.3 사이다.
    }
    return  Result;   
}

bool MazeGame::EventBattle(const Player* InUser)
{
    MazeEnemy Goblin;
    printf("[%s]이 나타났다!! 전투 시작!\n", Goblin.Name.c_str());
    int Turn = 1;

    while (InUser->IsAlive() && Goblin.Health > 0)
    {
        // 전투 턴 진행
        printf("------------턴 %d------------\n", Turn);
        InUser->PrintStatus();
        printf("| Enemy : %3d |\n", Goblin.Health);
        printf("-----------------------------\n");
        //InUser->Attack(Enemy);  // 나중에 Enemy만들고 수정
        Goblin.Health = 0;  // 테스트용 코드
        if (Goblin.Health > 0)
        {
            // 나중에 Enemy만들고 Enemy가 InUser를 Attack하게 만들기
        }
    }

    return InUser->IsAlive();    // 플레이어의 체력이 남은채 while이 끝났으면 플레이어가 이긴것}
}

void MazeGame::EventRestoreHealth(Player* InUser)
{
    if (InUser)
    {
        const int HealMin = 10;
        const int HealMax = 30;

        int HealAmount = GetRandomRange(HealMin, HealMax);
        printf("회복의 샘을 발견했습니다.\n[%d]만큼의 체력을 회복합니다.\n", HealAmount);
        InUser->AddHealth(HealAmount);   // 랜덤하게 회복    
    }
    else
    {
        printf("ERROR!!! InUser가 null입니다.\n");
    }
}

void MazeGame::EventTreasure(Player* InUser)
{
    if (InUser)
    {
        const int TreasureMin = 100;
        const int TreasureMax = 500;

        int TreasureAmount = GetRandomRange(TreasureMin, TreasureMax);
        printf("보물을 발견했습니다.\n[%d]만큼의 돈을 획득합니다.\n", TreasureAmount);
        InUser->AddMoney(TreasureAmount);
    }
    else
    {
        printf("ERROR!!! InUser가 null입니다.\n");
    }
}

std::string MazeGame::ReadFile(const std::string& Path)
{
    std::ifstream InputFile(Path);	// 입력용 파일스트림 만들기
    if (InputFile.is_open())
    {
        std::string FileTexts(
            (std::istreambuf_iterator<char>(InputFile)),
            std::istreambuf_iterator<char>()
        );
        //printf("파일 내용 : \n%s\n", FileTexts.c_str());
        InputFile.close();
        return FileTexts;
    }
    else
    {
        // 파일이 없거나 다른 이유로 열리지 않았다.
        printf("파일을 열 수 없습니다.\n");        
    }
    
    //return "";  // 전통적인 방식
    return {};
}

bool MazeGame::ParseMaze(const std::string& StringData)
{
    // 파싱전 초기화
    Width = 0;
    Height = 0;
    if (MazeDataArray)
    {
        delete MazeDataArray;
        MazeDataArray = nullptr;
    }

    // 데이터 처리 시작
    if (StringData.empty())
    {
        return false;  // 입력 데이터 없으면 그냥 종료
    }

    size_t FirstLinePosition = StringData.find('\n');      // 첫번째 엔터 찾기
    if (FirstLinePosition == std::string::npos)
    {
        printf("ERROR - 첫번째 줄을 찾을 수 없습니다!!!\n");
        return false;
    }
    std::string FirstLine = StringData.substr(0, FirstLinePosition);    // 첫번째 엔터 위치 이용해서 첫줄 만들기
    size_t CommaPosition = FirstLine.find(',');
    if (CommaPosition == std::string::npos)
    {
        printf("ERROR - 콤마(,)를 찾을 수 없습니다!!!\n");
        return false;
    }
    // 첫 줄 데이터로 가로 세로 크기 가져오기
    Width = std::stoi(FirstLine.substr(0, CommaPosition)); // 처음 ~ 콤마앞까지
    Height = std::stoi(FirstLine.substr(CommaPosition+1)); // 콤마다음 ~ 끝까지

    // 동적 할당으로 배열 만들기
    MazeDataArray = new int[Width * Height];

    // 맵 데이터 파싱 시작 지점 설정
    size_t CurrentPosition = FirstLinePosition + 1; // 첫줄 다음 위치
    unsigned int X = 0;
    unsigned int Y = 0;
    while (CurrentPosition < StringData.length() && Y < Height)
    {
        size_t NextComma = StringData.find(',', CurrentPosition);       // 다음 콤마 위치
        size_t NextNewLine = StringData.find('\n', CurrentPosition);    // 다음 뉴라인 위치
        
        size_t TokenEndPosition = std::string::npos;
        bool IsLineEnd = false;

        if (NextComma < NextNewLine)
        {
            TokenEndPosition = NextComma;   // 콤마까지가 하나의 숫자다
        }
        else
        {
            TokenEndPosition = NextNewLine; // 줄의 마지막 숫자다
            IsLineEnd = true;
        }

        if (TokenEndPosition == std::string::npos)  // 데이터 마지막이다.
        {
            TokenEndPosition = StringData.length();
            IsLineEnd = true;
        }

        // 값부분만 잘라내기
        std::string ValueString = StringData.substr(CurrentPosition, TokenEndPosition - CurrentPosition);
        if (!ValueString.empty())
        {
            int Index = X + Y * Width;                      // X와 Y로 인덱스 계산해서
            *(MazeDataArray + Index) = std::stoi(ValueString);  // 데이터 설정
            X++;    // X 증가
        }
        else
        {
            printf("ERROR - 값을 확인 할 수 없습니다.\n");
        }

        CurrentPosition = TokenEndPosition + 1; // 현재 위치를 방금 처리한 토큰 다음 위치로 변경

        if (IsLineEnd)  // 줄이 끝났으면
        {
            Y++;        // Y 증가시키고
            X = 0;      // X 0으로 초기화
        }
    }

    return IsValidMazeData();
}

void MazeGame::Cleanup()
{
    // 플레이어 정보 정리
    delete User;
    User = nullptr;

    // 맵 정보 정리
    if (MazeDataArray)
    {
        delete[] MazeDataArray;
        MazeDataArray = nullptr;
    }
    Width = 0;
    Height = 0;
}
