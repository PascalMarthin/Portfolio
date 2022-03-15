#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

// ���� :
class GameEngine;
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

protected:
	// �����Լ�
	// ��������鼭 ���ҽ��� ���͸� ���鶧 ���
	virtual void Loading() = 0;
	// �� ������ ���� ������ �� �ؾ� ������ �����Ѵ�
	virtual void Update() = 0;

	// Current �������� Next ������ ���� �� �� Next ������ �����ϴ� �Լ� 
	virtual void SceneChangeStart() {}
	// Current �������� Next ������ ���� �� �� Current ������ �����ϴ� �Լ� 
	virtual void SceneChangeEnd() {}

	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr; // �̿�
	}

private :

};

