#pragma once
#include <GameEngine/GameEngineActor.h>

// Ό³Έν :
class PlayAndMainLevelMenu : public GameEngineActor
{
public:

	PlayAndMainLevelMenu();
	~PlayAndMainLevelMenu();


	PlayAndMainLevelMenu(const PlayAndMainLevelMenu& _Other) = delete;
	PlayAndMainLevelMenu(PlayAndMainLevelMenu&& _Other) noexcept = delete;
	PlayAndMainLevelMenu& operator=(const PlayAndMainLevelMenu& _Other) = delete;
	PlayAndMainLevelMenu& operator=(PlayAndMainLevelMenu&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
};

