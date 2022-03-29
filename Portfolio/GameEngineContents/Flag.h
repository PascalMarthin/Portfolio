#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Flag_Unit : public GamePlayUnitObject
{
	static Flag_Unit* Inst_;

public:
	static Flag_Unit* GetInst()
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
	void SettingImg() override;

private:
	Flag_Unit();
	~Flag_Unit();

	Flag_Unit(const Flag_Unit& _Other) = delete;
	Flag_Unit(Flag_Unit&& _Other) noexcept = delete;
	Flag_Unit& operator=(const Flag_Unit& _Other) = delete;
	Flag_Unit& operator=(Flag_Unit&& _Other) noexcept = delete;

};


class Flag_Text : public GamePlayTextObject
{

public:
	static Flag_Text* GetInst()
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
	void SettingImg() override;

private:
	static Flag_Text* Inst_;
	Flag_Text();
	~Flag_Text();

	Flag_Text(const Flag_Text& _Other) = delete;
	Flag_Text(Flag_Text&& _Other) noexcept = delete;
	Flag_Text& operator=(const Flag_Text& _Other) = delete;
	Flag_Text& operator=(Flag_Text&& _Other) noexcept = delete;

};

