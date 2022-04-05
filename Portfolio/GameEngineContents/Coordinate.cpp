#include "Coordinate.h"
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineWindow.h>
#include "Text.h"

Coordinate::Coordinate() 
	: Pos_({0, 0})
	, LUPos_({ 0, 0 })
	, CurrentImgScale({0, 0})
	, CurrentImgPivot({0, 0})
	, UnitObject_(nullptr)
	, UnitDir_(Direction::Error)
	, CurrentFrame_(0)
	, StartFrame_(0)
	, EndFrame_(2)
	, CurrentInterTime_(0.1f)
	, IsActive_(false)
	, PastActive_(false)
	, Type_(ObjectType::Error)
	, TextObject_(nullptr)
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
	if (Type_ == ObjectType::Unit)
	{
		GameEngine::BackBufferImage()->TransCopy(UnitObject_->GetImage(), LUPos_, CurrentImgScale, CurrentImgPivot, CurrentImgScale, RGB(255, 0, 255));
	}
	else if (Type_ == ObjectType::Text)
	{
		GameEngine::BackBufferImage()->TransCopy(TextObject_->GetImage(), LUPos_, CurrentImgScale, CurrentImgPivot, CurrentImgScale, RGB(255, 0, 255));
	}
	
}

void Coordinate::FrameUpdate()
{
	if (UnitObject_ != nullptr)
	{
		GamePlayObject* Object = UnitObject_;
		if (Type_ == ObjectType::Text)
		{
			Object = TextObject_;
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


		CurrentImgScale = Object->GetImage()->GetCutScale(CurrentFrame_);
		CurrentImgPivot = Object->GetImage()->GetCutPivot(CurrentFrame_);
	}
}


void Coordinate::SetBaseValue(GamePlayObject* _Object, ObjectType _Type, Direction _Dir, const float4& _Size)
{
	{
		if (_Type == ObjectType::Text)
		{
			UnitObject_ = Text_Unit::GetInst();
			TextObject_ = static_cast<GamePlayText*>(_Object);
			Type_ = _Type;
		}
		else if (_Type == ObjectType::Unit)
		{
			UnitObject_ = static_cast<GamePlayUnitObject*>(_Object);
			TextObject_ = nullptr;
			Type_ = _Type;
		}
		CurrentImgScale = _Size;
	}

	if (UnitDir_ == Direction::Error)
	{
		UnitDir_ = _Dir;
	}
}
