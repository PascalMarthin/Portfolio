#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

// ���� :
class GameEngine;
class GameEngineLevel : public GameEngineNameObject
{
	friend GameEngine;
public:
	GameEngineLevel();

	virtual ~GameEngineLevel();
	// �ڽ� Ŭ���� �Ҹ��� ȣ��

	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	virtual void Loading() = 0;

	virtual void Update() = 0;
	// ���� ������ ������Ʈ 

private:
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr; // �̿�
	}

};

