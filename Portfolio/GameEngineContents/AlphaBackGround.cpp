#include "AlphaBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>

AlphaBackGround::AlphaBackGround() 
{
}

AlphaBackGround::~AlphaBackGround() 
{
}

void AlphaBackGround::Start()
{
	// GetScale().Half() Áß¾Ó
	//SetOrder(1);
	SetPosition(GameEngineWindow::GetScale().Half());
	
	GameEngineRenderer* Render = CreateRenderer("BackGround.bmp");
	Render->SetAlpha(100);
	Render->SetScale(float4(4752, 2592));
	Render->SetOrder(2);
}

void AlphaBackGround::Update()
{

}

void AlphaBackGround::Render()
{

}