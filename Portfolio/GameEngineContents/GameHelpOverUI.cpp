#include "GameHelpOverUI.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTime.h>
#include "EffectManager.h"
#include <math.h>
#include "PlayLevel.h"

GameHelpOverUI::GameHelpOverUI() 
	: CurrentWaitTime_(0.0f)
	, IsOver_(false)
	, Undo_(nullptr)
	, Restart_(nullptr)
	, KeyZ_(nullptr)
	, KeyR_(nullptr)
	, KeyR_Alpha_(nullptr)
	, KeyZ_Alpha_(nullptr)
	, CurrentInterTime_(ImageSpeed)
	, CurrentFrame_(0)
	, EndFrame_(2)
	, CurrentUndoImgPivot_(float4::ZERO)
	, CurrentResetImgPivot_(float4::ZERO)
	, CurrentResetImgScale_(float4::ZERO)
	, CurrentUndoImgScale_(float4::ZERO)
	, Angle_(0.02f)
	, AngleIndex_(0.0f)
	, AngleValue_(1.0f)
	, Effect_(false)
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
		KeyR_Alpha_ = GameEngineImageManager::GetInst()->Find("Key_R_Alpha.bmp");
		KeyZ_Alpha_ = GameEngineImageManager::GetInst()->Find("Key_Z_Alpha.bmp");
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

			if (Effect_ == false)
			{
				static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x - 280 - 60, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20 ,25, -1.0f, 1.0f, 0.08f);
				static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x + 280 - 52, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20, 25, -1.0f, 1.0f, 0.08f);

				static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x - 280, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20, 25, -1.0f, 1.0f, 0.08f);
				static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x + 280, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20, 25, -1.0f, 1.0f, 0.08f);
				Effect_ = true;
			}
			AngleIndex_ += 0.008f;
			//AngleValue_ = -
			if (AngleIndex_ > GameEngineMath::PIE)
			{
				AngleValue_ = 0.0f;
			}
			{
				CurrentInterTime_ -= GameEngineTime::GetDeltaTime(0);
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
			Angle_ += sinf(AngleIndex_) * 30.0f * GameEngineTime::GetDeltaTime(0);
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
			GameEngine::BackBufferImage()->TransCopy(Restart_, { GameEngineWindow::GetScale().Half().x - 280, 30 }, {84, 48}, CurrentUndoImgPivot_, CurrentResetImgScale_, RGB(255, 0, 255));
			GameEngine::BackBufferImage()->TransCopy(Undo_, { GameEngineWindow::GetScale().Half().x + 280, 30 }, {96, 48}, CurrentResetImgPivot_, CurrentUndoImgScale_, RGB(255, 0, 255));
		}
		{
			GameEngine::BackBufferImage()->PlgCopy(KeyR_, { GameEngineWindow::GetScale().Half().x - 280 - 60, 30 }, { 48, 48 }, { 0, 0 }, { 48, 48 }, (342 + Angle_) > 360.0f ? (342 + Angle_) - 360.0f : (342 + Angle_), KeyR_Alpha_);
			GameEngine::BackBufferImage()->PlgCopy(KeyZ_, { GameEngineWindow::GetScale().Half().x + 280 - 52, 30 }, { 48, 48 }, { 0, 0 }, { 48, 48 }, (342 + Angle_) > 360.0f ? (342 + Angle_) - 360.0f : (342 + Angle_), KeyZ_Alpha_);

		}
	}
}

void GameHelpOverUI::SetOver()
{
	On();
	IsOver_ = true;
	Effect_ = false;
	CurrentWaitTime_ = 3.0f;
	CurrentInterTime_ = ImageSpeed;
	CurrentFrame_ = 0;
	EndFrame_ = 2;
	{
		Angle_ = 0.0f;
		AngleIndex_ = 0.0f;
		//AngleValue_ = 0.001f;
	}
}

void GameHelpOverUI::SetBack()
{
	static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x - 280 - 48, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20, 25, -1.0f, 1.0f, 0.08f);
	static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x + 280 - 40, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20, 25, -1.0f, 1.0f, 0.08f);
	static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x - 280, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20, 25, -1.0f, 1.0f, 0.08f);
	static_cast<PlayLevel*>(GetLevel())->GetEffectManager()->ShowRandomSprayEffect({ GameEngineWindow::GetScale().Half().x + 280, 40 }, GameEngineImageManager::GetInst()->Find("Ui_Effect_Sheet.bmp"), 20, 25, -1.0f, 1.0f, 0.08f);
	IsOver_ = false;
	Off();
}