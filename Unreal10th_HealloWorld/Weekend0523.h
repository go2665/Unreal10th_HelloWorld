#pragma once

enum MazeTile
{
	MazePath = 0,
	MazeWall = 1,
	MazeStart = 2,
	MazeEnd = 3
};

enum MoveDirection
{
	DirNone		= 0,
	DirUp		= 1 << 0,	// 1
	DirDown		= 1 << 1,	// 2
	DirLeft		= 1 << 2,	// 4
	DirRight	= 1 << 3	// 8
};

enum RandomIncounterType
{
	RI_None = 0,	// 아무일 없음
	RI_Battle,		// 전투
	RI_Heal,		// 회복
	RI_Treasure		// 보물 찾음(돈)
};

// constexpr; : 컴파일 타임에 결정이 되는 상수
// constexpr int MazeHeight = 10;
const int MazeHeight = 10;
const int MazeWidth = 20;
const int InvalidPosition = -1;
const int InitHealth = 100;

// 랜덤 인카운터 종류별 확률
const float BattleRate = 0.1f;
const float HealRate = 0.1f;
const float TresureRate = 0.1f;

// MazeTile 표시용
const char* const ShapePlayer = "P ";
const char* const ShapeWall = "# ";
const char* const ShapePath = ". ";
const char* const ShapeStart = "S ";
const char* const ShapeEnd = "E ";

// extern : 실제 선언은 아니고 다른곳에 이런 변수/함수등이 존재한다고 알려주는 것
//extern int Maze[MazeHeight][MazeWidth];	

void Weekend0523();

// 게임 시작 함수
void Weekend0523_Dungeon();

/// <summary>
/// 시작 위치 찾는 함수
/// </summary>
/// <param name="OutX">시작 X 위치(출력용)</param>
/// <param name="OutY">시작 Y 위치(출력용)</param>
void FindStart(int& OutX, int& OutY);

/// <summary>
/// 미로를 출력하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 X위치</param>
/// <param name="PlayerY">플레이어의 현재 Y위치</param>
void PrintMaze(int PlayerX, int PlayerY);

/// <summary>
/// 플레이어의 현재 상태 출력하는 함수
/// </summary>
/// <param name="Health">플레이어의 체력</param>
/// <param name="MaxHealth">플레이어의 최대 체력</param>
/// <param name="Money">플레이어의 돈</param>
void PrintPlayerState(int Health, int MaxHealth, int Money);

/// <summary>
/// 플레이어가 도착점에 도착했는지 확인하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 X위치</param> 
/// <param name="PlayerY">플레이어의 현재 Y위치</param>
/// <returns>true면 도착점에 있다. false면 도착점에 없다.</returns>
bool IsGoal(int PlayerX, int PlayerY);
//inline bool IsGoal(int PlayerX, int PlayerY) { return Maze[PlayerY][PlayerX] == MazeEnd; }

/// <summary>
/// 이동 할 수 있는 방향을 출력하고 그 결과를 비트플래그로 반환하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 X위치</param> 
/// <param name="PlayerY">플레이어의 현재 Y위치</param>
/// <returns>이동 가능한 방향이 모두 저장된 비트플래그(MoveDirection)</returns>
int PrintAvailableMoves(int PlayerX, int PlayerY);

/// <summary>
///	해당 위치가 벽인지 아닌지 확인하는 함수
/// </summary>
/// <param name="X">확인할 X 위치</param>
/// <param name="Y">확인할 Y 위치</param>
/// <returns>true변 벽, false면 벽이 아닌 이동가능한 지역</returns>
bool IsWall(int X, int Y);

/// <summary>
/// 이동 방향을 입력받고 해당 방향을 리턴하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 X위치</param> 
/// <param name="PlayerY">플레이어의 현재 Y위치</param>
/// <returns>입력받은 방향</returns>
MoveDirection GetMoveInput(int PlayerX, int PlayerY);

/// <summary>
/// 0.0f ~ 1.0f 사이를 리턴하는 함수
/// </summary>
/// <returns>0.0f ~ 1.0f 사이의 랜덤값</returns>
float GetRandom();

/// <summary>
/// Min ~ Max 사이의 랜덤한 값을 리턴하는 함수
/// </summary>
/// <param name="Min">랜덤의 최소값(포함)</param> 
/// <param name="Max">랜덤의 최대값(포함)</param>
/// <returns>Min ~ Max 사이의 랜덤한 값</returns>
int GetRandomRange(int Min, int Max);

/// <summary>
/// 랜덤 인카운터(전투) 발생 여부 체크하는 함수
/// </summary>
/// <returns>true면 전투 발생, false면 아무일 없음</returns>
RandomIncounterType RandomIncounter();

/// <summary>
/// 전투 랜덤 인카운터 이벤트 처리 함수
/// </summary>
/// <param name="PlayerHealth">현재 플레이어의 HP</param>
/// <returns>true면 플레이어의 승리, false면 패배</returns>
bool Battle(int& PlayerHealth);

/// <summary>
/// 플레이어 체력회복 랜덤 인카운터 이벤트 처리 함수
/// </summary>
/// <param name="PlayerHealth">플레이어의 현재 체력</param>
/// <param name="MaxHealth">플레이어의 최대 체력</param>
void Heal(int& PlayerHealth, int MaxHealth);

/// <summary>
/// 플레이어 보물 발견 랜덤 인카운터 이벤트 처리함수
/// </summary>
/// <param name="PlayerMoney">플레이어의 현재 보유 금액</param>
void Treasure(int& PlayerMoney);

// 자리수 분리해서 합치기(입력은 인티저로 제한)
int GetSum(int Number);

// 자리수 분리해서 합치기(입력은 자리 수 제한 없음)
int GetSum(const char* NumberString);

/// <summary>
/// 특정 위치의 Maze 타일 정보를 리턴하는 함수
/// </summary>
/// <param name="X">X위치</param>
/// <param name="Y">Y위치</param>
/// <returns>해당 위치의 타일 정보</returns>
MazeTile GetMazeData(int X, int Y);

// 특정 위치의 Maze 타일 정보를 세팅하는 함수
// void SetMazeData(int X, int Y);