#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class TitleLevel;
class TitleMenu;
class TitleBaba : public GameEngineActor
{
	friend TitleLevel;
	friend TitleMenu;
public:
	// constrcuter destructer
	TitleBaba();
	~TitleBaba();

	// delete Function
	TitleBaba(const TitleBaba& _Other) = delete;
	TitleBaba(TitleBaba&& _Other) noexcept = delete;
	TitleBaba& operator=(const TitleBaba& _Other) = delete;
	TitleBaba& operator=(TitleBaba&& _Other) noexcept = delete;



protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	static BabaLocation BabaTitleLocate_;
	GameEngineRenderer* Render_;

	GameEngineImage* BabaImgSheet_;
	GameEngineImage* BabaImg_;

	float4 BabaPos_;
};

