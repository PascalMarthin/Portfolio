#pragma once

// Ό³Έν :
class Push_Text
{
public:
	// constrcuter destructer
	Push_Text();
	~Push_Text();

	// delete Function
	Push_Text(const Push_Text& _Other) = delete;
	Push_Text(Push_Text&& _Other) noexcept = delete;
	Push_Text& operator=(const Push_Text& _Other) = delete;
	Push_Text& operator=(Push_Text&& _Other) noexcept = delete;

protected:

private:

};

