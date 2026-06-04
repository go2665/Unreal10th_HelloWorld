#pragma once
#include "MazeCommon.h"
#include "Player.h"

class MazeGame
{
public:
	void GameStart();

private:
	// 미로 맵 파일
	const char* MapFilePath = ".\\Data\\MapData.txt";
	
	// 미로 기본 정보
	unsigned int Width = 0;
	unsigned int Height = 0;
	int* MazeDataArray = nullptr;

	// 플레이어 정보
	Player* User = nullptr;

private:
	/// <summary>
	/// 플레이어가 도착점에 도착했는지 확인하는 함수
	/// </summary>
	/// <param name="InPlayer">플레이어 참조</param>
	/// <returns>true면 도착점에 있다. false면 도착점에 없다.</returns>
	inline bool IsGoal(const Player* InPlayer)
	{
		return GetMazeData(InPlayer->GetLocation().X,
			InPlayer->GetLocation().Y) == MazeEnd;
	}

	/// <summary>
	///	해당 위치가 벽인지 아닌지 확인하는 함수
	/// </summary>
	/// <param name="X">확인할 X 위치</param>
	/// <param name="Y">확인할 Y 위치</param>
	/// <returns>true변 벽, false면 벽이 아닌 이동가능한 지역</returns>
	inline bool IsWall(int X, int Y)
	{
	    return (
	        X < 0 || X >= static_cast<int>(Width) 
		    || Y < 0 || Y >= static_cast<int>(Height) 
			|| GetMazeData(X, Y) == MazeWall);
	}

	/// <summary>
	/// MazeData가 사용가능한 데이터인지 확인하는 함수
	/// </summary>
	/// <returns>true면 사용가능, false면 사용 불가능</returns>
	inline bool IsValidMazeData()
	{
		return MazeDataArray != nullptr;
	}

	/// <summary>
	/// 특정 위치의 Maze 타일 정보를 리턴하는 함수
	/// </summary>
	/// <param name="X">X위치</param>
	/// <param name="Y">Y위치</param>
	/// <returns>해당 위치의 타일 정보</returns>
	inline MazeTile GetMazeData(int X, int Y)
	{
		return (MazeTile)(MazeDataArray[X + Width * Y]);
	}

	// 내부 함수들 ---------------------------------------------

	/// <summary>
	/// 시작 위치 찾는 함수
	/// </summary>
	void FindStart();

	/// <summary>
	/// 미로를 출력하는 함수
	/// </summary>
	/// <param name="InPlayer">플레이어 주소</param>
	void PrintMaze(const Player* InPlayer);

	/// <summary>
	/// 이동 할 수 있는 방향을 출력하고 그 결과를 비트플래그로 반환하는 함수
	/// </summary>
	/// <param name="InPos">위치 참조</param>
	/// <returns>이동 가능한 방향이 모두 저장된 비트플래그(MoveDirection)</returns>
	int PrintAvailableMoves(const Position& InLocation);

	/// <summary>
	/// 이동 방향을 입력받고 해당 방향을 리턴하는 함수
	/// </summary>
	/// <param name="InPlayer">플레이어 위치 참조</param>
	/// <returns>입력받은 방향</returns>
	MoveDirection GetMoveInput(const Position& InLocation);

	/// <summary>
	/// 랜덤 인카운터(전투) 발생 여부 체크하는 함수
	/// </summary>
	/// <returns>true면 전투 발생, false면 아무일 없음</returns>
	RandomIncounterType RandomIncounter();

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
	/// <returns>파싱 성공 여부(true면 성공, false면 실패)</returns>
	bool ParseMaze(const std::string& StringData);

	/// <summary>
	/// MazeGame에서 할당한 것들을 모두 정리하는 함수
	/// </summary>
	void Cleanup();

	// 이벤트 함수-----------------------------------------------
	/// <summary>
	/// 전투 랜덤 인카운터 이벤트 처리 함수
	/// </summary>
	/// <param name="InPlayer">유저의 주소</param>
	/// <returns>true면 플레이어의 승리, false면 패배</returns>
	bool EventBattle(const Player* InUser);

	/// <summary>
	/// 플레이어 체력회복 랜덤 인카운터 이벤트 처리 함수
	/// </summary>
	/// <param name="InPlayer">유저의 주소</param>
	void EventRestoreHealth(Player* InUser);

	/// <summary>
	/// 플레이어 보물 발견 랜덤 인카운터 이벤트 처리함수
	/// </summary>
	/// <param name="InPlayer">유저의 주소</param>
	void EventTreasure(Player* InUser);
};

