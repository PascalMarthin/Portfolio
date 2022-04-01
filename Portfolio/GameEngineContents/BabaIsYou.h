#pragma once
#include <GameEngine/GameEngine.h>
#include "GamePlayEnum.h"


// Ό³Έν :
class BabaIsYou : public GameEngine
{
public:
	BabaIsYou();
	~BabaIsYou();

	BabaIsYou(const BabaIsYou& _Other) = delete;
	BabaIsYou(BabaIsYou&& _Other) noexcept = delete;
	BabaIsYou& operator=(const BabaIsYou& _Other) = delete;
	BabaIsYou& operator=(BabaIsYou&& _Other) noexcept = delete;

	void GameInit() override;
	void GameLoop() override;
	void GameEnd() override;


protected:


private:
	void CreateKeyBaba();

};

