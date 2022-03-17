#pragma once

// Ό³Έν :
class Baba_Unit
{
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

private:

};

