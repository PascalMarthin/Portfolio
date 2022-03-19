#pragma once

// 설명 :
#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// 설명 :
class Water_Text;
class Water_Unit : public GamePlayUnitObject
{
	friend Water_Text;
public:
	// constrcuter destructer
	Water_Unit();
	~Water_Unit();

	// delete Function
	Water_Unit(const Water_Unit& _Other) = delete;
	Water_Unit(Water_Unit&& _Other) noexcept = delete;
	Water_Unit& operator=(const Water_Unit& _Other) = delete;
	Water_Unit& operator=(Water_Unit&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override {}
	void Render() override {}

private:

};


class Water_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Water_Text();
	~Water_Text();

	// delete Function
	Water_Text(const Water_Text& _Other) = delete;
	Water_Text(Water_Text&& _Other) noexcept = delete;
	Water_Text& operator=(const Water_Text& _Other) = delete;
	Water_Text& operator=(Water_Text&& _Other) noexcept = delete;

protected:


private:

};

