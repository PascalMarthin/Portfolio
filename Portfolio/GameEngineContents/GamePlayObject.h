#pragma once
#include <GameEngine/GameEngineActor.h>
#include "GamePalyEnum.h"
#include <GameEngineBase/GameEngineMath.h>  

// Ό³Έν :
class GamePlayObject : public GameEngineActor
{
public:
	// constrcuter destructer
	GamePlayObject();
	virtual ~GamePlayObject();

	// delete Function
	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

	inline ObjectName GetObjectName() const
	{
		return ObjectName_;
	}

	inline ObjectType GetOType() const
	{
		return OType_;
	}

	inline float4 GetObjectCPos() const
	{
		return CPos_;
	}

	inline void SetObjectCPos(float4 _Pos)
	{
		CPos_ = _Pos;
	}

protected:
	virtual void Start() = 0;
	virtual void Update() {}
	virtual void Render() {}

	inline void SetObjectName(ObjectName _Idx)
	{
		ObjectName_ = _Idx;
	}

	inline void SetOType(ObjectType _Idx)
	{
		OType_ = _Idx;
	}


private:
	ObjectName ObjectName_;
	ObjectType OType_;

	float4 CPos_;


};

