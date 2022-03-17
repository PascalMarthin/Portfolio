#pragma once

// Ό³Έν :
class Wall_Unit
{
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

private:

};

