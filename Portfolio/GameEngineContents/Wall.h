#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Wall_Text;
class Wall_Unit : public GamePlayUnitObject
{
	friend Wall_Text;
public:
	// constrcuter destructer
	Wall_Unit();
	~Wall_Unit();

	// delete Function
	Wall_Unit(const Wall_Unit& _Other) = delete;
	Wall_Unit(Wall_Unit&& _Other) noexcept = delete;
	Wall_Unit& operator=(const Wall_Unit& _Other) = delete;
	Wall_Unit& operator=(Wall_Unit&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};


class Wall_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Wall_Text();
	~Wall_Text();

	// delete Function
	Wall_Text(const Wall_Text& _Other) = delete;
	Wall_Text(Wall_Text&& _Other) noexcept = delete;
	Wall_Text& operator=(const Wall_Text& _Other) = delete;
	Wall_Text& operator=(Wall_Text&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};

