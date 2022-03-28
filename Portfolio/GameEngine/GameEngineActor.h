#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

// ���� : ��ġ�� �������ִ� ������Ʈ �θ� Ŭ����
class GameEngineRenderer;
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject, public GameEngineUpdateObject
{
public:
	friend GameEngineLevel;

	GameEngineActor();
	virtual ~GameEngineActor();


	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	inline GameEngineLevel* GetLevel()
	{
		return Level_;
	}

	inline float4 GetPosition()
	{
		return Position_;
	}
	inline float4 GetScale()
	{
		return Scale_;
	}
	inline void SetMove(float4 _Value)
	{
		Position_ += _Value;
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
	// ������ �� ������ �ϰ� ������ �����ڿ����� ����� �� �� �κе��� ó���Ѵ�.
	virtual void Start() = 0;
	// ���������� ������ ����� �� ȣ��
	virtual void Update() {}
	// ���������� ������ ����� �� ȣ��
	virtual void Render() {}

	// ����� ����
	void DebugRectRender();

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	// �� ��ü�� ���� ������ ����
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

public:
	// ������ ��
	// ���� �����̴ϴ�.
	// ����Ʈ ���ڴ� ���𿡼��� ���� �����մϴ�.

	GameEngineRenderer* CreateRenderer(RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRenderer(const std::string& _Image, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });


	void Renderering();

private:
	std::list<GameEngineRenderer*> RenderList_;
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;
	

protected:

};

