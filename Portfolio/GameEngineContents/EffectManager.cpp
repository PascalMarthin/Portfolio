#include "EffectManager.h"
#include <math.h>

EffectManager::EffectManager() 
	: Random_(nullptr)
{
	Random_ = new GameEngineRandom();
}


EffectManager::~EffectManager() 
{
	if (QueueEffect_.empty() == false)
	{
		std::list<QueueEffect*>::iterator StartIter = QueueEffect_.begin();
		std::list<QueueEffect*>::iterator EndIter = QueueEffect_.end();
		while (StartIter != EndIter)
		{
			delete (*StartIter);
			(*StartIter) = nullptr;
			++StartIter;
		}
	}
	if (Random_ != nullptr)
	{
		delete Random_;
		Random_ = nullptr;
	}
}

bool EffectManager::ShowStatEffect(const float4& _LUPos, GameEngineImage* _EffectImage, int _Min, int _Max)
{
	if (_Min > _Max)
	{
		int idx = _Max;
		_Max = _Min;
		_Min = idx;
	}
	//int RandomInt = Random_->RandomInt(_Min, _Max);
	int RandomInt = 0;
	if (RandomInt == Random_->RandomInt(_Min, _Max))
	{
		float4 Center(_LUPos.x + 10.0f, _LUPos.y + 10.0f);
		QueueEffect* Group = new QueueEffect(Center, _EffectImage, static_cast<int>(_EffectImage->GetCutCount() - 1), 0.1f);
		float x = Random_->RandomFloat(Center.x - static_cast<float>(DotSizeX / 2), Center.x + static_cast<float>(DotSizeX / 2));
		float y = Random_->RandomFloat(Center.y - static_cast<float>(DotSizeY / 2), Center.y + static_cast<float>(DotSizeY / 2));
		while ((Center.x - static_cast<float>(DotSizeX / 4) < x && x < Center.x + static_cast<float>(DotSizeX / 4)))
		{
			x = Random_->RandomFloat(Center.x - static_cast<float>(DotSizeX / 2), Center.x + static_cast<float>(DotSizeX / 2));
		}
		while ((Center.y - static_cast<float>(DotSizeY / 4) < y && y < Center.y + static_cast<float>(DotSizeY / 4)))
		{
			y = Random_->RandomFloat(Center.y - static_cast<float>(DotSizeY / 2), Center.y + static_cast<float>(DotSizeY / 2));
		}
		Group->PosList_.push_back({ x, y });
		QueueEffect_.push_back(Group);
		return true;
	}
	return false;
}

void EffectManager::ShowRandomEffect(const float4& _LUPos, GameEngineImage* _EffectImage, int _Min, int _Max, float _InterTime)
{	
	if (_Min > _Max)
	{
		int idx = _Max;
		_Max = _Min;
		_Min = idx;
	}
	
	if (_EffectImage->GetNameConstRef() == "CLEAR_EFFECT_SHEET.BMP")
	{

		int Index = Random_->RandomInt(_Min, _Max);
		for (int i = 0; i < Index; i++)
		{
			float RandomInterTime = Random_->RandomFloat(_InterTime - _InterTime / 4, _InterTime + _InterTime / 2);
			float Speed = Random_->RandomFloat(4.0f, 6.0f);
			QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, static_cast<int>(_EffectImage->GetCutCount() - 1), RandomInterTime);
			Group->WinEffect_ = true;
			Group->Speed_ = Speed;
			float x = Random_->RandomFloat(_LUPos.x - static_cast<float>(DotSizeX / 2), _LUPos.x + static_cast<float>(DotSizeX / 2));
			float y = Random_->RandomFloat(_LUPos.y - static_cast<float>(DotSizeY / 2), _LUPos.y + static_cast<float>(DotSizeY / 2));
			Group->PosList_.push_back({ x, y });
			QueueEffect_.push_back(Group);
		}

	}
	else
	{
		QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, static_cast<int>(_EffectImage->GetCutCount() - 1), _InterTime);
		int Index = Random_->RandomInt(_Min, _Max);
		for (int i = 0; i < Index; i++)
		{
			float x = Random_->RandomFloat(_LUPos.x - static_cast<float>(DotSizeX / 2), _LUPos.x + static_cast<float>(DotSizeX / 2));
			float y = Random_->RandomFloat(_LUPos.y - static_cast<float>(DotSizeY / 2), _LUPos.y + static_cast<float>(DotSizeY / 2));
			Group->PosList_.push_back({ x, y });
		}
		QueueEffect_.push_back(Group);
	}

}

void EffectManager::ShowMoveEffect(const float4& _LUPos, GameEngineImage* _EffectImage, Direction _Dir, float _InterTime)
{

	QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, static_cast<int>(_EffectImage->GetCutCount() - 1), _InterTime);
	switch (_Dir)
	{
	case Direction::Right:
		Group->PosList_.push_back({ Random_->RandomFloat(_LUPos.x - 8.0f, _LUPos.x - 1.0f), _LUPos.y});
		break;
	case Direction::Up:
		Group->PosList_.push_back({ _LUPos.x, Random_->RandomFloat(_LUPos.y + 1.0f, _LUPos.y + 8.0f) });
		break;
	case Direction::Left:
		Group->PosList_.push_back({ Random_->RandomFloat(_LUPos.x + 1.0f, _LUPos.x + 8.0f), _LUPos.y });
		break;
	case Direction::Down:
		Group->PosList_.push_back({ _LUPos.x, Random_->RandomFloat(_LUPos.y - 8.0f, _LUPos.y - 1.0f) });
		break;
	}
	Group->MoveEffect_ = true;
	QueueEffect_.push_back(Group);
}

void EffectManager::Start()
{

}
void EffectManager::Update()
{
	if (QueueEffect_.empty() == false)
	{
		std::list<QueueEffect*>::iterator StartIter = QueueEffect_.begin();
		std::list<QueueEffect*>::iterator EndIter = QueueEffect_.end();
		while (StartIter != EndIter)
		{
			if ((*StartIter)->FrameUpdate() == true)
			{
				delete (*StartIter);
				(*StartIter) = nullptr;

				StartIter = QueueEffect_.erase(StartIter);
				continue;
			}
			++StartIter;
		}
	}
}



void EffectManager::Render()
{
	if (QueueEffect_.empty() == false)
	{
		std::list<QueueEffect*>::iterator StartIter = QueueEffect_.begin();
		std::list<QueueEffect*>::iterator EndIter = QueueEffect_.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			for (const float4& Iter : (*StartIter)->PosList_)
			{
				if ((*StartIter)->EffectImage_ == GameEngineImageManager::GetInst()->Find("Baba_Effect_sheet.bmp") ||
					(*StartIter)->EffectImage_ == GameEngineImageManager::GetInst()->Find("Wall_Effect_sheet.bmp") ||
					(*StartIter)->EffectImage_ == GameEngineImageManager::GetInst()->Find("Rock_Effect_sheet.bmp") )
				{
					GameEngine::BackBufferImage()->TransCopy((*StartIter)->EffectImage_, {Iter.x + static_cast<float>(DotSizeX / 2) - 10.0f, Iter.y + static_cast<float>(DotSizeY / 2)}, float4{20, 20}, (*StartIter)->CurrentImgPivot_, (*StartIter)->CurrentImgScale_, RGB(255, 0, 255));
				}
				else
				{
					GameEngine::BackBufferImage()->TransCopy((*StartIter)->EffectImage_, Iter, float4{ DotSizeX * 0.75, DotSizeY * 0.75 }, (*StartIter)->CurrentImgPivot_, (*StartIter)->CurrentImgScale_, RGB(255, 0, 255));
				}

			}
		}
	}
}

QueueEffect::QueueEffect(const float4& _Pos, GameEngineImage* _EffectImage, int _EndFrame, float _InterTime) :
	CurrentInterTime_(_InterTime)
	, OrignalInterTime_(_InterTime)
	, CurrentFrame_(0)
	, EndFrame_(_EndFrame)
	, Pos_(_Pos)
	, EffectImage_(_EffectImage)
	, MoveEffect_(false)
	, WinEffect_(false)
	, Speed_(1.0f)
{

}

QueueEffect::~QueueEffect()
{

}

void QueueEffect::PlusPos(float _Index)
{
	for (float4& Iter : PosList_)
	{
		Iter += (Iter - Pos_) * _Index * Speed_ * GameEngineTime::GetInst()->GetDeltaTime(0);
	}

}

void QueueEffect::SameSpeedPos()
{
	for (float4& Iter : PosList_)
	{
		Iter = Iter + ((Iter - Pos_) * Speed_ * GameEngineTime::GetInst()->GetDeltaTime(0));
	}
}

bool QueueEffect::FrameUpdate()
{
	if (MoveEffect_ == true)
	{
		{	
			PlusPos(3.300f);
		}
	}
	else if (WinEffect_ == true)
	{
		switch (CurrentFrame_)
		{
		case 0:
			SameSpeedPos();
			break;
		case 1:
			PlusPos(0.18f);
			break;
		case 2:
			PlusPos(0.08f);
			break;
		case 3:
			PlusPos(0.01f);
			break;
		default:
			break;
		}
		if (CurrentFrame_ == 0)
		{
		
		}
		else if (CurrentFrame_ > 2)
		{
			
		}
		else
		{
			
		}
		//
	}
	else
	{
		PlusPos(1.15f);
	}
	CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime(0);
	if (0 >= CurrentInterTime_)
	{
		CurrentInterTime_ = OrignalInterTime_;
		CurrentFrame_ += 1;

		if (EndFrame_ < CurrentFrame_)
		{
			return true;
			// ³¡;
		}
	}
	CurrentImgScale_ = EffectImage_->GetCutScale(CurrentFrame_);
	CurrentImgPivot_ = EffectImage_->GetCutPivot(CurrentFrame_);

	return false;
}

