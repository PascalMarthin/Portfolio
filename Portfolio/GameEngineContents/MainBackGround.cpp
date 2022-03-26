#include "MainBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GamePlayEnum.h"
#define MAX_FIXEL 48

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
	CreateRenderer("BackGround1.bmp");
	CreateRendererToScale("island_1.bmp", { (33 * MAX_FIXEL), (18 * MAX_FIXEL) });
	CreateRendererToScale("island_decor_1.bmp", { (33 * MAX_FIXEL), (18 * MAX_FIXEL) });
}

void MainBackGround::Update()
{

}

void MainBackGround::Render()
{

}

