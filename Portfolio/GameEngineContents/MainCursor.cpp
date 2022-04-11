#include "MainCursor.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include "GamePlayEnum.h"

MainCursor::MainCursor()
{
}

MainCursor::~MainCursor()
{
}

void MainCursor::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

	GameEngineRenderer* RenderImg = CreateRenderer(5, RenderPivot::CENTER);
	RenderImg->CreateAnimation("cursor_sheet.bmp", "Cursor", 0, 2, ImageSpeed, true);
	RenderImg->ChangeAnimation("Cursor");
}

void MainCursor::Update()
{

}

void MainCursor::Render()
{

}

