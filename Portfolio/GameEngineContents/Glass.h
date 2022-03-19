#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Glass_Text;
class Glass_Unit : public GamePlayUnitObject
{
	friend Glass_Text;
public:
	Glass_Unit();
	~Glass_Unit();

	// delete Function
	Glass_Unit(const Glass_Unit& _Other) = delete;
	Glass_Unit(Glass_Unit&& _Other) noexcept = delete;
	Glass_Unit& operator=(const Glass_Unit& _Other) = delete;
	Glass_Unit& operator=(Glass_Unit&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override {}
	void Render() override {}

private:

};


class Glass_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Glass_Text();
	~Glass_Text();

	// delete Function
	Glass_Text(const Glass_Text& _Other) = delete;
	Glass_Text(Glass_Text&& _Other) noexcept = delete;
	Glass_Text& operator=(const Glass_Text& _Other) = delete;
	Glass_Text& operator=(Glass_Text&& _Other) noexcept = delete;

protected:

private:

};

