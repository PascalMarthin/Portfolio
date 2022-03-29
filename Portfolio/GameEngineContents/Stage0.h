#pragma once
#include <GameEngineBase/GameEngineMath.h>

class Stage0
{
	static Stage0* Inst_;

public:
	static Stage0* GetInst()
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
	float4 Scale_;

	Stage0();
	~Stage0();

	Stage0(const Stage0& _Other) = delete;
	Stage0(Stage0&& _Other) noexcept = delete;
	Stage0& operator=(const Stage0& _Other) = delete;
	Stage0& operator=(Stage0&& _Other) noexcept = delete;
};