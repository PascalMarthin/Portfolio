#pragma once

// Ό³Έν :
class Lava_Unit
{
public:
	// constrcuter destructer
	Lava_Unit();
	~Lava_Unit();

	// delete Function
	Lava_Unit(const Lava_Unit& _Other) = delete;
	Lava_Unit(Lava_Unit&& _Other) noexcept = delete;
	Lava_Unit& operator=(const Lava_Unit& _Other) = delete;
	Lava_Unit& operator=(Lava_Unit&& _Other) noexcept = delete;

protected:

private:

};

