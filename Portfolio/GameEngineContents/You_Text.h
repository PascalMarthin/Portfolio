#pragma once

// Ό³Έν :
class You_Text
{
public:
	// constrcuter destructer
	You_Text();
	~You_Text();

	// delete Function
	You_Text(const You_Text& _Other) = delete;
	You_Text(You_Text&& _Other) noexcept = delete;
	You_Text& operator=(const You_Text& _Other) = delete;
	You_Text& operator=(You_Text&& _Other) noexcept = delete;

protected:

private:

};

