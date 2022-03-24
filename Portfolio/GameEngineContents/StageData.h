#pragma once
#include "GamePalyEnum.h"
#include <GameEngineBase/GameEngineMath.h>
#include <list>
#include <map>
#include <GameEngineBase/GameEngineDebug.h>
#include "Coordinate.h"

// ���� : �� Stage �����͸� �����ϴ� Ŭ����
class CoordinateManagement;
class StageData
{
	friend CoordinateManagement;
public:
	StageData();
	virtual ~StageData();

	StageData(const StageData& _Other) = delete;
	StageData(StageData&& _Other) noexcept = delete;
	StageData& operator=(const StageData& _Other) = delete;
	StageData& operator=(StageData&& _Other) noexcept = delete;

	

protected:
	inline void SetScale(float4 _Value)
	{
		MapScale_ = _Value;
	}

	inline float4 GetScale() const
	{
		return MapScale_;
	}

	inline void SetStage(Stage _Stage)
	{
		Stage_ = _Stage;
	}
	inline Stage GetStage() const
	{
		return Stage_;
	}

	// ���� ���� �Ҵ��ؾ��ϴ°�?
	std::map<int, std::map<int , ObjectName>> Data_;

private:
	float4 MapScale_;
	Stage Stage_;

};


