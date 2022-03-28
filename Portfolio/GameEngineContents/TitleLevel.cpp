#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleLogo.h"
#include "TitleBackGround.h"
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
	CreateActor<TitleBackGround>(0);
	CreateActor<TitleLogo>(1, "TitleLogo");
	CreateActor<TitleMenu>(1, "TitleMenu");
		
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

		case BabaLocation::Settings:

		case BabaLocation::Exit_The_Game:

		default:
			MsgBoxAssert("BabaTitleLocate Error");
			break;
		}
			

	}
}