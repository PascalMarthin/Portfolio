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
	, UnitDirection_(Direction::Error)
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
	if (ObjectImage_->IsCut() == false)
	{
		MsgBoxAssert("Coordinate 못자름");
	}
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


	CurrentImgScale = ObjectImage_->GetCutScale(CurrentFrame_);
	CurrentImgPivot = ObjectImage_->GetCutPivot(CurrentFrame_);
}

void Coordinate::SetImg(GameEngineImage* _Img, Direction _Dir, const float4& _Size)
{
	ObjectImage_ = _Img;
	UnitDirection_ = _Dir;
	CurrentImgScale = _Size;
}