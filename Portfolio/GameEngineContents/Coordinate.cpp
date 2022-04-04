#include "Coordinate.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>

Coordinate::Coordinate() 
	: Pos_({0, 0})
	, LUPos_({ 0, 0 })
	, CurrentImgScale({0, 0})
	, CurrentImgPivot({0, 0})
	, Object_(nullptr)
	, UnitDir_(Direction::Error)
	, CurrentFrame_(0)
	, StartFrame_(0)
	, EndFrame_(2)
	, CurrentInterTime_(0.1f)
	, IsActive_(false)
	, PastActive_(false)
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
	if (Object_ != nullptr)
	{
		if (Object_->GetImage()->IsCut() == false)
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


		CurrentImgScale = Object_->GetImage()->GetCutScale(CurrentFrame_);
		CurrentImgPivot = Object_->GetImage()->GetCutPivot(CurrentFrame_);
	}
}

// 활성화시 true, 비활성화시 false
bool Coordinate::ApplyActive()
{
	if (Object_->GetType() != ObjectType::Text)
	{
		MsgBoxAssert("Text가 아닙니다");
	}
	if (PastActive_ != IsActive_)
	{
		if (IsActive_ == true)
		{
			StartFrame_ = 3;
			CurrentFrame_ = 3;
			EndFrame_ = 5;
			return true;
		}
		else if (IsActive_ == false)
		{
			StartFrame_ = 0;
			CurrentFrame_ = 0;
			EndFrame_ = 2;
			return true;
		}
	}

	return false;
}

void Coordinate::SetBaseValue(GamePlayObject* _Object, Direction _Dir, const float4& _Size)
{
	if (UnitDir_ == Direction::Error)
	{
		UnitDir_ = _Dir;
	}
	Object_ = _Object;
	CurrentImgScale = _Size;
}
