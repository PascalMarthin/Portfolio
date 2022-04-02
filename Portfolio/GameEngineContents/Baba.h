#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Baba_Unit : public GamePlayUnitObject
{
	static Baba_Unit* Inst_;

	public:
	static Baba_Unit* GetInst()
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
	Baba_Unit();
	~Baba_Unit();

	Baba_Unit(const Baba_Unit& _Other) = delete;
	Baba_Unit(Baba_Unit&& _Other) noexcept = delete;
	Baba_Unit& operator=(const Baba_Unit& _Other) = delete;
	Baba_Unit& operator=(Baba_Unit&& _Other) noexcept = delete;

};


class Baba_Text : public GamePlayTextObject
{

public:
	static Baba_Text* GetInst()
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
	static Baba_Text* Inst_;
	Baba_Text();
	~Baba_Text();

	Baba_Text(const Baba_Text& _Other) = delete;
	Baba_Text(Baba_Text&& _Other) noexcept = delete;
	Baba_Text& operator=(const Baba_Text& _Other) = delete;
	Baba_Text& operator=(Baba_Text&& _Other) noexcept = delete;

};

