#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GamePlayGobal.h"
#include "StageData.h"
#include "GamePlayTextStat.h"
#include "GamePlayUnitObject.h"
#include "GamePlayUnitText.h"

// ���� : Stage ������ �޾� ȭ�鿡 ������ִ� Level
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
	void ApplyObjectFuction(Coordinate* _Unit, Coordinate* _Verb, Coordinate* _Stat);
	void ChangeUnit(const GamePlayObject* _Left, GamePlayObject* _Right);
	void CheckMapAllStat();
	void CheckBitStat(std::vector<Coordinate*>& _Value);
	bool IsMapOut(int _X, int _Y);
	void Move(int _X, int _Y);
	bool CheckBitMove(std::vector<Coordinate*>& _Value, int _X, int _Y);
	Coordinate* FindUnitByStat(std::vector<Coordinate*>& _Value, unsigned __int64 _Stat);
	std::vector<Coordinate*>* FindUnitByStatVector(std::vector<Coordinate*>& _Value, unsigned __int64 _Stat);


	bool KeyCheck();

	void EndStage();
	void ReleaseActor();

	Stage CurrentStage_;
	float4 MapScale_;
	// ����
	float GameWindowStartPosX_;
	float GameWindowStartPosY_;

	std::map<int, std::map<int, std::vector<Coordinate*>>> CurrentMap_;
	std::vector<std::pair<GamePlayObject*, GamePlayObject*>> ActiveFunction_;
	std::vector<std::vector<Coordinate*>*> AllUnitByStatFucnDummy_;
};

