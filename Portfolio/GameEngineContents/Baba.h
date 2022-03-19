#pragma once
#include "GamePlayUnitObject.h"
#include "GamePlayTextObject.h"

// Ό³Έν :
class Baba_Text;
class Baba_Unit : public GamePlayUnitObject
{
	friend Baba_Text;
public:
	// constrcuter destructer
	Baba_Unit();
	~Baba_Unit();

	// delete Function
	Baba_Unit(const Baba_Unit& _Other) = delete;
	Baba_Unit(Baba_Unit&& _Other) noexcept = delete;
	Baba_Unit& operator=(const Baba_Unit& _Other) = delete;
	Baba_Unit& operator=(Baba_Unit&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override {}
	void Render() override {}

private:

};


class Baba_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Baba_Text();
	~Baba_Text();

	// delete Function
	Baba_Text(const Baba_Text& _Other) = delete;
	Baba_Text(Baba_Text&& _Other) noexcept = delete;
	Baba_Text& operator=(const Baba_Text& _Other) = delete;
	Baba_Text& operator=(Baba_Text&& _Other) noexcept = delete;

protected:

private:

};

