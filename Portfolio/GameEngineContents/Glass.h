#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Glass_Unit : public GamePlayUnitObject
{
	static Glass_Unit* Inst_;

public:
	static Glass_Unit* GetInst()
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
	Glass_Unit();
	~Glass_Unit();

	Glass_Unit(const Glass_Unit& _Other) = delete;
	Glass_Unit(Glass_Unit&& _Other) noexcept = delete;
	Glass_Unit& operator=(const Glass_Unit& _Other) = delete;
	Glass_Unit& operator=(Glass_Unit&& _Other) noexcept = delete;

};
