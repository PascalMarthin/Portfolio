#pragma once
#include "GamePlayTextObject.h"

// Ό³Έν :
class Is_Text : public GamePlayTextObject
{

public:
	static Is_Text* GetInst()
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
	void SettingImg() override;

private:
	static Is_Text* Inst_;
	Is_Text();
	~Is_Text();

	Is_Text(const Is_Text& _Other) = delete;
	Is_Text(Is_Text&& _Other) noexcept = delete;
	Is_Text& operator=(const Is_Text& _Other) = delete;
	Is_Text& operator=(Is_Text&& _Other) noexcept = delete;

};

