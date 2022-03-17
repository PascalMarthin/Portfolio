#pragma once

// Ό³Έν :
class Glass_Unit
{
public:
	// constrcuter destructer
	Glass_Unit();
	~Glass_Unit();

	// delete Function
	Glass_Unit(const Glass_Unit& _Other) = delete;
	Glass_Unit(Glass_Unit&& _Other) noexcept = delete;
	Glass_Unit& operator=(const Glass_Unit& _Other) = delete;
	Glass_Unit& operator=(Glass_Unit&& _Other) noexcept = delete;

protected:

private:

};

