#pragma once
#include <GameEngine/GameEngineActor.h>
#include "GamePalyEnum.h"

// Ό³Έν :
class GamePlayObject : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayObject();
	virtual ~GamePlayObject();

	// delete Function
	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

protected:
	virtual void Start() = 0;
	virtual void Update() {}
	virtual void Render() {}

	ObjectName GetEnumClass() const
	{
		return EnumClass_;
	}
	void SetEnumClass(ObjectName _Value)
	{
		EnumClass_ = _Value;
		return;
	}

private:
	ObjectName EnumClass_;

};

