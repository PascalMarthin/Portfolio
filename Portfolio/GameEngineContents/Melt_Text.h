#pragma once

// Ό³Έν :
class Melt_Text
{
public:
	// constrcuter destructer
	Melt_Text();
	~Melt_Text();

	// delete Function
	Melt_Text(const Melt_Text& _Other) = delete;
	Melt_Text(Melt_Text&& _Other) noexcept = delete;
	Melt_Text& operator=(const Melt_Text& _Other) = delete;
	Melt_Text& operator=(Melt_Text&& _Other) noexcept = delete;

protected:

private:

};

