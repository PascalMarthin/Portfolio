#include "Coordinate.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>

Coordinate::Coordinate() 
	: ObjectImage_(nullptr)
	, Pos_({0, 0})
	, CPos_({ 0, 0 })
	, CurrentImgScale({0, 0})
	, CurrentImgPivot({0, 0})
	, Object_(ObjectName::Error)
	, CurrentFrame_(0)
	, StartFrame_(0)
	, EndFrame_(2)
	, CurrentInterTime_(0.1f)
{
}

Coordinate::~Coordinate() 
{
}

void Coordinate::Start()
{
	// 안만들어도 되나? SetPosition(GameEngineWindow::GetScale().Half());

}
void Coordinate::Update()
{
	FrameUpdate();
}

void Coordinate::Render()
{
	GameEngine::BackBufferImage()->TransCopy(ObjectImage_, CPos_, CurrentImgScale, CurrentImgPivot, CurrentImgScale, RGB(255, 0, 255));
}

void Coordinate::FrameUpdate()
{
	CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime();
	if (0 >= CurrentInterTime_)
	{
		CurrentInterTime_ = ImageSpeed;
		++CurrentFrame_;

		if (EndFrame_ < CurrentFrame_)
		{
			CurrentFrame_ = StartFrame_;
		}
	}

	if (ObjectImage_->IsCut() == false)
	{
		MsgBoxAssert("Coordinate에서 가져온 이미지가 잘못되어있습니다")
	}
	CurrentImgScale = ObjectImage_->GetCutPivot(CurrentFrame_);
	CurrentImgPivot = ObjectImage_->GetCutScale(CurrentFrame_);
}

void Coordinate::SetImg(GameEngineImage* _Img, Direction _Dir)
{
	ObjectImage_ = _Img;
	UnitDirection_ = _Dir;
}