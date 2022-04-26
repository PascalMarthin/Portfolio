#include "GameHelpOverUI.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTime.h>
#include "EffectManager.h"

GameHelpOverUI::GameHelpOverUI() 
	: CurrentWaitTime_(0.0f)
	, IsOver_(false)
	, Undo_(nullptr)
	, Restart_(nullptr)
	, KeyZ_(nullptr)
	, KeyR_(nullptr)
	, CurrentInterTime_(ImageSpeed)
	, CurrentFrame_(0)
	, EndFrame_(2)
	, CurrentUndoImgPivot_(float4::ZERO)
	, CurrentResetImgPivot_(float4::ZERO)
	, CurrentResetImgScale_(float4::ZERO)
	, CurrentUndoImgScale_(float4::ZERO)
{
}

GameHelpOverUI::~GameHelpOverUI() 
{
}

void GameHelpOverUI::Start()
{
	float4 Scale = GameEngineWindow::GetScale().Half();
	Scale.y = 100.0f;
	SetPosition(Scale);
	SetScale({100, 100});
	GameEngineActor::SetOrder(7);

	{
		Restart_ = GameEngineImageManager::GetInst()->Find("button_restart_sheet.bmp");
		KeyR_ = GameEngineImageManager::GetInst()->Find("Key_R.bmp"); // CreateRenderer(".bmp", 1, RenderPivot::Up, {-280, 20});
		Undo_ = GameEngineImageManager::GetInst()->Find("button_undo_sheet.bmp");
		//Undo_ = CreateRenderer(1, RenderPivot::Up, { 200, 20 });
		KeyZ_ = GameEngineImageManager::GetInst()->Find("Key_Z.bmp");  //KeyZ_ = CreateRenderer("Key_Z.bmp", 1, RenderPivot::Up, {160, 20});
	}

	SetBack();

}
void GameHelpOverUI::Update()
{
	if (IsOver_ == true)
	{
		if (CurrentWaitTime_ < 0)
		{
			CurrentInterTime_-= GameEngineTime::GetDeltaTime(0);
			if (CurrentInterTime_ < 0)
			{
				CurrentInterTime_ = ImageSpeed;
				++CurrentFrame_;
				if (CurrentFrame_ > EndFrame_)
				{
					CurrentFrame_ = 0;
				}
			}
			CurrentUndoImgScale_ = Undo_->GetCutScale(CurrentFrame_);
			CurrentUndoImgPivot_ = Undo_->GetCutPivot(CurrentFrame_);

			CurrentResetImgScale_ = Restart_->GetCutScale(CurrentFrame_);
			CurrentResetImgPivot_ = Restart_->GetCutPivot(CurrentFrame_);
		}
		else
		{
			CurrentWaitTime_ -= GameEngineTime::GetDeltaTime(0);
		}
	}
}

void GameHelpOverUI::Render()
{
	if (IsOver_ == true && CurrentWaitTime_ < 0)
	{
		{
			//DebugRectRender();
			//GameEngine::BackBufferImage()->TransCopy(Restart_, { GameEngineWindow::GetScale().Half().x - 280, 20 }, {84, 48}, CurrentUndoImgPivot_, CurrentResetImgScale_, RGB(255, 0, 255));
			//GameEngine::BackBufferImage()->TransCopy(Undo_, { GameEngineWindow::GetScale().Half().x - 120, 20 }, {96, 48}, CurrentResetImgPivot_, CurrentUndoImgScale_, RGB(255, 0, 255));
		}
		{
			GameEngine::BackBufferImage()->PlgCopy(KeyR_, { GameEngineWindow::GetScale().Half().x - 280, 20 }, { 48, 48 }, CurrentUndoImgPivot_, CurrentResetImgScale_, 230.0f, KeyR_);
		}
	}
}

void GameHelpOverUI::SetOver()
{
	On();
	IsOver_ = true;
	CurrentWaitTime_ = 3.0f;
	CurrentInterTime_ = ImageSpeed;
	CurrentFrame_ = 0;
	EndFrame_ = 2;
}

void GameHelpOverUI::SetBack()
{
	IsOver_ = false;
	Off();
}