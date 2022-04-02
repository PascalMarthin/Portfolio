#pragma once
#include "GamePlayObject.h"
#include <GameEngine/GameEngineActor.h>

// ���� :
class GamePlayUnitObject : public GamePlayObject
{
public:
	GamePlayUnitObject();
	virtual ~GamePlayUnitObject();

	GamePlayUnitObject(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject(GamePlayUnitObject&& _Other) noexcept = delete;
	GamePlayUnitObject& operator=(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject& operator=(GamePlayUnitObject&& _Other) noexcept = delete;

	virtual void SettingAbility() {}
	virtual void Destroy() {}

protected:
	//GameEngineActor* Actor;

private:

};

