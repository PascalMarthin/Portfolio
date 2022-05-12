#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "TitleLogo.h"
#include "BackGround.h"
#include "TitleMenu.h"
#include "GamePlayEnum.h"
#include "TitleBaba.h"
#include "TitleBackGroundStage.h"
#include "AlphaBackGround.h"
#include "PlayAndMainLevelMenu.h"
#include "GamePlayGobal.h"


TitleLevel::TitleLevel()
	: Fade_(nullptr)
	, InOption_(false)
	, Logo_(nullptr)
	, TitleMenu_(nullptr)
	, SettingMenu_(nullptr)
	, TitleBaba_(nullptr)
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	GameEngineSound::Update();
	Fade_->ShowFadeIn();
	BackGroundMusicControl_ = GameEngineSound::SoundPlayControl("menu.ogg");
	OptionOFF();
}

void TitleLevel::Loading()
{
	CreateActor<AlphaBackGround>(2);
	CreateActor<TitleBackGroundStage>(1);
	CreateActor<BackGround>(0);
	{
		Fade_ = CreateActor<Fade_InAndOut>(10);
		Fade_->Reset();
	}
	Logo_ = CreateActor<TitleLogo>(5, "TitleLogo");
	TitleMenu_ = CreateActor<TitleMenu>(5, "TitleMenu");
	TitleBaba_ = CreateActor<TitleBaba>(4, "TitleBaba");
	TitleBaba::BabaTitleLocate_ = BabaLocation::Start_The_Game;
	{
		SettingMenu_ = CreateActor< PlayAndMainLevelMenu>(3);
		SettingMenu_->IntotheOption();
		SettingMenu_->Off();
		OptionOFF();
	}
}

void TitleLevel::KeyPushInOption()
{
	if (GameEngineInput::GetInst()->IsDown("Space") || GameEngineInput::GetInst()->IsDown("Enter"))
	{
		MainOption CurrentOption = SettingMenu_->GetCurrentMenuOption();
		switch (CurrentOption)
		{
		case MainOption::EnableGrid:
			if (GamePlayGobal::EnableGrid_ == true)
			{
				GamePlayGobal::EnableGrid_ = false;
			}
			else
			{
				GamePlayGobal::EnableGrid_ = true;
			}
			break;
		case MainOption::DisableParticleEffects:
			if (GamePlayGobal::DisableParticleEffects_ == true)
			{
				GamePlayGobal::DisableParticleEffects_ = false;
			}
			else
			{
				GamePlayGobal::DisableParticleEffects_ = true;
			}
			break;
		case MainOption::DisableScreenshake:
			if (GamePlayGobal::DisableScreenshake_ == true)
			{
				GamePlayGobal::DisableScreenshake_ = false;
			}
			else
			{
				GamePlayGobal::DisableScreenshake_ = true;
			}
			break;
		case MainOption::ReturnOption:
			OptionOFF();
			GameEngineSound::Update();
			GameEngineSound::SoundPlayOneShot("select.ogg");
			return;
			break;
		}
		GameEngineSound::Update();
		GameEngineSound::SoundPlayOneShot("select.ogg");
	}
	if (GameEngineInput::GetInst()->IsDown("Esc"))
	{
		OptionOFF();
	}
	SettingMenu_->KeyPush();
}

void TitleLevel::Update()
{
	if (Fade_->IsFadeOut() == true && Fade_->IsChangeScreen() == false)
	{
		GameEngine::GetInst().ChangeLevel("MainLevel");
		return;
	}
	if (Fade_->IsChangeScreen() == true)
	{
		return;
	}
	if (InOption_ == true)
	{
		KeyPushInOption();
		return;
	}

	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		if (TitleBaba::BabaTitleLocate_ == BabaLocation::Start_The_Game)
		{
			TitleBaba::BabaTitleLocate_ = BabaLocation::Exit_The_Game;
		}
		else if (TitleBaba::BabaTitleLocate_ == BabaLocation::Settings)
		{
			TitleBaba::BabaTitleLocate_ = BabaLocation::Start_The_Game;
		}
		else if (TitleBaba::BabaTitleLocate_ == BabaLocation::Exit_The_Game)
		{
			TitleBaba::BabaTitleLocate_ = BabaLocation::Settings;
		}
		else
		{
			MsgBoxAssert("BabaTitleLocate Error");
		}
		GameEngineSound::SoundPlayOneShot("select2.ogg");
	}
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{	
		if (TitleBaba::BabaTitleLocate_ == BabaLocation::Start_The_Game)
		{
			TitleBaba::BabaTitleLocate_ = BabaLocation::Settings;
		}
		else if (TitleBaba::BabaTitleLocate_ == BabaLocation::Settings)
		{
			TitleBaba::BabaTitleLocate_ = BabaLocation::Exit_The_Game;
		}
		else if (TitleBaba::BabaTitleLocate_ == BabaLocation::Exit_The_Game)
		{
			TitleBaba::BabaTitleLocate_ = BabaLocation::Start_The_Game;
		}
		else
		{
			MsgBoxAssert("BabaTitleLocate Error");
		}
		GameEngineSound::SoundPlayOneShot("select4.ogg");
	}

	if (GameEngineInput::GetInst()->IsDown("Space") || GameEngineInput::GetInst()->IsDown("Enter"))
	{
		switch (TitleBaba::BabaTitleLocate_)
		{
		case BabaLocation::Start_The_Game:
			Fade_->ShowFadeOut();
			BackGroundMusicControl_.Stop();
			GameEngineSound::SoundPlayOneShot("input.ogg");
			break;
		case BabaLocation::Settings:
			OptionON();
			GameEngineSound::SoundPlayOneShot("select.ogg");
			break;
		case BabaLocation::Exit_The_Game:
			GameEngineWindow::GetInst().Off();
			GameEngineSound::SoundPlayOneShot("input.ogg");
			break;
		default:
			MsgBoxAssert("BabaTitleLocate Error");
			break;
		}
	}


}

void TitleLevel::OptionON()
{
	InOption_ = true;
	Logo_->Off();
	TitleMenu_->Off();
	TitleBaba_->Off();
	SettingMenu_->On();
}

void TitleLevel::OptionOFF()
{
	InOption_ = false;
	Logo_->On();
	TitleMenu_->On();
	TitleBaba_->On();
	SettingMenu_->Off();
}

void TitleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	Fade_->Reset();
}