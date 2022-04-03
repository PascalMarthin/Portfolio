#pragma once
#include "GamePlayUnitObject.h"
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

	bool CheckStat(GamePlayUnitObject* _Unit);

	inline void Kill()
	{
		Death = true;
	}
	inline bool IsDeath()
	{
		return Death;
	}


protected:
	bool Defeat_;
	bool Hot_;
	bool Melt_;
	bool Push_;
	bool Sink_;
	bool Stop_;
	bool Win_;
	bool You_;

private:
	void SetDefeat(GamePlayUnitObject* _Unit);
	void SetHot(GamePlayUnitObject* _Unit);
	void SetMelt(GamePlayUnitObject* _Unit);
	void SetPush(GamePlayUnitObject* _Unit);
	void SetSink(GamePlayUnitObject* _Unit);
	void SetStop(GamePlayUnitObject* _Unit);
	void SetWin(GamePlayUnitObject* _Unit);
	void SetYou(GamePlayUnitObject* _Unit);

	bool Death;
};

