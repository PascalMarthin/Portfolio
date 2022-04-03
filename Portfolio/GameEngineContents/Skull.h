#pragma once
#include "GamePlayUnitText.h"

// ���� :
class Skull_Unit : public GamePlayUnitObject
{
	static Skull_Unit* Inst_;

public:
	static Skull_Unit* GetInst()
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
	Skull_Unit();
	~Skull_Unit();

	Skull_Unit(const Skull_Unit& _Other) = delete;
	Skull_Unit(Skull_Unit&& _Other) noexcept = delete;
	Skull_Unit& operator=(const Skull_Unit& _Other) = delete;
	Skull_Unit& operator=(Skull_Unit&& _Other) noexcept = delete;

};


class Skull_Text : public GamePlayUnitText
{

public:
	static Skull_Text* GetInst()
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
	static Skull_Text* Inst_;
	Skull_Text();
	~Skull_Text();

	Skull_Text(const Skull_Text& _Other) = delete;
	Skull_Text(Skull_Text&& _Other) noexcept = delete;
	Skull_Text& operator=(const Skull_Text& _Other) = delete;
	Skull_Text& operator=(Skull_Text&& _Other) noexcept = delete;

};

