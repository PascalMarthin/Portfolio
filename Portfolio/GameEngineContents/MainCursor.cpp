#include "MainCursor.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineRenderer.h>
#include "GamePlayEnum.h"
#include <GameEngine/GameEngine.h>
#include <GameEngine/GameEngineImageManager.h>

MainCursor::MainCursor()
	: CurrentInterTime_(ImageSpeed)
	, CurrentFrame_(0)
	, Image_(nullptr)
{
}

MainCursor::~MainCursor()
{
}

void MainCursor::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());

	Image_ = GameEngineImageManager::GetInst()->Find("cursor_sheet.bmp");
}

void MainCursor::Update()
{
	CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime(0);
	if (0 >= CurrentInterTime_)
	{
		CurrentInterTime_ = ImageSpeed;
		++CurrentFrame_;
		if (2 < CurrentFrame_)
		{
			CurrentFrame_ = 0;
		}
	}
	CurrentImgScale_ = Image_->GetCutScale(CurrentFrame_);
	CurrentImgPivot_ = Image_->GetCutPivot(CurrentFrame_);
}

void MainCursor::Render()
{
	GameEngine::BackBufferImage()->TransCopy(Image_, GetPosition() - CurrentImgScale_.Half(), CurrentImgScale_, CurrentImgPivot_, CurrentImgScale_, RGB(255, 0, 255));
}

