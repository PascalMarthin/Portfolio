#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>

// ���� : ��ġ�� �������ִ� ������Ʈ �θ� Ŭ����
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject
{
public:
	friend GameEngineLevel;

	GameEngineActor();
	~GameEngineActor();


	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

protected:
	// ������ �� ������ �ϰ� ������ �����ڿ����� ����� �� �� �κе��� ó���Ѵ�.
	virtual void Start() = 0;
	// ���������� ������ ����� �� ȣ��
	virtual void Update() {}
	virtual void Render() {}

private:
	GameEngineLevel* Level_;
	float4 Position;
	float4 Scale_;

	// �� ��ü�� ���� ������ ����
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

};

