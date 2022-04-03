#pragma once
#include "GamePlayUnitText.h"
// Ό³Έν :
class Lava_Unit : public GamePlayUnitObject
{
	static Lava_Unit* Inst_;

public:
	static Lava_Unit* GetInst()
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
	Lava_Unit();
	~Lava_Unit();

	Lava_Unit(const Lava_Unit& _Other) = delete;
	Lava_Unit(Lava_Unit&& _Other) noexcept = delete;
	Lava_Unit& operator=(const Lava_Unit& _Other) = delete;
	Lava_Unit& operator=(Lava_Unit&& _Other) noexcept = delete;

};


class Lava_Text : public GamePlayUnitText
{

public:
	static Lava_Text* GetInst()
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
	static Lava_Text* Inst_;
	Lava_Text();
	~Lava_Text();

	Lava_Text(const Lava_Text& _Other) = delete;
	Lava_Text(Lava_Text&& _Other) noexcept = delete;
	Lava_Text& operator=(const Lava_Text& _Other) = delete;
	Lava_Text& operator=(Lava_Text&& _Other) noexcept = delete;

};

