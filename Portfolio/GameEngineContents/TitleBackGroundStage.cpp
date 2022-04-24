#include <GameEngineBase/GameEngineWindow.h>
#include "TitleBackGroundStage.h"
#include "GamePlayEnum.h"

TitleBackGroundStage::TitleBackGroundStage()
	: MoveSpeed_({ 2.0f,  2.0f })
{
}

TitleBackGroundStage::~TitleBackGroundStage() 
{
}

void TitleBackGroundStage::Start()
{
	// GetScale().Half() Áß¾Ó
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());

	CreateRendererToScale("TitleStage.bmp", float4(4752, 2592));
}

void TitleBackGroundStage::Update()	
{
	GetLevel()->MoveCameraPos(MoveSpeed_);
	//float AA = GetScale().x - GameEngineWindow::GetScale().x;
	//float BB = GetLevel()->GetCameraPos().x;
	//if ()
	//{
	//	GetLevel()->SetCameraPos(float4::ZERO);
	//}
}

void TitleBackGroundStage::Render()
{
}