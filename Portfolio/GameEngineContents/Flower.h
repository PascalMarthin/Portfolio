#pragma once
#include "GamePlayUnitObject.h"

// Ό³Έν :
class Flower_Unit : public GamePlayUnitObject
{
	static Flower_Unit* Inst_;

public:
	static Flower_Unit* GetInst()
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
	Flower_Unit();
	~Flower_Unit();

	Flower_Unit(const Flower_Unit& _Other) = delete;
	Flower_Unit(Flower_Unit&& _Other) noexcept = delete;
	Flower_Unit& operator=(const Flower_Unit& _Other) = delete;
	Flower_Unit& operator=(Flower_Unit&& _Other) noexcept = delete;

};
