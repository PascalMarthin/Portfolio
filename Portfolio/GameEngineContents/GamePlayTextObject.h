#pragma once
#include "GamePlayObject.h"

// ���� :
class GamePlayTextObject : public GamePlayObject
{
public:
	GamePlayTextObject();
	virtual ~GamePlayTextObject();

	GamePlayTextObject(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject(GamePlayTextObject&& _Other) noexcept = delete;
	GamePlayTextObject& operator=(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject& operator=(GamePlayTextObject&& _Other) noexcept = delete;

	virtual void SettingImg() {}
	virtual void Destroy() {}

	
protected:


private:
};
