#include "MainBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"

MainBackGround::MainBackGround()
{
}

MainBackGround::~MainBackGround()
{
}

void MainBackGround::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	//SetScale(GameEngineWindow::GetScale());

	{
		GameEngineRenderer* RenderImg = CreateRenderer();
		RenderImg->CreateAnimation("island_sheet.bmp", "MainBackGround", 0, 2, ImageSpeed, true);
		RenderImg->ChangeAnimation("MainBackGround");
		RenderImg->SetScale({ (33 * DotSize), (18 * DotSize) });
	}

	{
		GameEngineRenderer* RenderImg = CreateRenderer();
		RenderImg->CreateAnimation("island_decor_sheet.bmp", "MainBackGroundDecor", 0, 2, ImageSpeed, true);
		RenderImg->ChangeAnimation("MainBackGroundDecor");
		RenderImg->SetScale({ (33 * DotSize), (18 * DotSize) });
	}

}

void MainBackGround::Update()
{

}

void MainBackGround::Render()
{

}

