#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngine/GameEngineRenderer.h>


// Ό³Έν :
class GameHelpOverUI : public GameEngineActor
{
public:

	GameHelpOverUI();
	~GameHelpOverUI();

	// delete Function
	GameHelpOverUI(const GameHelpOverUI& _Other) = delete;
	GameHelpOverUI(GameHelpOverUI&& _Other) noexcept = delete;
	GameHelpOverUI& operator=(const GameHelpOverUI& _Other) = delete;
	GameHelpOverUI& operator=(GameHelpOverUI&& _Other) noexcept = delete;

	void SetOver();
	void SetBack();

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	GameEngineImage* Restart_;
	GameEngineImage* Undo_;
	GameEngineImage* KeyR_;
	GameEngineImage* KeyZ_;
	GameEngineImage* KeyR_Alpha_;
	GameEngineImage* KeyZ_Alpha_;

	//
	float CurrentWaitTime_;
	float CurrentInterTime_;
	int CurrentFrame_;
	int EndFrame_;

	float4 CurrentUndoImgScale_;
	float4 CurrentUndoImgPivot_;

	float4 CurrentResetImgScale_;
	float4 CurrentResetImgPivot_;

	float Angle_;
	float AngleIndex_;
	float AngleValue_;
	//
	bool IsOver_;
	bool Effect_;
};

