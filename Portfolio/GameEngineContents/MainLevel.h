#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <map>
#include "GamePlayEnum.h"

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

private:
	static Stage CurrentStage_;
	
	std::map<int, std::map<int, Coordinate*>> MainMap_;

	float4 MapScale_;
	float4 BackGroundScale_;
	float GameWindowStartPosX_;
	float GameWindowStartPosY_;

	GameEngineActor* MainCursor_;
	float4 MainCursorPos_;


	void CreatMap(std::map<int, std::map<int, ObjectName>>& _Stage);
};

