#include "MainCursor.h"
#include <GameEngineBase/GameEngineWindow.h>

MainCursor::MainCursor()
{
}

MainCursor::~MainCursor()
{
}

void MainCursor::Start()
{
	//SetPosition(GameEngineWindow::GetScale().Half());
	//SetScale(GameEngineWindow::GetScale());

	CreateRenderer("cursor_0_1.bmp");
}

void MainCursor::Update()
{

}

void MainCursor::Render()
{

}
