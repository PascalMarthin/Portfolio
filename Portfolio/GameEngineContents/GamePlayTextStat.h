#pragma once
#include "GamePlayObject.h"

// Ό³Έν :
class GamePlayTextStat : public GamePlayObject
{
public:
	// constrcuter destructer
	GamePlayTextStat();
	virtual ~GamePlayTextStat();

	// delete Function
	GamePlayTextStat(const GamePlayTextStat& _Other) = delete;
	GamePlayTextStat(GamePlayTextStat&& _Other) noexcept = delete;
	GamePlayTextStat& operator=(const GamePlayTextStat& _Other) = delete;
	GamePlayTextStat& operator=(GamePlayTextStat&& _Other) noexcept = delete;

protected:
	virtual void Start() = 0;
	virtual void Update() {}
	virtual void Render() {}

	virtual bool StatEffect() = 0;

private:

};

