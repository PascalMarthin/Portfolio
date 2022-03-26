#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Empty_Text;
class Empty_Unit : public GamePlayUnitObject
{
	friend Empty_Text;
public:
	// constrcuter destructer
	Empty_Unit();
	~Empty_Unit();

	// delete Function
	Empty_Unit(const Empty_Unit& _Other) = delete;
	Empty_Unit(Empty_Unit&& _Other) noexcept = delete;
	Empty_Unit& operator=(const Empty_Unit& _Other) = delete;
	Empty_Unit& operator=(Empty_Unit&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};


class Empty_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Empty_Text();
	~Empty_Text();

	// delete Function
	Empty_Text(const Empty_Text& _Other) = delete;
	Empty_Text(Empty_Text&& _Other) noexcept = delete;
	Empty_Text& operator=(const Empty_Text& _Other) = delete;
	Empty_Text& operator=(Empty_Text&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};

