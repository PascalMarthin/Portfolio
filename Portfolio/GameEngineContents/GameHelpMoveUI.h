#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngine/GameEngineRenderer.h>


// Ό³Έν :
class GameHelpMoveUI : public GameEngineActor
{
public:
	// constrcuter destructer
	GameHelpMoveUI();
	~GameHelpMoveUI();

	// delete Function
	GameHelpMoveUI(const GameHelpMoveUI& _Other) = delete;
	GameHelpMoveUI(GameHelpMoveUI&& _Other) noexcept = delete;
	GameHelpMoveUI& operator=(const GameHelpMoveUI& _Other) = delete;
	GameHelpMoveUI& operator=(GameHelpMoveUI&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:

};

