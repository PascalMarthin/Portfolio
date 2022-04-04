#pragma once
#include "GamePlayTextStat.h"
#include "GamePlayEnum.h"
#include <vector>

// Ό³Έν :
class GamePlayStatManager
{
public:
	// constrcuter destructer
	GamePlayStatManager();
	~GamePlayStatManager();

	// delete Function
	GamePlayStatManager(const GamePlayStatManager& _Other) = delete;
	GamePlayStatManager(GamePlayStatManager&& _Other) noexcept = delete;
	GamePlayStatManager& operator=(const GamePlayStatManager& _Other) = delete;
	GamePlayStatManager& operator=(GamePlayStatManager&& _Other) noexcept = delete;

	void ApplyStat(const GamePlayTextStat* _Stat);
	inline unsigned __int64& GetAllStat()
	{
		return AllStat_;
	}

	void Reset();

	


protected:
	unsigned __int64 AllStat_;

private:
	void SetDefeat();
	void SetHot();
	void SetMelt();
	void SetPush();
	void SetSink();
	void SetStop();
	void SetWin();
	void SetYou();


};

