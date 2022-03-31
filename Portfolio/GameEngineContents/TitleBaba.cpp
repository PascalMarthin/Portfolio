#include "TitleBaba.h"
#include <GameEngine/GameEngineRenderer.h>
#include "GamePlayEnum.h"
#include <GameEngine/GameEngineImageManager.h>
#include <GameEngineBase/GameEngineWindow.h>
#include "TitleLevel.h"

BabaLocation TitleBaba::BabaTitleLocate_ = BabaLocation::Baba;

TitleBaba::TitleBaba() 
	: BabaPos_(-330, 100)
	, BabaImgSheet_(nullptr)
	, BabaImg_(nullptr)
	, Render_(nullptr)
{
}

TitleBaba::~TitleBaba() 
{
}

void TitleBaba::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	BabaImgSheet_ = GameEngineImageManager::GetInst()->Find("unit_baba_right_Sheet.bmp");

	Render_ = CreateRenderer(RenderPivot::CENTER, BabaPos_);
	Render_->CreateAnimation("unit_baba_right_Sheet.bmp", "Baba", 0, 2, 0.17f, true);
	Render_->ChangeAnimation("Baba");
}

void TitleBaba::Update()
{
	switch (BabaTitleLocate_)
	{
	case BabaLocation::Start_The_Game :
		BabaPos_ = { -330, 100 };
		break;
	case BabaLocation::Settings :
		BabaPos_ = { -330, 190 };
		break;
	case BabaLocation::Exit_The_Game :
		BabaPos_ = { -330, 280 };
		break;
	default:
		break;
	}
	Render_->SetPivot(BabaPos_);
}

void TitleBaba::Render()
{
}