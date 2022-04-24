#include <GameEngineBase/GameEngineWindow.h>
#include "TitleBackGroundStage.h"
#include "GamePlayEnum.h"
#include <GameEngineBase/GameEngineTime.h>

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
	SetPosition(float4::ZERO);
	SetScale(float4(4752, 2592));


	//CreateRendererToScale("TitleStage.bmp", GetScale()); 
	CreateRenderer("TitleStage1.bmp", 1 , RenderPivot::LeftUp);
	MoveSpeed_ = float4((GetScale().x - GameEngineWindow::GetScale().x) * 0.1, (GetScale().y - GameEngineWindow::GetScale().y) * 0.1);
}

void TitleBackGroundStage::Update()	
{
	GetLevel()->MoveCameraPos(MoveSpeed_ * GameEngineTime::GetDeltaTime(0));
	float x = GetLevel()->GetCameraPos().x;
	float y = GetLevel()->GetCameraPos().y;
	float4 AA = GameEngineWindow::GetScale();
	float4 BB = GetScale();
	if (GetScale().x - GameEngineWindow::GetScale().x < GetLevel()->GetCameraPos().x || GetScale().y - GameEngineWindow::GetScale().y < GetLevel()->GetCameraPos().y)
	{
		GetLevel()->SetCameraPos(float4::ZERO);
	}
}

void TitleBackGroundStage::Render()
{
}