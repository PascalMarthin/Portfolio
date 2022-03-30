#pragma once
#include "GamePlayObject.h"

// Ό³Έν :
class GamePlayUnitObject : public GamePlayObject
{
public:
	GamePlayUnitObject();
	virtual ~GamePlayUnitObject();

	GamePlayUnitObject(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject(GamePlayUnitObject&& _Other) noexcept = delete;
	GamePlayUnitObject& operator=(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject& operator=(GamePlayUnitObject&& _Other) noexcept = delete;

	virtual void SettingImg() {}
	virtual void Destroy() {}

protected:

private:

};

