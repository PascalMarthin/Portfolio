#pragma once
#include "GamePlayUnitText.h"
	// Ό³Έν :
class Brick_Unit : public GamePlayUnitObject
{
	static Brick_Unit* Inst_;

public:
	static Brick_Unit* GetInst()
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
	Brick_Unit();
	~Brick_Unit();

	Brick_Unit(const Brick_Unit& _Other) = delete;
	Brick_Unit(Brick_Unit&& _Other) noexcept = delete;
	Brick_Unit& operator=(const Brick_Unit& _Other) = delete;
	Brick_Unit& operator=(Brick_Unit&& _Other) noexcept = delete;

};


class Brick_Text : public GamePlayUnitText
{

public:
	static Brick_Text* GetInst()
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
	static Brick_Text* Inst_;
	Brick_Text();
	~Brick_Text();

	Brick_Text(const Brick_Text& _Other) = delete;
	Brick_Text(Brick_Text&& _Other) noexcept = delete;
	Brick_Text& operator=(const Brick_Text& _Other) = delete;
	Brick_Text& operator=(Brick_Text&& _Other) noexcept = delete;

};

