#pragma once
#include <GameEngine/GameEngine.h>

// Ό³Έν :
class BabaIsYou : public GameEngine
{
public:
	// constrcuter destructer
	BabaIsYou();
	~BabaIsYou();

	// delete Function
	BabaIsYou(const BabaIsYou& _Other) = delete;
	BabaIsYou(BabaIsYou&& _Other) noexcept = delete;
	BabaIsYou& operator=(const BabaIsYou& _Other) = delete;
	BabaIsYou& operator=(BabaIsYou&& _Other) noexcept = delete;

protected:

private:

};

