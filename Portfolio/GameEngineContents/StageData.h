#pragma once
#include <map>
#include <vector>
#include <GameEngineBase/GameEngineMath.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class StageData
{
	friend class PlayLevel;
	friend class MainLevel;
private:
	static StageData* Inst_;

public:
	static StageData* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
	{
		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}

private:
	std::map<int, std::map<int, std::map<int, ObjectName>>> StageData_;
	std::map<int, std::map<int, std::vector<ObjectName>>> MainData_;
	std::map<int, float4> Scale_;

	void MainStage();
	void Stage0();
	


	StageData();
	~StageData();

	StageData(const StageData& _Other) = delete;
	StageData(StageData&& _Other) noexcept = delete;
	StageData& operator=(const StageData& _Other) = delete;
	StageData& operator=(StageData&& _Other) noexcept = delete;
	
};

