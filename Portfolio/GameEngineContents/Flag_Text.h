#pragma once

// Ό³Έν :
class Flag_Text
{
public:
	// constrcuter destructer
	Flag_Text();
	~Flag_Text();

	// delete Function
	Flag_Text(const Flag_Text& _Other) = delete;
	Flag_Text(Flag_Text&& _Other) noexcept = delete;
	Flag_Text& operator=(const Flag_Text& _Other) = delete;
	Flag_Text& operator=(Flag_Text&& _Other) noexcept = delete;

protected:

private:

};

