#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>

// Ό³Έν :
class MainCursor : public GameEngineActor
{
public:
	MainCursor();
	~MainCursor();

	MainCursor(const MainCursor& _Other) = delete;
	MainCursor(MainCursor&& _Other) noexcept = delete;
	MainCursor& operator=(const MainCursor& _Other) = delete;
	MainCursor& operator=(MainCursor&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	int CurrentFrame_;
	float CurrentInterTime_;
	float4 CurrentImgScale_;
	float4 CurrentImgPivot_;

	GameEngineImage* Image_;
};

