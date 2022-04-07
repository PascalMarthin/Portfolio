#pragma once
#include "GamePlayText.h"

// Ό³Έν :
class Is_Text : public GamePlayText
{

public:
	static Is_Text* GetInst()
	{
		return Inst_;
	}

	void Destroy() override
	{
		if (nullptr == Inst_)
		{
			return;
		}

		delete Inst_;
		Inst_ = nullptr;
	}
	void SettingAbility() override;
	const std::vector<std::pair<int, int>>* GetAnimationTake(Direction _Dir) override;

private:
	static Is_Text* Inst_;
	Is_Text();
	~Is_Text();

	Is_Text(const Is_Text& _Other) = delete;
	Is_Text(Is_Text&& _Other) noexcept = delete;
	Is_Text& operator=(const Is_Text& _Other) = delete;
	Is_Text& operator=(Is_Text&& _Other) noexcept = delete;

};

