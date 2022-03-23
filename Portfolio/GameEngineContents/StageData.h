#pragma once
#include "GamePlayObjectNameEnum.h"
#include <GameEngineBase/GameEngineMath.h>
#include <vector>
#include <map>
#include <GameEngineBase/GameEngineDebug.h>

// Ό³Έν :
class StageData
{
public:
	StageData();
	virtual ~StageData();

	StageData(const StageData& _Other) = delete;
	StageData(StageData&& _Other) noexcept = delete;
	StageData& operator=(const StageData& _Other) = delete;
	StageData& operator=(StageData&& _Other) noexcept = delete;

	

protected:
	inline void SetScale_(float4 _Value)
	{
		MapScale_ = _Value;
	}

	inline float4 GetScale_()
	{
		return MapScale_;
	}

	std::map<int, std::map<int, std::vector<ObjectName>>> Data_;

private:
	float4 MapScale_;

	void FillObject(const ObjectName _Value);
	void CreateMap();
	bool CheckError();
};


