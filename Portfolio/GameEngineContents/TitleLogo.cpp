#include "TitleLogo.h"
#include <Windows.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>

TitleLogo::TitleLogo()
{
}

TitleLogo::~TitleLogo()
{
}



void TitleLogo::Start()
{
	// GameEngineWindow::GetScale().Half() È­¸é Áß¾Ó
	SetPosition(GameEngineWindow::GetScale().Half());
	//CreateRenderer("Idle.bmp");
	SetScale({ 200, 500 });
}

void TitleLogo::Render()
{
	DebugRectRender();
}