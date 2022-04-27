#pragma once
#include <map>
#include <vector>
#include <GameEngineBase/GameEngineMath.h>
#include <string>
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
	std::map<Stage, std::map<int, std::map<int, ObjectName>>> StageData_;
	std::map<Stage, float4> Scale_;
	std::map<Stage, std::string> TitleString_;

	void MainStage();
	void Stage0();
	void Stage1();
	void Stage2();
	void Stage3();
	void Stage4();
	void Stage5();
	void Stage6();
	void Stage7();
	void DebugStage();


	StageData();
	~StageData();

	StageData(const StageData& _Other) = delete;
	StageData(StageData&& _Other) noexcept = delete;
	StageData& operator=(const StageData& _Other) = delete;
	StageData& operator=(StageData&& _Other) noexcept = delete;
	
};

