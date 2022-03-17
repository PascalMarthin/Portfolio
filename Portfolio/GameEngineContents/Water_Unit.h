#pragma once

// Ό³Έν :
class Water_Unit
{
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

private:

};

