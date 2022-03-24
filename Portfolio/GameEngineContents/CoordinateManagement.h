#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "StageData.h"
#include "GamePalyEnum.h"
#include "Coordinate.h"
#include <list>
#include <map>
#include <vector>

// ���� : ��ǥ�� ����� �����ϴ� Ŭ���� (�̱���XX ��������) 
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

	void Create(const StageData* _Data);

protected:
	

private:
	Stage Stage_;
	float4 MapScale_;

	std::map<int, std::map<int, std::vector<Coordinate*>*>*> MapPos_;
	// need prevData
	
	bool ScanData(const StageData* _Data);

};

