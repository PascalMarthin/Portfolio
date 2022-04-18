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
	GameEngineRenderer* Reset_;
	GameEngineRenderer* Undo_;
	float CurrentInterTime_;
	bool IsOver_;
};

