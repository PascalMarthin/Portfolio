#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "StageData.h"
#include "GamePalyEnum.h"
#include "Coordinate.h"
#include <list>
#include <map>
#include <vector>

// 설명 : 좌표를 만들고 관리하는 클래스 (싱글톤XX 하지말것) 
class CoordinateManagement
{

public:
	CoordinateManagement();
	~CoordinateManagement();

	CoordinateManagement(const CoordinateManagement& _Other) = delete;
	CoordinateManagement(CoordinateManagement&& _Other) noexcept = delete;
	CoordinateManagement& operator=(const CoordinateManagement& _Other) = delete;
	CoordinateManagement& operator=(CoordinateManagement&& _Other) noexcept = delete;


	inline float4 GetMapScale() const
	{
		return MapScale_;
	}
	inline Stage GetStage() const
	{
		return Stage_;
	}
	// const 차후에 붙히기
	void Create(StageData* _Data);

protected:
	

private:
	Stage Stage_;
	float4 MapScale_;

	std::map<int ,std::map<int ,Coordinate*>> Map_;
	// need prevData
	
	bool ScanData(StageData* _Data);

};

