#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>
#include <queue>

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

	void MoveCursor(const float4& _Pos);

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	int CurrentFrame_;
	float CurrentInterTime_;
	float4 CurrentImgScale_;
	float4 CurrentImgPivot_;

	std::queue<float4> QueueList_;

	GameEngineImage* Image_;
};

