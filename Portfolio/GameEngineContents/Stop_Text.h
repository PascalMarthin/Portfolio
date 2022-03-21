#pragma once

// Ό³Έν :
class Stop_Text
{
public:
	// constrcuter destructer
	Stop_Text();
	~Stop_Text();

	// delete Function
	Stop_Text(const Stop_Text& _Other) = delete;
	Stop_Text(Stop_Text&& _Other) noexcept = delete;
	Stop_Text& operator=(const Stop_Text& _Other) = delete;
	Stop_Text& operator=(Stop_Text&& _Other) noexcept = delete;

protected:

private:

};

