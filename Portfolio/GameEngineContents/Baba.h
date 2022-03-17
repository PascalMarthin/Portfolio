#pragma once

// Ό³Έν :
class Baba
{
public:
	// constrcuter destructer
	Baba();
	~Baba();

	// delete Function
	Baba(const Baba& _Other) = delete;
	Baba(Baba&& _Other) noexcept = delete;
	Baba& operator=(const Baba& _Other) = delete;
	Baba& operator=(Baba&& _Other) noexcept = delete;

protected:

private:

};

