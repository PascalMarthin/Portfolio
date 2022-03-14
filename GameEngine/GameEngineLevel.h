#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

// 설명 :
class GameEngine;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	GameEngineLevel();

	virtual ~GameEngineLevel();
	// 자식 클래스 소멸자 호출

	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	virtual void Loading() = 0;

	virtual void Update() = 0;
	// 레벨 수준의 업데이트 

private:
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr; // 미완
	}

};

