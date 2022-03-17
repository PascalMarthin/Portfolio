#pragma once

// Ό³Έν :
class Water_Text
{
public:
	// constrcuter destructer
	Water_Text();
	~Water_Text();

	// delete Function
	Water_Text(const Water_Text& _Other) = delete;
	Water_Text(Water_Text&& _Other) noexcept = delete;
	Water_Text& operator=(const Water_Text& _Other) = delete;
	Water_Text& operator=(Water_Text&& _Other) noexcept = delete;

protected:

private:

};

