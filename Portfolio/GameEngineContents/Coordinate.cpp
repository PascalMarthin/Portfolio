#include "Coordinate.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>

Coordinate::Coordinate() 
	: Pos_({0, 0})
	, LUPos_({ 0, 0 })
	, CurrentImgScale({0, 0})
	, CurrentImgPivot({0, 0})
	, Object_(nullptr)
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

}
void Coordinate::Update()
{
	FrameUpdate();
}

void Coordinate::Render()
{
	GameEngine::BackBufferImage()->TransCopy(Object_->GetImage(), LUPos_, CurrentImgScale, CurrentImgPivot, CurrentImgScale, RGB(255, 0, 255));
}

void Coordinate::FrameUpdate()
{
	if (Object_->GetImage()->IsCut() == false)
	{
		MsgBoxAssert("Coordinate ¸øÀÚ¸§");
	}

	if (Object_)
	{

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


	CurrentImgScale = Object_->GetImage()->GetCutScale(CurrentFrame_);
	CurrentImgPivot = Object_->GetImage()->GetCutPivot(CurrentFrame_);
}

void Coordinate::SetBaseValue(GamePlayObject* _Object, Direction _Dir, const float4& _Size)
{
	Object_ = _Object;
	UnitDirection_ = _Dir;
	CurrentImgScale = _Size;
}
