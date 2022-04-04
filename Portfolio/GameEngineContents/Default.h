#pragma once
#include "GamePlayUnitObject.h"

// ���� :
class Default : public GamePlayUnitObject
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
	void SettingAbility() override;

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
