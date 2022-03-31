#pragma once
#include "GamePlayTextObject.h"

// Ό³Έν :
class Default : public GamePlayTextObject
{
public:
	static Default* GetInst()
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
	void SettingImg() override;

public:
	static Default* Inst_;
	Default();
	~Default();

	Default(const Default& _Other) = delete;
	Default(Default&& _Other) noexcept = delete;
	Default& operator=(const Default& _Other) = delete;
	Default& operator=(Default&& _Other) noexcept = delete;

protected:

private:

};
