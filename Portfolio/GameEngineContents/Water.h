#pragma once
#include "GamePlayUnitText.h"

// Ό³Έν :
class Water_Unit : public GamePlayUnitObject
{
	static Water_Unit* Inst_;

public:
	static Water_Unit* GetInst()
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
	std::vector<std::pair<int, int>>* GetAnimationTake(Direction _Dir) override { return nullptr; }

private:
	Water_Unit();
	~Water_Unit();

	Water_Unit(const Water_Unit& _Other) = delete;
	Water_Unit(Water_Unit&& _Other) noexcept = delete;
	Water_Unit& operator=(const Water_Unit& _Other) = delete;
	Water_Unit& operator=(Water_Unit&& _Other) noexcept = delete;

};


class Water_Text : public GamePlayUnitText
{

public:
	static Water_Text* GetInst()
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
	std::vector<std::pair<int, int>>* GetAnimationTake(Direction _Dir) override;

private:
	static Water_Text* Inst_;
	Water_Text();
	~Water_Text();

	Water_Text(const Water_Text& _Other) = delete;
	Water_Text(Water_Text&& _Other) noexcept = delete;
	Water_Text& operator=(const Water_Text& _Other) = delete;
	Water_Text& operator=(Water_Text&& _Other) noexcept = delete;

};

