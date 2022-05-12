#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>
#include <map>
#include <queue>
#include "GamePlayEnum.h"
#include "Fade_InAndOut.h"
#include "StageName.h"
#include "PlayAndMainLevelMenu.h"
#include "PlayAndMainGrid.h"

// ���� :
class Coordinate;
class MainLevel : public GameEngineLevel
{
public:

	MainLevel();
	~MainLevel();


	MainLevel(const MainLevel& _Other) = delete;
	MainLevel(MainLevel&& _Other) noexcept = delete;
	MainLevel& operator=(const MainLevel& _Other) = delete;
	MainLevel& operator=(MainLevel&& _Other) noexcept = delete;

	static inline Stage GetCurrentStage()
	{
		return CurrentStage_;
	}

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

private:
	static Stage CurrentStage_;
	void IntoLevel();
	bool KeyPush();
	void CursorPosCheck();
	
	std::map<int, std::map<int, Coordinate*>> MainMap_;

	float4 MapScale_;
	float4 BackGroundScale_;
	float GameWindowStartPosX_;
	float GameWindowStartPosY_;

	float4 MainCursorPos_;

	bool IntoStage_;
	bool IntoTitle_;
	bool IntoMain_;
	//
	PlayAndMainLevelMenu* Menu_;
	void ShowMenuMode();
	void ShowMainMode();
	bool IsPause_;
	void KeyPushInMenu();
	PlayAndMainGrid* Grid_;
	//

	void CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage);
	StageName* StageName_;
	GameEngineActor* MainCursor_;
	std::queue<Direction> MoveQueue_;
	float CurrentMovePos_;
	Fade_InAndOut* Fade_;
	GameEngineSoundPlayer BackGroundMusicControl_;
};

