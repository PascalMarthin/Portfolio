#pragma once

// Ό³Έν :
class Wall_Text
{
public:
	// constrcuter destructer
	Wall_Text();
	~Wall_Text();

	// delete Function
	Wall_Text(const Wall_Text& _Other) = delete;
	Wall_Text(Wall_Text&& _Other) noexcept = delete;
	Wall_Text& operator=(const Wall_Text& _Other) = delete;
	Wall_Text& operator=(Wall_Text&& _Other) noexcept = delete;

protected:

private:

};

