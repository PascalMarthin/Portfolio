#include "TitleLogo.h"
#include <Windows.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>

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

	//CreateRenderer("TitleLogo_1.bmp", RenderPivot::CENTER, { 0,-250 });

	GameEngineRenderer* RenderImg = CreateRenderer(RenderPivot::CENTER, { 0,-150 });
	RenderImg->CreateAnimation("TitleLogo_sheet.bmp", "Title_Logo", 0, 2, 0.17f, true);
	RenderImg->ChangeAnimation("Title_Logo");
}

void TitleLogo::Update()
{

}

void TitleLogo::Render()
{
	//DebugRectRender();
}