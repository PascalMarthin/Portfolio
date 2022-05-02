#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngineBase/GameEngineSound.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <queue>

#include "Coordinate.h"
#include "GamePlayGobal.h"
#include "StageData.h"
#include "GamePlayTextStat.h"
#include "GamePlayUnitObject.h"
#include "GamePlayUnitText.h"
#include "ClearScene.h"
#include "EffectManager.h"
#include "Fade_InAndOut.h"
#include "GameHelpMoveUI.h"
#include "GameHelpOverUI.h"
#include "PlayAndMainLevelMenu.h"
#include "AlphabetManager.h"
#include "BackGround.h"
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

	inline EffectManager* GetEffectManager()
	{
		return PlayLevelEffectManager_;
	}

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

private:
	void SetStage();
	void ReSetStage();
	void CreatMap (std::map<int, std::map<int, ObjectName>>& _Stage);
	
	void StageFucntionReset();
	void StageSave();
	void ScanFucntion();
	void ScanBridgeUnit();
	bool CheckFunction(int _X, int _Y, Coordinate* _Verb);
	void ApplyObjectFuction(Coordinate* _Unit, Coordinate* _Verb, Coordinate* _Stat);
	bool ChangeUnit(const GamePlayUnitObject* _Left, GamePlayUnitObject* _Right);
	Coordinate* FindUnitByStat(std::list<Coordinate*>& _Value, unsigned __int64 _Stat);
	void CheckMapAllStat();
	bool CheckMapAllStat(Direction _MoveDir);
	bool CheckBitMove(const int _x, const int _y, Direction _MoveDir);
	bool PushKey(Direction _Dir);
	void CheckBitStat(std::list<Coordinate*>& _Value);
	std::list<Coordinate*>::iterator& Move(std::list<Coordinate*>::iterator& _ListIter, Direction _MoveDir);
	std::list<Coordinate*>::iterator& MoveBack(std::list<Coordinate*>::iterator& _ListIter, const float4& _MovePos, Direction _Dir);
	bool IsMapOut(const std::pair<int, int>& _Pos);

	// 사운드
	void PlaySoundMove();
	void PlaySoundBack();
	void PlaySoundSink();
	void PlaySoundDefeat();
	void PlaySoundMelt();
	void PlaySoundChange();
	GameEngineSoundPlayer BackGroundMusicControl_;
	GameEngineSoundPlayer BackGroundNoiseControl_;
	//

	// 이펙트
	EffectManager* PlayLevelEffectManager_;
	//

	// Ui
	AlphabetManager* StageAlphabet_;
	GameHelpMoveUI* MoveUI_;
	GameHelpOverUI* OverUI_;
	PlayAndMainLevelMenu* Menu_;
	BackGround* GameBackGround_;
	bool GoMain_;
	bool GoTitle_;
	bool IsPause_;
	void KeyPushInMenu();
	void ShowPlayMode();
	void ShowMenuMode();
	float TimeForFadeIn_;
	//

	void SceneChange();
	//void BeforeMove();
	void AfterMove();
	void BackTothePast();
	void StageSavePopBack();
	bool CanMove();
	void GameOver();
	void ReGame();

	// StageTitle(Alphabet)
	bool StageTitle_;
	//

	unsigned int CheckUnitBridge(const Coordinate* _Unit);
	Coordinate* FindUnitObject(std::list<Coordinate*>& _UnitList, const ObjectName _Unit);
	bool KeyCheck();

	void ClearStage();
	bool IsClear_;
	bool IsReset_;
	bool IsOver_;
	
	float ClearWait;
	void EndStage();
	void AllReleaseInStage();

	Fade_InAndOut* Fade_;
	// Random
	GameEngineRandom* Random_;
	inline const GameEngineRandom* GetRandom() const
	{
		return Random_;
	}
	//
	GameEngineActor* BackGround_;
	ClearScene* ClearScene_;
	Stage CurrentStage_;
	float4 MapScale_;
	// 게임
	float GameWindowStartPosX_;
	float GameWindowStartPosY_;

	std::map<int, std::map<int, std::list<Coordinate*>>> CurrentMap_;
	std::list<Coordinate*> AllCoordinate_;
	std::vector<std::map< Coordinate* , const CooridnateHistoryData*>*> AllMoveHistory_;
	std::queue<Direction> QueueMove_;

private:

};

class CooridnateHistoryData
{
public:
	CooridnateHistoryData(Coordinate* _Coordinate)
		: Pos_(_Coordinate->GetPos())
		, Direction_(_Coordinate->GetDir())
		, IsUpdate_(_Coordinate->IsUnitUpdate())
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

