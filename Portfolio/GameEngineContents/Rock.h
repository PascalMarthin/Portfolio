#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Rock_Text;
class Rock_Unit : public GamePlayUnitObject
{
	friend Rock_Text;
public:
	// constrcuter destructer
	Rock_Unit();
	~Rock_Unit();

	// delete Function
	Rock_Unit(const Rock_Unit& _Other) = delete;
	Rock_Unit(Rock_Unit&& _Other) noexcept = delete;
	Rock_Unit& operator=(const Rock_Unit& _Other) = delete;
	Rock_Unit& operator=(Rock_Unit&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};


class Rock_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Rock_Text();
	~Rock_Text();

	// delete Function
	Rock_Text(const Rock_Text& _Other) = delete;
	Rock_Text(Rock_Text&& _Other) noexcept = delete;
	Rock_Text& operator=(const Rock_Text& _Other) = delete;
	Rock_Text& operator=(Rock_Text&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};

