#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

// 설명 : 위치를 가지고있는 오브젝트 부모 클래스
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

	inline void NextLevelOn()
	{
		NextLevelOn_ = true;
	}

	void SetOrder(int _Order) override;

protected:
	// 시작할 때 뭔가를 하고 싶은데 생성자에서는 절대로 못 할 부분들을 처리한다.
	virtual void Start() = 0;
	// 지속적으로 게임이 실행될 떄 호출
	virtual void Update() {}
	// 지속적으로 게임이 실행될 떄 호출
	virtual void Render() {}

	virtual void LevelChangeStart(GameEngineLevel* _PrevLevel) {}
	virtual void LevelChangeEnd(GameEngineLevel* _NextLevel) {}


	// 디버그 렌더
	void DebugRectRender();

	void Release();

	void LevelRegist(std::string _RegistName = "");


private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	bool NextLevelOn_;

	inline void NextLevelOff()
	{
		NextLevelOn_ = false;
	}


	// 이 객체를 생성 시켜준 레벨
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}

public:
	// 벡터의 값
	// 가장 빠를겁니다.
	// 디폴트 인자는 선언에서만 지정 가능합니다.

	GameEngineRenderer* CreateRenderer(int _Order = static_cast<int>(EngineMax::RENDERORDERMAX), RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	// 가장 빠를겁니다.
	// 디폴트 인자는 선언에서만 지정 가능합니다.
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
	// 이터레이터
	std::list<GameEngineCollision*> CollisionList_;

};

