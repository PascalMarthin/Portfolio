#pragma once
#include <GameEngine/GameEngineLevel.h>
#include <GameEngineBase/GameEngineSound.h>

// Ό³Έν :
class DebugLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	DebugLevel();
	~DebugLevel();

	// delete Function
	DebugLevel(const DebugLevel& _Other) = delete;
	DebugLevel(DebugLevel&& _Other) noexcept = delete;
	DebugLevel& operator=(const DebugLevel& _Other) = delete;
	DebugLevel& operator=(DebugLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override {}
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override {}

private:

};

