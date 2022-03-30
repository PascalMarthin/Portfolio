#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleLogo.h"
#include "BackGround.h"
#include "TitleMenu.h"
#include "GamePlayEnum.h"


TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}


void TitleLevel::Loading()
{
	CreateActor<BackGround>(0);
	CreateActor<TitleLogo>(1, "TitleLogo");
	//CreateActor<TitleMenu>(1, "TitleMenu");
		
}

void TitleLevel::Update()
{
	if (GameEngineInput::GetInst()->IsDown("Up"))
	{
		if (TitleMenu::BabaTitleLocate == BabaLocation::Start_the_Game)
		{
			TitleMenu::BabaTitleLocate = BabaLocation::Exit_The_Game;
		}
		else if (TitleMenu::BabaTitleLocate == BabaLocation::Settings)
		{
			TitleMenu::BabaTitleLocate = BabaLocation::Start_the_Game;
		}
		else if (TitleMenu::BabaTitleLocate == BabaLocation::Exit_The_Game)
		{
			TitleMenu::BabaTitleLocate = BabaLocation::Settings;
		}
		else
		{
			MsgBoxAssert("BabaTitleLocate Error");
		}

	}
	if (GameEngineInput::GetInst()->IsDown("Down"))
	{
		if (TitleMenu::BabaTitleLocate == BabaLocation::Start_the_Game)
		{
			TitleMenu::BabaTitleLocate = BabaLocation::Settings;
		}
		else if (TitleMenu::BabaTitleLocate == BabaLocation::Settings)
		{
			TitleMenu::BabaTitleLocate = BabaLocation::Exit_The_Game;
		}
		else if (TitleMenu::BabaTitleLocate == BabaLocation::Exit_The_Game)
		{
			TitleMenu::BabaTitleLocate = BabaLocation::Start_the_Game;
		}
		else
		{
			MsgBoxAssert("BabaTitleLocate Error");
		}

	}

	if (GameEngineInput::GetInst()->IsPress("Space") || GameEngineInput::GetInst()->IsPress("Enter"))
	{
		switch (TitleMenu::BabaTitleLocate)
		{
		case BabaLocation::Start_the_Game:
			GameEngine::GlobalEngine().ChangeLevel("MainLevel");
			break;
		case BabaLocation::Settings:




			break;
		case BabaLocation::Exit_The_Game:




			break;
		default:
			MsgBoxAssert("BabaTitleLocate Error");
			break;
		}
			

	}
}