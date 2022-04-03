#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngine/GameEngineActor.h>
#include "GamePlayEnum.h"
#include "GamePlayObject.h"
#include <vector>


class Coordinate : public GameEngineActor
{
public:
	// constrcuter destructer
	Coordinate();
	~Coordinate();

	// delete Function
	Coordinate(const Coordinate& _Other) = delete;
	Coordinate(Coordinate&& _Other) noexcept = delete;
	Coordinate& operator=(const Coordinate& _Other) = delete;
	Coordinate& operator=(Coordinate&& _Other) noexcept = delete;

	//inline void SetPos(float4 _Pos)
	//{
	//	Pos_ = _Pos;
	//}

	inline GamePlayObject* GetObjectInst() const
	{
		return Object_;
	}

	void SetCFrame(int _Start, int _End)
	{
		CurrentFrame_ = _Start;
		StartFrame_ = _Start;
		EndFrame_ = _End;
	}
	void SetPos(const float4& _Pos, const float4& _CPos)
	{
		Pos_ = _Pos;
		LUPos_ = _CPos;
		SetPosition({ LUPos_.x + (DotSizeX / 2), LUPos_.y + (DotSizeY / 2) });
	}

	void SetBaseValue(GamePlayObject* _Object, Direction _Dir = Direction::None, const float4& _Size = { DotSizeX, DotSizeY });

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	float4 Pos_;
	float4 LUPos_;
	GamePlayObject* Object_;

	
	// img
	int CurrentFrame_;
	int StartFrame_;
	int EndFrame_;
	float CurrentInterTime_;
	float4 CurrentImgScale;
	float4 CurrentImgPivot;
	Direction UnitDirection_;

	void FrameUpdate();

};

