#pragma once

// Ό³Έν :
class Lava_Text
{
public:
	// constrcuter destructer
	Lava_Text();
	~Lava_Text();

	// delete Function
	Lava_Text(const Lava_Text& _Other) = delete;
	Lava_Text(Lava_Text&& _Other) noexcept = delete;
	Lava_Text& operator=(const Lava_Text& _Other) = delete;
	Lava_Text& operator=(Lava_Text&& _Other) noexcept = delete;

protected:

private:

};

