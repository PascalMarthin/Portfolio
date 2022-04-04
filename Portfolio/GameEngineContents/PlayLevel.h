#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GamePlayGobal.h"
#include "StageData.h"
#include "GamePlayTextStat.h"
#include "GamePlayUnitObject.h"
#include "GamePlayUnitText.h"

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
	void ScanFucntion();
	//void SetFunction(GamePlayObject* _LeftObject, GamePlayObject* _RightObject);
	void ApplyObjectFuction(Coordinate* _Unit, Coordinate* _Verb, Coordinate* _Stat);
	void ChangeUnit(const GamePlayObject* _Left, GamePlayObject* _Right);
	void ApplyStat();
	void CheckBit(const GamePlayStatManager* _Left, const GamePlayStatManager* _Right = nullptr);
	bool KeyCheck();
	void Move(Direction _Dir);

	void EndStage();
	void ReleaseActor();

	Stage CurrentStage_;
	float4 MapScale_;
	// 게임
	float GameWindowStartPosX_;
	float GameWindowStartPosY_;

	std::map<int, std::map<int, std::vector<Coordinate*>>> CurrentMap_;
	std::vector<std::pair<GamePlayObject*, GamePlayObject*>> ActiveFunction_;
};

