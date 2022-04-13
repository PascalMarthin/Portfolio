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

void TitleLevel::LevelChangeStart()
{

}

void TitleLevel::Loading()
{
	CreateActor<BackGround>(0);
	Fade_ = CreateActor<Fade_InAndOut>(10);
	CreateActor<TitleLogo>(1, "TitleLogo");
	CreateActor<TitleMenu>(1, "TitleMenu");
	CreateActor<TitleBaba>(2, "TitleBaba");
	TitleBaba::BabaTitleLocate_ = BabaLocation::Start_The_Game;
	Fade_->Off();
}

void TitleLevel::Update()
{
	if (Fade_->IsChangeScreen() == false)
	{
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

		}

		if (GameEngineInput::GetInst()->IsPress("Space") || GameEngineInput::GetInst()->IsPress("Enter"))
		{
			switch (TitleBaba::BabaTitleLocate_)
			{
			case BabaLocation::Start_The_Game:
				Fade_->ShowFadeOut();
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

	if (Fade_->IsChangeScreen() == false && Fade_->IsFadeOut() == true)
	{
		GameEngine::GetInst().ChangeLevel("MainLevel");
	}
	


}