#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>
#include <map>
#include "GamePlayEnum.h"
#include "Fade_InAndOut.h"
#include "StageName.h"

// Ό³Έν :
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
	void LevelChangeStart() override;
	void LevelChangeEnd() override;

private:
	static Stage CurrentStage_;
	void IntotheStage();
	bool KeyPush();
	void CursorPosCheck();
	void ShowStageTitle();
	
	std::map<int, std::map<int, Coordinate*>> MainMap_;

	float4 MapScale_;
	float4 BackGroundScale_;
	float GameWindowStartPosX_;
	float GameWindowStartPosY_;

	float4 MainCursorPos_;

	void CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage);
	StageName* StageName_;
	GameEngineActor* MainCursor_;
	Fade_InAndOut* Fade_;
	GameEngineSoundPlayer BackGroundMusicControl_;
};

