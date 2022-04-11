#pragma once
#include "GamePlayUnitText.h"

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
	const std::vector<std::pair<int, int>>* GetAnimationTake(Direction _Dir) override;

private:
	Grass_Unit();
	~Grass_Unit();

	Grass_Unit(const Grass_Unit& _Other) = delete;
	Grass_Unit(Grass_Unit&& _Other) noexcept = delete;
	Grass_Unit& operator=(const Grass_Unit& _Other) = delete;
	Grass_Unit& operator=(Grass_Unit&& _Other) noexcept = delete;

};

class Grass_Text : public GamePlayUnitText
{

public:
	static Grass_Text* GetInst()
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
	static Grass_Text* Inst_;
	Grass_Text();
	~Grass_Text();

	Grass_Text(const Grass_Text& _Other) = delete;
	Grass_Text(Grass_Text&& _Other) noexcept = delete;
	Grass_Text& operator=(const Grass_Text& _Other) = delete;
	Grass_Text& operator=(Grass_Text&& _Other) noexcept = delete;

};

