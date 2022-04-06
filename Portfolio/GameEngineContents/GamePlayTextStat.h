#pragma once
#include "GamePlayText.h"
#include "GamePlayEnum.h"

// Ό³Έν :
class GamePlayTextStat : public GamePlayText
{
public:
	GamePlayTextStat();
	virtual ~GamePlayTextStat();

	GamePlayTextStat(const GamePlayTextStat& _Other) = delete;
	GamePlayTextStat(GamePlayTextStat&& _Other) noexcept = delete;
	GamePlayTextStat& operator=(const GamePlayTextStat& _Other) = delete;
	GamePlayTextStat& operator=(GamePlayTextStat&& _Other) noexcept = delete;

	virtual void SettingAbility() {}
	virtual void Destroy() {}

	inline const StatName GetStat() const
	{
		return Stat_;
	}

	
protected:
	virtual void StatEffect() {}
	StatName Stat_;

private:

};
