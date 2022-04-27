#include "BackGround.h"
#include <GameEngineBase/GameEngineWindow.h>

BackGround::BackGround()
	: Image_(nullptr)
	, ActorRender_(false)
{
}

BackGround::~BackGround()
{
}


void BackGround::Start()
{
	// GetScale().Half() Áß¾Ó
	SetOrder(0);
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());
	CreateRenderer("BackGround1.bmp");
	Image_ = GameEngineImageManager::GetInst()->Find("BackGround1.bmp");
}

void BackGround::Update()
{

}

void BackGround::Render()
{
	if (ActorRender_ == true)
	{
		GameEngine::BackBufferImage()->TransCopy(Image_, float4::ZERO, GameEngineWindow::GetScale(), float4::ZERO, Image_->GetScale(), RGB(255, 0, 255));
	}
}