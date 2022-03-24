#include "MainBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>

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

	CreateRendererToScale("island_1.bmp", {1920, 1080});
	CreateRendererToScale("island_decor_1.bmp", { 1920, 1080 });
}

void MainBackGround::Update()
{

}

void MainBackGround::Render()
{

}

