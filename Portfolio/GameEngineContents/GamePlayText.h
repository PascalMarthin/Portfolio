#pragma once
#include "GamePlayObject.h"

// Ό³Έν :
class GamePlayText : public GamePlayObject
{
public:
	// constrcuter destructer
	GamePlayText();
	~GamePlayText();

	// delete Function
	GamePlayText(const GamePlayText& _Other) = delete;
	GamePlayText(GamePlayText&& _Other) noexcept = delete;
	GamePlayText& operator=(const GamePlayText& _Other) = delete;
	GamePlayText& operator=(GamePlayText&& _Other) noexcept = delete;

	virtual void SettingAbility() {}
	virtual void Destroy() {}

protected:
	virtual void StatEffect() {}

private:

};

