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
	//SetScale({ 10, 100 });

	CreateRenderer("TitleLogo_1.bmp", RenderPivot::CENTER, { 0,-250 });
}

void TitleLogo::Update()
{

}

void TitleLogo::Render()
{
	//DebugRectRender();
}