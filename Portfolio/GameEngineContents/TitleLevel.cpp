#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleLogo.h"
#include "TitleBackGround.h"
#include "TitleMenu.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}


void TitleLevel::Loading()
{
	CreateActor<TitleBackGround>("BackGround", 0);
	CreateActor<TitleLogo>("TitleLogo", 1);
	CreateActor<TitleMenu>("TitleMenu", 1);
		
}

void TitleLevel::Update()
{

}