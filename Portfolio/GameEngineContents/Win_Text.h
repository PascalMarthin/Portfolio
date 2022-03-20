#pragma once

// Ό³Έν :
class Win_Text
{
public:
	// constrcuter destructer
	Win_Text();
	~Win_Text();

	// delete Function
	Win_Text(const Win_Text& _Other) = delete;
	Win_Text(Win_Text&& _Other) noexcept = delete;
	Win_Text& operator=(const Win_Text& _Other) = delete;
	Win_Text& operator=(Win_Text&& _Other) noexcept = delete;

protected:

private:

};

