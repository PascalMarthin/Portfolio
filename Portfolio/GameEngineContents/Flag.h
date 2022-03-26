#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Flag_Text;
class Flag_Unit : public GamePlayUnitObject
{
	friend Flag_Text;
public:
	// constrcuter destructer
	Flag_Unit();
	~Flag_Unit();

	// delete Function
	Flag_Unit(const Flag_Unit& _Other) = delete;
	Flag_Unit(Flag_Unit&& _Other) noexcept = delete;
	Flag_Unit& operator=(const Flag_Unit& _Other) = delete;
	Flag_Unit& operator=(Flag_Unit&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};


class Flag_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Flag_Text();
	~Flag_Text();

	// delete Function
	Flag_Text(const Flag_Text& _Other) = delete;
	Flag_Text(Flag_Text&& _Other) noexcept = delete;
	Flag_Text& operator=(const Flag_Text& _Other) = delete;
	Flag_Text& operator=(Flag_Text&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};

