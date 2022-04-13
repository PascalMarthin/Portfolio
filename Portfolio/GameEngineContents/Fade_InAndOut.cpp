#include "Fade_InAndOut.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineTime.h>
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngine/GameEngine.h>
#define AnimationSpeed 0.03f

Fade_InAndOut::Fade_InAndOut()
	: CurrentFrame_(0)
	, EndFrame_(21)
	, CurrentInterTime_(AnimationSpeed)
	, FadeIn_(false)
	, FadeOut_(false)
	, FadeImage_(nullptr)
	, ImageScale_(float4::ZERO)
	, ChangeScreen_(false)
	, WattingTime_(1.0f)
{
}

Fade_InAndOut::~Fade_InAndOut()
{
}


void Fade_InAndOut::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale(GameEngineWindow::GetScale());
	GameEngineActor::SetOrder(10);

	FadeImage_ = GameEngineImageManager::GetInst()->FolderImageFind("Fade");
	ImageScale_ = FadeImage_->GetImage(CurrentFrame_)->GetScale();

}

void Fade_InAndOut::Reset()
{
	FadeOut_ = false;
	FadeIn_ = false;
	ChangeScreen_ = false;
	Off();
}

void Fade_InAndOut::ShowFadeIn()
{
	On();
	FadeIn_ = true;
	FadeOut_ = false;
	CurrentInterTime_ = AnimationSpeed;
	WattingTime_ = 0.3f;
	ChangeScreen_ = true;
	CurrentFrame_ = 21;
	EndFrame_ = 0;
}
void Fade_InAndOut::ShowFadeOut()
{
	On();
	FadeIn_ = false;
	FadeOut_ = true;
	CurrentInterTime_ = AnimationSpeed;
	WattingTime_ = 1.0f;
	ChangeScreen_ = true;
	CurrentFrame_ = 0;
	EndFrame_ = 21;
}

void Fade_InAndOut::Update()
{
	if (FadeOut_ == true)
	{
		CurrentInterTime_ -= GameEngineTime::GetDeltaTime();
		if (CurrentInterTime_ < 0)
		{
			CurrentInterTime_ = AnimationSpeed;
			++CurrentFrame_;
			if (EndFrame_ < CurrentFrame_)
			{
				CurrentFrame_ = EndFrame_;
			}
		}
		else if (EndFrame_ == CurrentFrame_)
		{
			WattingTime_ -= GameEngineTime::GetDeltaTime();
			if (WattingTime_ < 0)
			{
				ChangeScreen_ = false;
			}
		}
	}
	else if (FadeIn_ == true)
	{
		if (WattingTime_ < 0)
		{
			CurrentInterTime_ -= GameEngineTime::GetDeltaTime();
			if (CurrentInterTime_ < 0)
			{
				CurrentInterTime_ = AnimationSpeed;
				--CurrentFrame_;
				if (0 > CurrentFrame_)
				{
					FadeIn_ = false;
					ChangeScreen_ = false;
					Off();
				}
			}
		}
		else
		{
			WattingTime_ -= GameEngineTime::GetDeltaTime();
		}
	}
}

void Fade_InAndOut::Render()
{
	if (FadeIn_ == true || FadeOut_ == true)
	{
		GameEngine::BackBufferImage()->TransCopy(FadeImage_->GetImage(CurrentFrame_), GetPosition() - GetScale().Half(), GetScale(), {0, 0}, ImageScale_, RGB(255, 0, 255));
	}
	
}