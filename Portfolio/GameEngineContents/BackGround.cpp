#include "BackGround.h"
#include <GameEngineBase/GameEngineWindow.h>

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}


void BackGround::Start()
{
	// GetScale().Half() Áß¾Ó
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());

	CreateRenderer("BackGround1.bmp");

}

void BackGround::Update()
{

}

void BackGround::Render()
{
}