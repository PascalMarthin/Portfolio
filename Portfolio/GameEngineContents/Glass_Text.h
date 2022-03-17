#pragma once

// Ό³Έν :
class Glass_Text
{
public:
	// constrcuter destructer
	Glass_Text();
	~Glass_Text();

	// delete Function
	Glass_Text(const Glass_Text& _Other) = delete;
	Glass_Text(Glass_Text&& _Other) noexcept = delete;
	Glass_Text& operator=(const Glass_Text& _Other) = delete;
	Glass_Text& operator=(Glass_Text&& _Other) noexcept = delete;

protected:

private:

};

