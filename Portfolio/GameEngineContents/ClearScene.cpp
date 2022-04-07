#include "ClearScene.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngineRenderer.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngine.h>
#include "GamePlayEnum.h"

ClearScene::ClearScene()
	: MakeImage_(nullptr)
	, StayImage_(nullptr)
	, CurrentInterTime_(0.05f)
	, CurrentFrame_(0)
	, EndFrame_(26)
	, StayOn_(false)
{
}

ClearScene::~ClearScene()
{
}

// 이미지 재생이 끝났는지 안끝났는지 확인이 가능한 기능이 있으면 좋겠다
void ClearScene::Start()
{
	// GetScale().Half() 중앙
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());

	MakeImage_ = GameEngineImageManager::GetInst()->Find("Clear_make_sheet.bmp");
	StayImage_ = GameEngineImageManager::GetInst()->Find("Clear_Stay_sheet.bmp");
	Off();
	//RenderImg->CreateAnimation("Clear_make_sheet.bmp", "Clear", 0, 2, ImageSpeed, true);
	//RenderImg->ChangeAnimation("Clear");



}

void ClearScene::Update()
{
	if (IsUpdate() == true && StayOn_ != true)
	{
		CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime();
		if (0 >= CurrentInterTime_)
		{
			if (CurrentFrame_ < 10)
			{
				CurrentInterTime_ = 0.05f;
			}
			else
			{
				CurrentInterTime_ = 0.08f;
			}

			++CurrentFrame_;
			if (EndFrame_ < CurrentFrame_)
			{
				StayOn_ = true;
				CurrentFrame_ = 1;
				EndFrame_ = 2;
				CurrentInterTime_ = ImageSpeed;
			}
		}
		CurrentImgScale_ = MakeImage_->GetCutScale(CurrentFrame_);
		CurrentImgPivot_ = MakeImage_->GetCutPivot(CurrentFrame_);
	}
	if (StayOn_ == true)
	{
		CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime();
		if (0 >= CurrentInterTime_)
		{
			CurrentInterTime_ = ImageSpeed;
			++CurrentFrame_;
			if (EndFrame_ < CurrentFrame_)
			{
				CurrentFrame_ = 0;
			}
		}
		CurrentImgScale_ = StayImage_->GetCutScale(CurrentFrame_);
		CurrentImgPivot_ = StayImage_->GetCutPivot(CurrentFrame_);
	}

}

void ClearScene::Render()
{
	if (StayOn_ != true)
	{
		GameEngine::BackBufferImage()->TransCopy(MakeImage_, GetPosition() - CurrentImgScale_.Half(), CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));
	}
	else
	{
		GameEngine::BackBufferImage()->TransCopy(StayImage_, GetPosition() - CurrentImgScale_.Half(), CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));
	}
}