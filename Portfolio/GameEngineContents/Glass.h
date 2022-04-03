#pragma once
#include "GamePlayUnitObject.h"

// Ό³Έν :
class Grass_Unit : public GamePlayUnitObject
{
	static Grass_Unit* Inst_;

public:
	static Grass_Unit* GetInst()
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

private:
	Grass_Unit();
	~Grass_Unit();

	Grass_Unit(const Grass_Unit& _Other) = delete;
	Grass_Unit(Grass_Unit&& _Other) noexcept = delete;
	Grass_Unit& operator=(const Grass_Unit& _Other) = delete;
	Grass_Unit& operator=(Grass_Unit&& _Other) noexcept = delete;

};
