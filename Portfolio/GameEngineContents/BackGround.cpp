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
	// GetScale().Half() �߾�
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