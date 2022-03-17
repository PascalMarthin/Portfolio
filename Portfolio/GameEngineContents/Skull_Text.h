#pragma once

// Ό³Έν :
class Skull_Text
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

