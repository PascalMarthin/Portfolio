#include "TitleLogo.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include "GamePlayEnum.h"

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
	
	GameEngineRenderer* RenderImg = CreateRenderer( 1, RenderPivot::CENTER, {0,-150});
	RenderImg->CreateAnimation("TitleLogo_sheet.bmp", "Title_Logo", 0, 2, ImageSpeed, true);
	RenderImg->ChangeAnimation("Title_Logo");
	RenderImg->CameraEffectOff();
}

void TitleLogo::Update()
{

}

void TitleLogo::Render()
{
	//DebugRectRender();
}