#pragma once

// Ό³Έν :
class Skull_Unit
{
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

private:

};

