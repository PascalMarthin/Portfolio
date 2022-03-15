#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

// 설명 :
class GameEngine;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	GameEngineLevel();

	// 자식 클래스 소멸자 호출
	virtual ~GameEngineLevel();


	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	// 시점함수
	// 만들어지면서 리소스나 액터를 만들때 써라
	virtual void Loading() = 0;
	// 이 레벨이 현재 레벨일 때 해야 할일을 실행한다
	virtual void Update() = 0;

	// Current 레벨에서 Next 레벨로 이전 할 떄 Next 레벨이 실행하는 함수 
	virtual void SceneChangeStart() {}
	// Current 레벨에서 Next 레벨로 이전 할 떄 Current 레벨이 실행하는 함수 
	virtual void SceneChangeEnd() {}

	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr; // 미완
	}

private :

};

