#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include <list>
#include <vector>
#include <map>

class GameEngineActor;
struct ChangeOrderItem
{
	GameEngineActor* TargetObject; // 이녀석을
	int ChangeOrder; // 이렇게 바꿔라.
};


// 설명 : 각 Level을 관리 하며 Actor를 생성
class GameEngine;
class GameEngineActor;
class GameEngineCollision;
class GameEngineRenderer;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
	friend GameEngineActor;
	friend GameEngineCollision;
	friend GameEngineRenderer;
public:
	GameEngineLevel();

	// 자식 클래스 소멸자 호출
	virtual ~GameEngineLevel();


	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0, const std::string& _Name = "")
	{
		ActorType* NewActor = new ActorType();
		// 업캐스팅
		// 일반적으로 Start() 함수는 두 번 호출이 안되게 protected로 막아놓았다
		// 그러나 예외적으로 actor의 부모 클래스인 GameEngineActor는
		// GameEngineLevel와 friend 선언 해놨기 때문에 접근이 가능한 것
		GameEngineActor* StartActor = NewActor;
		// GameEngineNameObject의 SetName
		NewActor->GameEngineUpdateObject::SetOrder(_Order);
		NewActor->SetName(_Name);
		// GameEngineActor의 SetLevel
		NewActor->SetLevel(this);


		// 업캐스팅에 의해 Start() 함수가 실행이 되며 
		// 이 때 가상함수로 인해 자식쪽 Start() 함수가 실행
		StartActor->Start();

		// 키값에 value를 넣어준다. 이 때 list를 사용함으로서
		// 중복을 허용하지 않는 map의 특징을 이용해 호출하고 싶은 키에 해당되는 value,
		// 즉 list를 가져옴으로서 좀 더 효과적으로 데이터를 이용할 수 있게 한다.
		// 아래 내용으로도 가능하다.
		//std::list<GameEngineActor*>& Group = AllActor_[_Order];
		//Group.push_back(NewActor);
		AllActor_[_Order].push_back(NewActor);

		return NewActor;
	}
	inline float4 GetCameraPos()
	{
		return CameraPos_;
	}

	inline void MoveCameraPos(const float4& _Value)
	{
		CameraPos_ += _Value;
	}

	inline void SetCameraPos(const float4& _Value)
	{
		CameraPos_ = _Value;
	}

protected:
	// 시점함수
	// 만들어지면서 리소스나 액터를 만들때 써라
	virtual void Loading() = 0;
	// 이 레벨이 현재 레벨일 때 해야 할일을 실행한다
	virtual void Update() = 0;

	// Current 레벨에서 Next 레벨로 이전 할 떄 Next 레벨이 실행하는 함수 
	virtual void LevelChangeStart() {}
	// Current 레벨에서 Next 레벨로 이전 할 떄 Current 레벨이 실행하는 함수 
	virtual void LevelChangeEnd() {}


private :
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	std::vector<ChangeOrderItem> ChangeOrderList;

	float4 CameraPos_;

	void ActorUpdate();
	void ActorRender();
	void CollisionDebugRender();
	void ActorRelease();

private:
	std::map<int, std::list<GameEngineRenderer*>> AllRenderer_;

	void AddRenderer(GameEngineRenderer* _Renderer);

	void ChangeUpdateOrder(GameEngineActor* _Actor, int _Oreder);

	void ChangeRenderOrder(GameEngineRenderer* _Renderer, int _NewOrder);


private:
	// 삭제는 액터가 하지만 실제 사용은 Level
	// 여기서 함부로 GameEngineCollision*을 delete 하는 일이 있으면 안된다.,
	std::map<std::string, std::list<GameEngineCollision*>> AllCollision_;

	void AddCollision(const std::string& _GroupName, GameEngineCollision* _Collision);
};

