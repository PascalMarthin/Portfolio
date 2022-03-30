#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include <list>
#include <map>

// ���� : �� Level�� ���� �ϸ� Actor�� ����
class GameEngine;
class GameEngineActor;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	GameEngineLevel();

	// �ڽ� Ŭ���� �Ҹ��� ȣ��
	virtual ~GameEngineLevel();


	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

	template<typename ActorType>
	ActorType* CreateActor(int _Order = 0, const std::string& _Name = "")
	{
		ActorType* NewActor = new ActorType();
		// ��ĳ����
		// �Ϲ������� Start() �Լ��� �� �� ȣ���� �ȵǰ� protected�� ���Ƴ��Ҵ�
		// �׷��� ���������� actor�� �θ� Ŭ������ GameEngineActor��
		// GameEngineLevel�� friend ���� �س��� ������ ������ ������ ��
		GameEngineActor* StartActor = NewActor;

		// GameEngineNameObject�� SetName
		NewActor->SetName(_Name);
		// GameEngineActor�� SetLevel
		NewActor->SetLevel(this);

		// ��ĳ���ÿ� ���� Start() �Լ��� ������ �Ǹ� 
		// �� �� �����Լ��� ���� �ڽ��� Start() �Լ��� ����
		StartActor->Start();

		// Ű���� value�� �־��ش�. �� �� list�� ��������μ�
		// �ߺ��� ������� �ʴ� map�� Ư¡�� �̿��� ȣ���ϰ� ���� Ű�� �ش�Ǵ� value,
		// �� list�� ���������μ� �� �� ȿ�������� �����͸� �̿��� �� �ְ� �Ѵ�.
		// �Ʒ� �������ε� �����ϴ�.
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
	// �����Լ�
	// ��������鼭 ���ҽ��� ���͸� ���鶧 ���
	virtual void Loading() = 0;
	// �� ������ ���� ������ �� �ؾ� ������ �����Ѵ�
	virtual void Update() = 0;

	// Current �������� Next ������ ���� �� �� Next ������ �����ϴ� �Լ� 
	virtual void LevelChangeStart() {}
	// Current �������� Next ������ ���� �� �� Current ������ �����ϴ� �Լ� 
	virtual void LevelChangeEnd() {}


private :
	std::map<int, std::list<GameEngineActor*>> AllActor_;

	float4 CameraPos_;

	void ActorUpdate();
	void ActorRender();
	void ActorRelease();
};

