#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "TitleLogo.h"
#include "BackGround.h"
#include "TitleMenu.h"
#include "GamePlayEnum.h"
#include "TitleBaba.h"



TitleLevel::TitleLevel() 
	: Fade_(nullptr)

{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	BackGroundMusicControl_ = GameEngineSound::SoundPlayControl("menu.ogg");
}

void TitleLevel::Loading()
{
	CreateActor<BackGround>(0);
	{
		Fade_ = CreateActor<Fade_InAndOut>(10);
		Fade_->Reset();
	}
	CreateActor<TitleLogo>(1, "TitleLogo");
	CreateActor<TitleMenu>(1, "TitleMenu");
	CreateActor<TitleBaba>(2, "TitleBaba");
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
			GameEngineSound::SoundPlayOneShot("select.ogg");
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
			GameEngineSound::SoundPlayOneShot("select.ogg");
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