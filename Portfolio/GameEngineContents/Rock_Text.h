#pragma once

// Ό³Έν :
class Rock_Text
{
public:
	// constrcuter destructer
	Rock_Text();
	~Rock_Text();

	// delete Function
	Rock_Text(const Rock_Text& _Other) = delete;
	Rock_Text(Rock_Text&& _Other) noexcept = delete;
	Rock_Text& operator=(const Rock_Text& _Other) = delete;
	Rock_Text& operator=(Rock_Text&& _Other) noexcept = delete;

protected:

private:

};

