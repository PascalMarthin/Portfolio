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
	// GetScale().Half() �߾�
	SetPosition(float4::ZERO);
	SetScale(float4(4752, 2592));

	CreateRenderer("TitleStage1.bmp", 1 , RenderPivot::LeftUp);
	MoveSpeed_ = float4((GetScale().x - GameEngineWindow::GetScale().x) * 0.03f, (GetScale().y - GameEngineWindow::GetScale().y) * 0.03f);
}

void TitleBackGroundStage::Update()	
{
	GetLevel()->MoveCameraPos(MoveSpeed_ * GameEngineTime::GetDeltaTime(0));
	if (1584.0f < GetLevel()->GetCameraPos().x && 864.0f < GetLevel()->GetCameraPos().y)
	{
		GetLevel()->SetCameraPos(float4(GetLevel()->GetCameraPos().x - 1584, GetLevel()->GetCameraPos().y - 864));
	}
}

void TitleBackGroundStage::Render()
{
}