#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Lava_Text;
class Lava_Unit : public GamePlayUnitObject
{
	friend Lava_Text;
public:
	// constrcuter destructer
	Lava_Unit();
	~Lava_Unit();

	// delete Function
	Lava_Unit(const Lava_Unit& _Other) = delete;
	Lava_Unit(Lava_Unit&& _Other) noexcept = delete;
	Lava_Unit& operator=(const Lava_Unit& _Other) = delete;
	Lava_Unit& operator=(Lava_Unit&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override {}
	void Render() override {}

private:

};


class Lava_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Lava_Text();
	~Lava_Text();

	// delete Function
	Lava_Text(const Lava_Text& _Other) = delete;
	Lava_Text(Lava_Text&& _Other) noexcept = delete;
	Lava_Text& operator=(const Lava_Text& _Other) = delete;
	Lava_Text& operator=(Lava_Text&& _Other) noexcept = delete;

protected:

private:

};

