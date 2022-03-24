#pragma once
#include "GamePalyEnum.h"
#include <GameEngineBase/GameEngineMath.h>
#include <vector>


// ���� : �ϳ��� ��ǥ�� ������Ʈ�� ������ ������ �ִ� Ŭ����
//class CoordinateManagement; friend
class Coordinate
{
public:
	// constrcuter destructer
	Coordinate();
	Coordinate(float4 _Pos, Stage _Stage, ObjectName _Object); // �������ڸ� ���� ����
	Coordinate(float4 _Pos, ObjectName _Object);
	Coordinate(ObjectName _Object);
	~Coordinate();

	// delete Function
	Coordinate(const Coordinate& _Other) = delete;
	Coordinate(Coordinate&& _Other) noexcept = delete;
	Coordinate& operator=(const Coordinate& _Other) = delete;
	Coordinate& operator=(Coordinate&& _Other) noexcept = delete;

	inline void SetPos(float4 _Idx)
	{
		Pos_ = _Idx;
	}
	template<typename T>
	inline void SetPos(T _x, T _y)
	{
		Pos_.x = _x;
		Pos_.y = _y;
	}

	inline void SetStage(Stage _Value)
	{
		Stage_ = _Value;
	}

protected:

	
private:

	// ���� ������ �ȹٲ�
	float4 Pos_;
	Stage Stage_;


	std::vector<ObjectName> Object_;
};

