#pragma once
#include <GameEngine/GameEngineLevel.h>

// 설명 : play 화면 클래스
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

