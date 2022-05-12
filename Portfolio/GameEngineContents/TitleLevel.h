#pragma once
#include <GameEngine/GameEngineLevel.h>
#include "GamePlayEnum.h"
#include "Fade_InAndOut.h"
#include <GameEngineBase/GameEngineSound.h>
#include <vector>
#include "TitleLogo.h"
#include "TitleMenu.h"
#include "PlayAndMainLevelMenu.h"
#include "TitleBaba.h"



// 설명 : title 화면 클래스
class TitleLevel : public GameEngineLevel
{
public:
	TitleLevel();
	~TitleLevel();

	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;


protected:
	void Loading() override;
	void Update() override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;

private:
	void OptionOFF();
	void OptionON();
	void KeyPushInOption();
	bool InOption_;
	Fade_InAndOut* Fade_;
	TitleLogo* Logo_;
	TitleMenu* TitleMenu_;
	TitleBaba* TitleBaba_;
	PlayAndMainLevelMenu* SettingMenu_;
	GameEngineSoundPlayer BackGroundMusicControl_;

};

