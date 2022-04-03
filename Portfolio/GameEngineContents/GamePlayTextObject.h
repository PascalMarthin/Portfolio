#pragma once
#include "GamePlayText.h"

// Ό³Έν :
class GamePlayTextObject : public GamePlayText
{
public:
	GamePlayTextObject();
	virtual ~GamePlayTextObject();

	GamePlayTextObject(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject(GamePlayTextObject&& _Other) noexcept = delete;
	GamePlayTextObject& operator=(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject& operator=(GamePlayTextObject&& _Other) noexcept = delete;

	virtual void SettingAbility() {}
	virtual void Destroy() {}

	
protected:
	virtual void StatEffect() {}

private:
};
