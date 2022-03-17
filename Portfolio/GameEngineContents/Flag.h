#pragma once

// Ό³Έν :
class Flag
{
public:
	// constrcuter destructer
	Flag();
	~Flag();

	// delete Function
	Flag(const Flag& _Other) = delete;
	Flag(Flag&& _Other) noexcept = delete;
	Flag& operator=(const Flag& _Other) = delete;
	Flag& operator=(Flag&& _Other) noexcept = delete;

protected:

private:

};

