#pragma once
#include "GamePlayObject.h"

// Ό³Έν :
class GamePlayTextObject : public GamePlayObject
{
public:
	GamePlayTextObject();
	virtual ~GamePlayTextObject();

	GamePlayTextObject(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject(GamePlayTextObject&& _Other) noexcept = delete;
	GamePlayTextObject& operator=(const GamePlayTextObject& _Other) = delete;
	GamePlayTextObject& operator=(GamePlayTextObject&& _Other) noexcept = delete;

protected:
	virtual void Start() = 0;
	virtual void Update() {}
	virtual void Render() {}

	//virtual bool TextEffect() = 0;
	//virtual void GameSet() = 0;


private:
	TextType TTpye_;

};
