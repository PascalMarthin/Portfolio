#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Skull_Text;
class Skull_Unit : public GamePlayUnitObject
{
	friend Skull_Text;
public:
	// constrcuter destructer
	Skull_Unit();
	~Skull_Unit();

	// delete Function
	Skull_Unit(const Skull_Unit& _Other) = delete;
	Skull_Unit(Skull_Unit&& _Other) noexcept = delete;
	Skull_Unit& operator=(const Skull_Unit& _Other) = delete;
	Skull_Unit& operator=(Skull_Unit&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override {}
	void Render() override {}

private:

};


class Skull_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Skull_Text();
	~Skull_Text();

	// delete Function
	Skull_Text(const Skull_Text& _Other) = delete;
	Skull_Text(Skull_Text&& _Other) noexcept = delete;
	Skull_Text& operator=(const Skull_Text& _Other) = delete;
	Skull_Text& operator=(Skull_Text&& _Other) noexcept = delete;

protected:

private:

};

