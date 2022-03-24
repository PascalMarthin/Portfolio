#pragma once

// Ό³Έν :
class ScreenFade
{
public:
	// constrcuter destructer
	ScreenFade();
	~ScreenFade();

	// delete Function
	ScreenFade(const ScreenFade& _Other) = delete;
	ScreenFade(ScreenFade&& _Other) noexcept = delete;
	ScreenFade& operator=(const ScreenFade& _Other) = delete;
	ScreenFade& operator=(ScreenFade&& _Other) noexcept = delete;

protected:

private:

};

