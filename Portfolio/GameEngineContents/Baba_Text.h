#pragma once

// Ό³Έν :
class Baba_Text
{
public:
	// constrcuter destructer
	Baba_Text();
	~Baba_Text();

	// delete Function
	Baba_Text(const Baba_Text& _Other) = delete;
	Baba_Text(Baba_Text&& _Other) noexcept = delete;
	Baba_Text& operator=(const Baba_Text& _Other) = delete;
	Baba_Text& operator=(Baba_Text&& _Other) noexcept = delete;

protected:

private:

};

