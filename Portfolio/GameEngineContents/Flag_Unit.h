#pragma once

// Ό³Έν :
class Flag_Unit
{
public:
	// constrcuter destructer
	Flag_Unit();
	~Flag_Unit();

	// delete Function
	Flag_Unit(const Flag_Unit& _Other) = delete;
	Flag_Unit(Flag_Unit&& _Other) noexcept = delete;
	Flag_Unit& operator=(const Flag_Unit& _Other) = delete;
	Flag_Unit& operator=(Flag_Unit&& _Other) noexcept = delete;

protected:

private:

};

