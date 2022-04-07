#include "ClearScene.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include "GamePlayEnum.h"

ClearScene::ClearScene()
{
}

ClearScene::~ClearScene()
{
}


void ClearScene::Start()
{
	// GetScale().Half() Áß¾Ó
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());

	//{
	//	GameEngineRenderer* RenderImg = CreateRenderer(1, RenderPivot::CENTER, { 0,0 });
	//	RenderImg->CreateAnimation("Clear_make_sheet.bmp", "Clear", 0, 2, ImageSpeed, true);
	//}

	//RenderImg->CreateAnimation("Clear_make_sheet.bmp", "Clear", 0, 2, ImageSpeed, true);
	//RenderImg->ChangeAnimation("Clear");
	Off();


}

void ClearScene::Update()
{

}

void ClearScene::Render()
{
}