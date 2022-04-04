#pragma once
#include "GamePlayTextStat.h"

// ���� :
class Defeat_Text : public GamePlayTextStat
{
public:
	static Defeat_Text* GetInst()
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

protected:

private:
	static Defeat_Text* Inst_;
	Defeat_Text();
	~Defeat_Text();

	Defeat_Text(const Defeat_Text& _Other) = delete;
	Defeat_Text(Defeat_Text&& _Other) noexcept = delete;
	Defeat_Text& operator=(const Defeat_Text& _Other) = delete;
	Defeat_Text& operator=(Defeat_Text&& _Other) noexcept = delete;

};

