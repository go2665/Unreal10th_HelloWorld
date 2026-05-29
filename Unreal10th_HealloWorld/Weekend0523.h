#pragma once
#include "MazeCommon.h"
#include "Player.h"

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
// const int MazeHeight = 10;
// const int MazeWidth = 20;

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

// 미로 정보를 저장할 구조체
struct MazeData
{
	unsigned int Width = 0;
	unsigned int Height = 0;
	int* Data = nullptr;

	MazeData() = default;

	MazeData(int* InData, int InWidth, int InHeight)
		:Data(InData), Width(InWidth), Height(InHeight)
	{
	}
};

const char* const MapFilePath = ".\\Data\\MapData.txt";

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
/// <param name="InPlayer">플레이어 참조</param>
void PrintMaze(Player& InPlayer);

/// <summary>
/// 플레이어의 현재 상태 출력하는 함수
/// </summary>
/// <param name="InPlayer">플레이어 참조</param>
void PrintPlayerState(Player& InPlayer);

/// <summary>
/// 플레이어가 도착점에 도착했는지 확인하는 함수
/// </summary>
/// <param name="InPlayer">플레이어 참조</param>
/// <returns>true면 도착점에 있다. false면 도착점에 없다.</returns>
bool IsGoal(Player& InPlayer);
//inline bool IsGoal(int PlayerX, int PlayerY) { return Maze[PlayerY][PlayerX] == MazeEnd; }

/// <summary>
/// 이동 할 수 있는 방향을 출력하고 그 결과를 비트플래그로 반환하는 함수
/// </summary>
/// <param name="InPlayer">플레이어 참조</param>
/// <returns>이동 가능한 방향이 모두 저장된 비트플래그(MoveDirection)</returns>
int PrintAvailableMoves(Player& InPlayer);

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
/// <param name="InPlayer">플레이어 참조</param>
/// <returns>입력받은 방향</returns>
MoveDirection GetMoveInput(Player& InPlayer);

/// <summary>
/// 랜덤 인카운터(전투) 발생 여부 체크하는 함수
/// </summary>
/// <returns>true면 전투 발생, false면 아무일 없음</returns>
RandomIncounterType RandomIncounter();

/// <summary>
/// 전투 랜덤 인카운터 이벤트 처리 함수
/// </summary>
/// <param name="InPlayer">플레이어 참조</param>
/// <returns>true면 플레이어의 승리, false면 패배</returns>
bool Battle(Player& InPlayer);

/// <summary>
/// 플레이어 체력회복 랜덤 인카운터 이벤트 처리 함수
/// </summary>
/// <param name="InPlayer">플레이어 참조</param>
void Heal(Player& InPlayer);

/// <summary>
/// 플레이어 보물 발견 랜덤 인카운터 이벤트 처리함수
/// </summary>
/// <param name="InPlayer">플레이어 참조</param>
void Treasure(Player& Player);

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

/// <summary>
/// 지정된 파일을 읽어서 문자열로 리턴하는 함수
/// </summary>
/// <param name="Path">파일 전체 경로(Full Path)</param>
/// <returns>파일에 기록된 문자열</returns>
std::string ReadFile(const std::string& Path);

/// <summary>
/// 문자열을 파싱해서 MazeData를 만드는 함수
/// </summary>
/// <param name="StringData">원본 데이터 문자열</param>
/// <returns>파싱한 데이터를 기반으로 새로 만들어진 MazeData</returns>
MazeData ParseMaze(const std::string& StringData);

/// <summary>
/// MazeData를 정리하는 함수(할당 해제). ParseMaze가 실행됬다면 반드시 Cleanup을 실행해야한다.
/// </summary>
/// <param name="InMazeData">정리할 MazeData</param>
void CleanupMazeData(MazeData* InMazeData);

/// <summary>
/// MazeData가 사용가능한 데이터인지 확인하는 함수
/// </summary>
/// <param name="InMazeData">확인할 데이터</param>
/// <returns>true면 사용가능, false면 사용 불가능</returns>
bool IsValidMazeData(MazeData* InMazeData);