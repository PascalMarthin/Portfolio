#pragma once
#include "GamePlayTextStat.h"
// Ό³Έν :
class Dummy_Text : public GamePlayTextStat
{
public:
	static Dummy_Text* GetInst()
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
	static Dummy_Text* Inst_;
	Dummy_Text();
	~Dummy_Text();

	// delete Function
	Dummy_Text(const Dummy_Text& _Other) = delete;
	Dummy_Text(Dummy_Text&& _Other) noexcept = delete;
	Dummy_Text& operator=(const Dummy_Text& _Other) = delete;
	Dummy_Text& operator=(Dummy_Text&& _Other) noexcept = delete;

};
