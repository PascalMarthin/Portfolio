#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>

// 설명 :
class GameEngine;
class GameEngineActor;
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
	ActorType* CreateActor(const std::string& _Name, int _Order)
	{
		ActorType* NewActor = new ActorType();
		// GameEngineNameObject의 SetName
		NewActor->SetName(_Name);
		// GameEngineActor의 SetLevel
		NewActor->SetLevel(this);

		// 키값에 value를 넣어준다. 이 때 list를 사용함으로서
		// 중복을 허용하지 않는 map의 특징을 이용해 호출하고 싶은 키에 해당되는 value,
		// 즉 list를 가져옴으로서 좀 더 효과적으로 데이터를 이용할 수 있게 한다.
		// 아래 내용으로도 가능하다.
		// std::list<GameEngineActor*>& Group = AllActor_[_Order];
		// Group.push_back(NewActor);
		AllActor_[_Order].push_back(NewActor);


		return nullptr;
	}

private :
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	void ActorUpdate();
	void ActorRender();

};

