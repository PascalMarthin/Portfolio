#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineRenderer.h>

// Ό³Έν :
class AlphaBackGround : public GameEngineActor
{
public:
	AlphaBackGround();
	~AlphaBackGround();

	AlphaBackGround(const AlphaBackGround& _Other) = delete;
	AlphaBackGround(AlphaBackGround&& _Other) noexcept = delete;
	AlphaBackGround& operator=(const AlphaBackGround& _Other) = delete;
	AlphaBackGround& operator=(AlphaBackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
};

