#pragma once
#include <GameEngine/GameEngineActor.h>

// ���� :
class GamePlayTextObject : public GameEngineActor
{
public:
	GamePlayTextObject();
	~GamePlayTextObject();

	GamePlayTextObject(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject(GamePlayTextObject&& _Other) noexcept = delete;
	GamePlayTextObject& operator=(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject& operator=(GamePlayTextObject&& _Other) noexcept = delete;

protected:
	virtual void Start() = 0;
	virtual void Update() {}
	virtual void Render() {}

	virtual bool TextEffect() = 0;
	virtual void GameSet() = 0;

	bool IsActivate;

private:

};

