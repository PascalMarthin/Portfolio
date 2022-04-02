#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Wall_Unit : public GamePlayUnitObject
{
	static Wall_Unit* Inst_;

public:
	static Wall_Unit* GetInst()
	{
		return Inst_;
	}

	void Destroy()
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
	Wall_Unit();
	~Wall_Unit();

	Wall_Unit(const Wall_Unit& _Other) = delete;
	Wall_Unit(Wall_Unit&& _Other) noexcept = delete;
	Wall_Unit& operator=(const Wall_Unit& _Other) = delete;
	Wall_Unit& operator=(Wall_Unit&& _Other) noexcept = delete;

};


class Wall_Text : public GamePlayTextObject
{

public:
	static Wall_Text* GetInst()
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
	static Wall_Text* Inst_;
	Wall_Text();
	~Wall_Text();

	Wall_Text(const Wall_Text& _Other) = delete;
	Wall_Text(Wall_Text&& _Other) noexcept = delete;
	Wall_Text& operator=(const Wall_Text& _Other) = delete;
	Wall_Text& operator=(Wall_Text&& _Other) noexcept = delete;

};

