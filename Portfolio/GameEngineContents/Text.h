#pragma once
#include "GamePlayUnitObject.h"

// Ό³Έν :

class Text_Unit : public GamePlayUnitObject
{
	static Text_Unit* Inst_;

public:
	static Text_Unit* GetInst()
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
	virtual void Reset() override
	{
		AllStat_ += SPush;
	}

protected:

private:
	Text_Unit();
	~Text_Unit();

	// delete Function
	Text_Unit(const Text_Unit& _Other) = delete;
	Text_Unit(Text_Unit&& _Other) noexcept = delete;
	Text_Unit& operator=(const Text_Unit& _Other) = delete;
	Text_Unit& operator=(Text_Unit&& _Other) noexcept = delete;

};

