#pragma once

// Ό³Έν :
class Rock_Unit
{
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

private:

};

