#pragma once
#include "GamePlayTextObject.h"

// Ό³Έν :
class Defeat_Text : public GamePlayTextObject
{
public:
	// constrcuter destructer
	Defeat_Text();
	~Defeat_Text();

	// delete Function
	Defeat_Text(const Defeat_Text& _Other) = delete;
	Defeat_Text(Defeat_Text&& _Other) noexcept = delete;
	Defeat_Text& operator=(const Defeat_Text& _Other) = delete;
	Defeat_Text& operator=(Defeat_Text&& _Other) noexcept = delete;

protected:
	void Start() override {}
	void Update() override {}
	void Render() override {}

private:

};

