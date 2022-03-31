#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngine/GameEngineActor.h>
#include "GamePlayEnum.h"
#include "GamePlayObject.h"
#include <vector>

// Ό³Έν :
class PlayLevel;
class MainLevel;
class Coordinate : public GameEngineActor
{
	friend PlayLevel;
	friend MainLevel;
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

	//inline void SetCPos(float4 _Pos)
	//{
	//	Pos_ = _Pos;
	//}


protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	float4 Pos_;
	float4 CPos_;
	ObjectName Object_;

	
	// img
	int CurrentFrame_;
	int StartFrame_;
	int EndFrame_;
	float CurrentInterTime_;
	float4 CurrentImgScale;
	float4 CurrentImgPivot;
	Direction UnitDirection_;

	void FrameUpdate();
	void SetImg(GameEngineImage* _Img, Direction _Dir = Direction::None, const float4& _Size = { DotSizeX, DotSizeY });

	GameEngineImage* ObjectImage_;

};

