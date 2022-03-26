#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "GamePalyEnum.h"
#include "GamePlayObject.h"
#include <map>

// Ό³Έν :
class PlayLevel;
class Coordinate
{
	friend PlayLevel;
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

private:
	float4 Pos_;
	float4 CPos_;
	std::map<ObjectName ,GamePlayObject*> Object_;

};

