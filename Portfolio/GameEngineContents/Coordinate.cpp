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
	, PastByCurrentRange_(0)
	, IsKeyPush_(false)
	, CurrentImageIndex_(nullptr)
	, SceneFrame_(0)
{
}

Coordinate::~Coordinate() 
{
}

void Coordinate::Start()
{

}
void Coordinate::SetCurrentImage()
{
	if (Type_ == ObjectType::Unit)
	{
		CurrentImageIndex_ = UnitObject_->GetAnimationTake(UnitDir_);
	}
	else if (Type_ == ObjectType::Text)
	{
		if (IsActive_ == true)
		{
			CurrentImageIndex_ = TextObject_->GetAnimationTake(Direction::Up);
			
		}
		else if (IsActive_ == false)
		{
			CurrentImageIndex_ = TextObject_->GetAnimationTake(Direction::Down);
		}
		SceneFrame_ = 0;
		
	}
	// 지금 wall, water, lava는 이미지 정리중
	if (CurrentImageIndex_ == nullptr)
	{
		return;
	}
	StartFrame_ = (*CurrentImageIndex_)[SceneFrame_].first;
	EndFrame_ = (*CurrentImageIndex_)[SceneFrame_].second;
	CurrentFrame_ = (*CurrentImageIndex_)[SceneFrame_].first + (CurrentFrame_ % 3);
	++SceneFrame_;
	if ((*CurrentImageIndex_).size() <= SceneFrame_)
	{
		SceneFrame_ = 0;
	}
}

void Coordinate::Update()
{
	if (IsKeyPush_ == true)
	{
		if (UnitObject_->GetName() == ObjectName::Baba_Unit)
		{
			int a = 0;
		}
		SetCurrentImage();
		IsKeyPush_ = false;
	}
	if (IsDeath() == false)
	{
		if (IsMove_ == true)
		{
			if (PastByCurrentRange_ > 0)
			{
				switch (UnitDir_)
				{
				case Direction::Right:
					PastLUPos_.x += 8.0f;
					break;
				case Direction::Up:
					PastLUPos_.y -= 8.0f;
					break;
				case Direction::Left:
					PastLUPos_.x -= 8.0f;
					break;
				case Direction::Down:
					PastLUPos_.y += 8.0f;
					break;
				default:
					break;
				}
				PastByCurrentRange_ -= 8;
			}
			else
			{
				IsMove_ = false;
			}
		}
		else
		{
			FrameUpdate();
		}

	}
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

		CurrentImgScale_ = Image->GetImage()->GetCutScale(CurrentFrame_);
		CurrentImgPivot_ = Image->GetImage()->GetCutPivot(CurrentFrame_);
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
		CurrentImgScale_ = _Size;
	}
	IsMove_ = false;
	IsActive_ = false;
	if (UnitDir_ == Direction::Error)
	{
		UnitDir_ = _Dir;
	}
}

void Coordinate::ChangePos(const float4& _Pos, const float4& _CPos, Direction _Dir)
{
	if (IsMove_ != true)
	{
		PastPos_ = CurrentPos_;
		PastLUPos_ = CurrentLUPos_;
		CurrentPos_ = _Pos;
		CurrentLUPos_ = _CPos;
		PastByCurrentRange_ = DotSizeX;
		UnitDir_ = _Dir;
		//SceneFrame_ = 0;
		IsMove_ = true;
	}
}