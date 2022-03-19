#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class GamePlayUnitObject : public GameEngineActor
{
public:
	GamePlayUnitObject();
	~GamePlayUnitObject();

	GamePlayUnitObject(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject(GamePlayUnitObject&& _Other) noexcept = delete;
	GamePlayUnitObject& operator=(const GamePlayUnitObject& _Other) = delete;
	GamePlayUnitObject& operator=(GamePlayUnitObject&& _Other) noexcept = delete;
protected:
	virtual void Start() = 0;
	virtual void Update() {}
	virtual void Render() {}


private:


};

