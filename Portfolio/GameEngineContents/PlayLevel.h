#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GamePlayGobal.h"

// ���� : Stage ������ �޾� ȭ�鿡 ������ִ� Level
class GamePlayObject;
class Coordinate;
class PlayLevel : public GameEngineLevel
{
public:
	PlayLevel();
	~PlayLevel();

	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart() override;

private:

};

