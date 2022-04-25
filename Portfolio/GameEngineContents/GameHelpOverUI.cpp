#include "GameHelpOverUI.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTime.h>
#include "EffectManager.h"

GameHelpOverUI::GameHelpOverUI() 
	: CurrentInterTime_(0.0f)
	, IsOver_(false)
	, Undo_(nullptr)
	, Reset_(nullptr)
	, KeyZ_(nullptr)
	, KeyR_(nullptr)
{
}

GameHelpOverUI::~GameHelpOverUI() 
{
}

void GameHelpOverUI::Start()
{
	float4 Scale = GameEngineWindow::GetScale().Half();
	Scale.y = 0.0f;
	SetPosition(Scale);

	{
		Reset_ = CreateRenderer(1, RenderPivot::Up, { -200, 20 });
		Reset_->CreateAnimation("button_restart_sheet.bmp", "button_restart_sheet", 0, 2, ImageSpeed, true);
		Reset_->ChangeAnimation("button_restart_sheet");
	}
	{
		KeyR_ = CreateRenderer("Key_R.bmp", 1, RenderPivot::Up, {-240, 20});
	}
	{
		Undo_ = CreateRenderer(1, RenderPivot::Up, { 200, 20 });
		Undo_->CreateAnimation("button_undo_sheet.bmp", "button_undo_sheet", 0, 2, ImageSpeed, true);
		Undo_->ChangeAnimation("button_undo_sheet");
	}
	{
		KeyZ_ = CreateRenderer("Key_Z.bmp", 1, RenderPivot::Up, {160, 20});
	}

	SetBack();

}
void GameHelpOverUI::Update()
{
	if (IsOver_ == true)
	{
		CurrentInterTime_ -= GameEngineTime::GetDeltaTime(0);
		if (CurrentInterTime_ < 0)
		{
			Reset_->On();
			Undo_->On();
			KeyZ_->On();
			KeyR_->On();
		}

	}
}

void GameHelpOverUI::Render()
{
}

void GameHelpOverUI::SetOver()
{
	On();
	IsOver_ = true;
	CurrentInterTime_ = 3.0f;
}

void GameHelpOverUI::SetBack()
{
	IsOver_ = false;
	KeyZ_->Off();
	KeyR_->Off();
	Reset_->Off();
	Undo_->Off();
	Off();
}