#pragma once
#include <GameEngine/GameEngineActor.h>

// ���� :
class PlayBackGround : public GameEngineActor
{
public:
	PlayBackGround();
	~PlayBackGround();

	PlayBackGround(const PlayBackGround& _Other) = delete;
	PlayBackGround(PlayBackGround&& _Other) noexcept = delete;
	PlayBackGround& operator=(const PlayBackGround& _Other) = delete;
	PlayBackGround& operator=(PlayBackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
};

