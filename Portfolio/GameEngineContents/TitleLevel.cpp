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


TitleLevel::TitleLevel() 
	: Fade_(nullptr)

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
	CreateActor<TitleLogo>(5, "TitleLogo");
	CreateActor<TitleMenu>(5, "TitleMenu");
	CreateActor<TitleBaba>(4, "TitleBaba");
	TitleBaba::BabaTitleLocate_ = BabaLocation::Start_The_Game;
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

		if (GameEngineInput::GetInst()->IsPress("Space") || GameEngineInput::GetInst()->IsPress("Enter"))
		{
			switch (TitleBaba::BabaTitleLocate_)
			{
			case BabaLocation::Start_The_Game:
				Fade_->ShowFadeOut();
				BackGroundMusicControl_.Stop();
				GameEngineSound::SoundPlayOneShot("input.ogg");
				break;
			case BabaLocation::Settings:




				break;
			case BabaLocation::Exit_The_Game:
				GameEngineWindow::GetInst().Off();
				break;
			default:
				MsgBoxAssert("BabaTitleLocate Error");
				break;
			}
		}



}

void TitleLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
	Fade_->Reset();
}