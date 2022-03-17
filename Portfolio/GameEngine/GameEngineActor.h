#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>

// 설명 : 위치를 가지고있는 오브젝트 부모 클래스
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject
{
public:
	friend GameEngineLevel;

	GameEngineActor();
	virtual ~GameEngineActor();


	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	inline float4 GetPosition()
	{
		return Position_;
	}
	inline float4 GetScale()
	{
		return Scale_;
	}

	inline void SetPosition(float4 _Value)
	{
		Position_ = _Value;
	}
	inline void SetScale(float4 _Value)
	{
		Scale_ = _Value;
	}


protected:
	// 시작할 때 뭔가를 하고 싶은데 생성자에서는 절대로 못 할 부분들을 처리한다.
	virtual void Start() = 0;
	// 지속적으로 게임이 실행될 떄 호출
	virtual void Update() {}
	virtual void Render() {}

	// 디버그 렌더
	void DebugRectRender();

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	// 이 객체를 생성 시켜준 레벨
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

};

