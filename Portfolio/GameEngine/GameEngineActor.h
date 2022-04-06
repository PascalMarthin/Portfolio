#pragma once
#include "GameEngineLevel.h"
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

// ���� : ��ġ�� �������ִ� ������Ʈ �θ� Ŭ����
class GameEngineLevel;
class GameEngineRenderer;
class GameEngineCollision;
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
	inline float4 GetCameraEffectPosition()
	{
		return Position_ - GetLevel()->GetCameraPos();
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

	void Release();


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

	GameEngineRenderer* CreateRenderer(int _Order = static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	// ���� �����̴ϴ�.
	// ����Ʈ ���ڴ� ���𿡼��� ���� �����մϴ�.
	GameEngineRenderer* CreateRenderer(const std::string& _Image, int _Order = static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, int _Order = static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });


private:
	std::list<GameEngineRenderer*> RenderList_;
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;
	
	////////////////////////////////////////////////////////// Collision

public:
	GameEngineCollision* CreateCollision(const std::string& _GroupName, float4 _Scale, float4 _Pivot = { 0, 0 });

	// 

private:
	// ���ͷ�����
	std::list<GameEngineCollision*> CollisionList_;

};

