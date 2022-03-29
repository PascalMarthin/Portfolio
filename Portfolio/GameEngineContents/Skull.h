#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Skull_Unit : public GamePlayUnitObject
{
	static Skull_Unit* Inst_;

public:
	static Skull_Unit* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
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
	Skull_Unit();
	~Skull_Unit();

	Skull_Unit(const Skull_Unit& _Other) = delete;
	Skull_Unit(Skull_Unit&& _Other) noexcept = delete;
	Skull_Unit& operator=(const Skull_Unit& _Other) = delete;
	Skull_Unit& operator=(Skull_Unit&& _Other) noexcept = delete;

};


class Skull_Text : public GamePlayTextObject
{

public:
	static Skull_Text* GetInst()
	{
		return Inst_;
	}

	static void Destroy()
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
	static Skull_Text* Inst_;
	Skull_Text();
	~Skull_Text();

	Skull_Text(const Skull_Text& _Other) = delete;
	Skull_Text(Skull_Text&& _Other) noexcept = delete;
	Skull_Text& operator=(const Skull_Text& _Other) = delete;
	Skull_Text& operator=(Skull_Text&& _Other) noexcept = delete;

};

