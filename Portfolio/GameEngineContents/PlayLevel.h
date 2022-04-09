#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineMath.h>
#include "Coordinate.h"
#include "GamePlayGobal.h"
#include "StageData.h"
#include "GamePlayTextStat.h"
#include "GamePlayUnitObject.h"
#include "GamePlayUnitText.h"

// 설명 : Stage 정보를 받아 화면에 출력해주는 Level
class CooridnateHistoryData;
class GamePlayObject;
class AA;
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
	void ReSetLevel();

	void CreatMap (std::map<int, std::map<int, ObjectName>>& _Stage);
	void StageFucntionReset();
	void StageSave();
	void ScanFucntionAndBridgeUnit();
	bool CheckFunction(int _X, int _Y, Coordinate* _Verb);
	void ApplyObjectFuction(Coordinate* _Unit, Coordinate* _Verb, Coordinate* _Stat);
	void ChangeUnit(const GamePlayUnitObject* _Left, GamePlayUnitObject* _Right);
	bool FindUnitByStat(std::list<Coordinate*>& _Value, unsigned __int64 _Stat);
	void CheckMapAllStat();
	bool CheckMapAllStat(const std::pair<int, int>& _MoveDir);
	bool CheckBitMove(const int _x, const int _y, const std::pair<int, int>& _MoveDir);
	bool PushKey(Direction _Dir);
	void CheckBitStat(std::list<Coordinate*>& _Value);
	std::list<Coordinate*>::iterator& Move(std::list<Coordinate*>::iterator& _ListIter, std::pair<int, int> _MoveDir);
	std::list<Coordinate*>::iterator& MoveBack(std::list<Coordinate*>::iterator& _ListIter, const float4& _MovePos, Direction _Dir);
	bool IsMapOut(const std::pair<int, int>& _Pos);

	void BackTothePast();
	void StageSavePopBack();

	unsigned int CheckUnitBridge(const Coordinate* _Unit);
	Coordinate* FindUnitObject(std::list<Coordinate*>& _UnitList, const ObjectName _Unit);
	bool KeyCheck();

	void ClearStage();
	bool IsClear_;
	float ClearWait;
	void EndStage();
	void AllReleaseInStage();

	GameEngineActor* ClearScene_;
	Stage CurrentStage_;
	float4 MapScale_;
	// 게임
	float GameWindowStartPosX_;
	float GameWindowStartPosY_;

	std::map<int, std::map<int, std::list<Coordinate*>>> CurrentMap_;
	//std::vector<std::pair<GamePlayObject*, GamePlayObject*>> ActiveFunction_;
	std::list<Coordinate*> AllCoordinate_;
	std::vector<std::map< Coordinate* , const CooridnateHistoryData*>*> AllMoveHistory_;

private:

};
class CooridnateHistoryData
{
public:
	CooridnateHistoryData(Coordinate* _Coordinate)
		: Pos_(_Coordinate->GetPos())
		, Direction_(_Coordinate->GetDir())
		, IsUpdate_(_Coordinate->IsUpdate())
		, ObjectName_(ObjectName::Error)
	{
		if (_Coordinate->GetObjectType() == ObjectType::Text)
		{
			ObjectName_ = _Coordinate->GetTextObjectInst()->GetName();
		}
		if (_Coordinate->GetObjectType() == ObjectType::Unit)
		{
			ObjectName_ = _Coordinate->GetUnitObjectInst()->GetName();
		}
	}

	~CooridnateHistoryData()
	{

	}

	CooridnateHistoryData(const CooridnateHistoryData& _Other) = delete;
	CooridnateHistoryData(CooridnateHistoryData&& _Other) noexcept = delete;
	CooridnateHistoryData& operator=(const CooridnateHistoryData& _Other) = delete;
	CooridnateHistoryData& operator=(CooridnateHistoryData&& _Other) noexcept = delete;
	
	float4 Pos_;
	Direction Direction_;
	ObjectName ObjectName_;
	bool IsUpdate_;
};

