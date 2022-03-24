#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>

TitleBackGround::TitleBackGround() 
{
}

TitleBackGround::~TitleBackGround() 
{
}


void TitleBackGround::Start()
{
	// GetScale().Half() Áß¾Ó
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());
	
	CreateRenderer("BackGround.bmp");

}

void TitleBackGround::Update()
{

}

void TitleBackGround::Render()
{
}