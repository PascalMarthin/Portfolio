#pragma once
#include "GamePlayText.h"
#include "GamePlayUnitObject.h"

// Ό³Έν :

class GamePlayUnitText : public GamePlayText
{
public:
	// constrcuter destructer
	GamePlayUnitText();
	virtual ~GamePlayUnitText();

	// delete Function
	GamePlayUnitText(const GamePlayUnitText& _Other) = delete;
	GamePlayUnitText(GamePlayUnitText&& _Other) noexcept = delete;
	GamePlayUnitText& operator=(const GamePlayUnitText& _Other) = delete;
	GamePlayUnitText& operator=(GamePlayUnitText&& _Other) noexcept = delete;

	virtual void SettingAbility() {}
	virtual void Destroy() {}

	GamePlayUnitObject* GetTextUnit()
	{
		return TextUnit_;
	}


protected:
	GamePlayUnitObject* TextUnit_;

private:

};


