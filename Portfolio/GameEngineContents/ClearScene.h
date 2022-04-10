#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineMath.h>

// Ό³Έν :
class ClearScene : public GameEngineActor
{
public:
	ClearScene();
	~ClearScene();

	ClearScene(const ClearScene& _Other) = delete;
	ClearScene(ClearScene&& _Other) noexcept = delete;
	ClearScene& operator=(const ClearScene& _Other) = delete;
	ClearScene& operator=(ClearScene&& _Other) noexcept = delete;

	void SetStayOFF()
	{
		StayOn_ = false;
		Off();
		CurrentInterTime_ = 0.05f;
		CurrentFrame_ = 0;
		EndFrame_ = 27;
	}

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	GameEngineImage* MakeImage_;
	GameEngineImage* StayImage_;
	float CurrentInterTime_;
	int CurrentFrame_;
	int EndFrame_;
	float4 CurrentImgScale_;
	float4 CurrentImgPivot_;

	bool StayOn_;
};

