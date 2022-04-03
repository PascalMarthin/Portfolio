#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "TitleLogo.h"
#include "BackGround.h"
#include "TitleMenu.h"
#include "GamePlayEnum.h"
#include "TitleBaba.h"


TitleLevel::TitleLevel() 
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
	CreateActor<TitleLogo>(1, "TitleLogo");
	CreateActor<TitleMenu>(1, "TitleMenu");
	CreateActor<TitleBaba>(2, "TitleBaba");
	TitleBaba::BabaTitleLocate_ = BabaLocation::Start_The_Game;
}

void TitleLevel::Update()
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
			GameEngine::GetInst().ChangeLevel("MainLevel");
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