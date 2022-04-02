#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Rock_Unit : public GamePlayUnitObject
{
	static Rock_Unit* Inst_;

public:
	static Rock_Unit* GetInst()
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
	Rock_Unit();
	~Rock_Unit();

	Rock_Unit(const Rock_Unit& _Other) = delete;
	Rock_Unit(Rock_Unit&& _Other) noexcept = delete;
	Rock_Unit& operator=(const Rock_Unit& _Other) = delete;
	Rock_Unit& operator=(Rock_Unit&& _Other) noexcept = delete;

};


class Rock_Text : public GamePlayTextObject
{

public:
	static Rock_Text* GetInst()
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
	static Rock_Text* Inst_;
	Rock_Text();
	~Rock_Text();

	Rock_Text(const Rock_Text& _Other) = delete;
	Rock_Text(Rock_Text&& _Other) noexcept = delete;
	Rock_Text& operator=(const Rock_Text& _Other) = delete;
	Rock_Text& operator=(Rock_Text&& _Other) noexcept = delete;

};

