#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GamePlayGobal.h"
#include "StageData.h"

// 설명 : Stage 정보를 받아 화면에 출력해주는 Level
class GamePlayObject;
class Coordinate;
class PlayLevel : public GameEngineLevel
{
public:
	PlayLevel();
	~PlayLevel();

	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;
	void LevelChangeEnd() override;

private:
	void CreatMap (std::map<int, std::map<int, ObjectName>>& _Stage);
	void ScanMap();
	bool KeyCheck();
	void Move(Direction _Dir);

	void EndStage();
	void ReleaseActor();

	Stage CurrentStage_;
	float4 MapScale_;
	float GameWindowPosX_;
	float GameWindowPosY_;

	std::map<int, std::map<int, std::vector<Coordinate*>>> CurrentMap_;
	std::vector<std::pair<const GamePlayObject*, const GamePlayObject*>> ActiveFunction_;
};

