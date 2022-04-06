#include "Coordinate.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include "Text.h"
#include "Dummy_Text.h"

Coordinate::Coordinate() 
	: CurrentPos_({0, 0})
	, CurrentLUPos_({ 0, 0 })
	, CurrentImgScale({0, 0})
	, CurrentImgPivot({0, 0})
	, UnitObject_(nullptr)
	, UnitDir_(Direction::Error)
	, CurrentFrame_(0)
	, StartFrame_(0)
	, EndFrame_(2)
	, CurrentInterTime_(0.1f)
	, IsActive_(false)
	, Type_(ObjectType::Error)
	, TextObject_(nullptr)
	, IsMove_(false)
	, CurrentInterTimebyMove_(0.05f)
	, PastByCurrentRange_(0)
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
	if (IsMove_ == true && IsDeath() != false)
	{
		CurrentInterTimebyMove_ -= GameEngineTime::GetInst()->GetDeltaTime();

		if (CurrentLUPos_ == PastLUPos_)
		{
			if (CurrentInterTime_ <= 0)
			{
				PastLUPos_ += (CurrentLUPos_ - PastLUPos_) * 0.25;
			}
		}

	}
	else
	{
		
	}
	FrameUpdate();
}

void Coordinate::Render()
{
	if (Type_ == ObjectType::Unit)
	{
		GameEngine::BackBufferImage()->TransCopy(UnitObject_->GetImage(), PastLUPos_, CurrentImgScale, CurrentImgPivot, CurrentImgScale, RGB(255, 0, 255));
	}
	else if (Type_ == ObjectType::Text)
	{
		GameEngine::BackBufferImage()->TransCopy(TextObject_->GetImage(), PastLUPos_, CurrentImgScale, CurrentImgPivot, CurrentImgScale, RGB(255, 0, 255));
	}
	
}

void Coordinate::FrameUpdate()
{
	if (UnitObject_ != nullptr)
	{
		GamePlayObject* Image = UnitObject_;
		if (UnitObject_->GetType() == ObjectType::Text)
		{
			Image = TextObject_;
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

		CurrentImgScale = Image->GetImage()->GetCutScale(CurrentFrame_);
		CurrentImgPivot = Image->GetImage()->GetCutPivot(CurrentFrame_);
	}
}


void Coordinate::SetValue(GamePlayObject* _Object, Direction _Dir, const float4& _Size)
{
	{
		if (_Object->GetType() == ObjectType::Text)
		{
			UnitObject_ = Text_Unit::GetInst();
			TextObject_ = static_cast<GamePlayText*>(_Object);
			Type_ = _Object->GetType();
		}
		else if (_Object->GetType() == ObjectType::Unit)
		{
			UnitObject_ = static_cast<GamePlayUnitObject*>(_Object);
			TextObject_ = Dummy_Text::GetInst();
			Type_ = _Object->GetType();
		}
		CurrentImgScale = _Size;
	}
	IsMove_ = false;
	IsActive_ = false;
	if (UnitDir_ == Direction::Error)
	{
		UnitDir_ = _Dir;
	}
}

void Coordinate::ChangePos(const float4& _Pos, const float4& _CPos)
{
	if (IsMove_ != true)
	{
		PastPos_ = CurrentPos_;
		PastLUPos_ = CurrentLUPos_;
		CurrentPos_ = _Pos;
		CurrentLUPos_ = _CPos;
		CurrentInterTimebyMove_ = 0.05f;
		IsMove_ = true;
	}
}