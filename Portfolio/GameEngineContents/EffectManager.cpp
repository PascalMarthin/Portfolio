#include "EffectManager.h"
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <Windows.h>
#include <stdio.h>  

GameEngineRandom* EffectManager::Random_ = new GameEngineRandom();

EffectManager::EffectManager()
	: Pause_(false)
{
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
	int RandomInt = Random_->RandomInt(_Min, _Max);
	if (RandomInt == Random_->RandomInt(_Min, _Max))
	{
		float4 Center(_LUPos.x + 10.0f, _LUPos.y + 10.0f);
		QueueEffect* Group = new QueueEffect(Center, _EffectImage, static_cast<int>(_EffectImage->GetCutCount() - 1), 0.1f);
		Group->CurrentPos_.push_back(Center);
		{
			float x = 0.0f;
			float y = 0.0f;
			do
			{
				x = Random_->RandomFloat(-0.6f, 0.6f);
			} while (x > -0.3f && x < 0.3f);
			do
			{
				y = Random_->RandomFloat(-0.6f, 0.6f);
			} while (y > -0.3f && y < 0.3f);
			Group->MoveVector_.push_back(float4{x, y});
		}
		//Group->Speed_ = Random_->RandomFloat(2.0f, 5.0f);
		Group->EffectType_ = EffectType::StatEffect;
		QueueEffect_.push_back(Group);

		return true;
	}
	return false;
}

void EffectManager::ShowRandomSprayEffect(const float4& _LUPos, GameEngineImage* _EffectImage, int _Min, int _Max, float _MinVector, float _MaxVector, float _InterTime)
{
	int Index = Random_->RandomInt(_Min, _Max);
	for (int i = 0; i < Index; i++)
	{
		float RandomInterTime = Random_->RandomFloat(_InterTime - _InterTime / 2 , _InterTime * 3 );
		
		QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, static_cast<int>(_EffectImage->GetCutCount() - 1), RandomInterTime);

		{
			float x = 0.0f;
			float y = 0.0f;
			do
			{
				x = Random_->RandomFloat(_MinVector, _MaxVector);
			} while (x > -0.5f && x < 0.5f);
			do
			{
				y = Random_->RandomFloat(_MinVector, _MaxVector);
			} while (y > -0.5f && y < 0.5f);
			Group->MoveVector_.push_back(float4{ x, y });
		}
		Group->CurrentPos_.push_back(_LUPos);
		Group->EffectType_ = EffectType::SprayEffect;
		QueueEffect_.push_back(Group);
	}
}

void EffectManager::ShowRandomEffect(const float4& _LUPos, GameEngineImage* _EffectImage, int _Min, int _Max, float _InterTime)
{	
	if (_Min > _Max)
	{
		int idx = _Max;
		_Max = _Min;
		_Min = idx;
	}
	{
		QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, static_cast<int>(_EffectImage->GetCutCount() - 1), _InterTime);
		int Index = Random_->RandomInt(_Min, _Max);
		for (int i = 0; i < Index; i++)
		{
			
			Group->MoveVector_.push_back(float4::ZERO);
			{
				float x = Random_->RandomFloat(-24.0f, 24.0f);
				float y = Random_->RandomFloat(-24.0f, 24.0f);
				Group->CurrentPos_.push_back(float4{ _LUPos.x + x, _LUPos.y + y });

			}
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
		Group->MoveVector_.push_back(float4{ Random_->RandomFloat(- 0.5f , - 0.3f), 0});
		break;
	case Direction::Up:
		Group->MoveVector_.push_back(float4{ 0, Random_->RandomFloat(0.3f, 0.5f) });
		break;
	case Direction::Left:
		Group->MoveVector_.push_back(float4{ Random_->RandomFloat(0.3f, 0.5f), 0 });
		break;
	case Direction::Down:
		Group->MoveVector_.push_back(float4{ 0 , Random_->RandomFloat(- 0.5f,  - 0.3f) });
		break;
	}
	Group->AddSpeedIndex_ = 0.8f;
	Group->CurrentPos_.push_back(_LUPos);
	Group->EffectType_ = EffectType::MoveEffect;
	QueueEffect_.push_back(Group);

}

void EffectManager::Start()
{

}
void EffectManager::Update()
{
	if (Pause_ == true)
	{
		return;
	}
	if (QueueEffect_.empty() == false)
	{
		std::list<QueueEffect*>::iterator StartIter = QueueEffect_.begin();
		std::list<QueueEffect*>::iterator EndIter = QueueEffect_.end();
		while (StartIter != EndIter)
		{
			if ((*StartIter)->FrameUpdate() == false)
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
			for (float4& Iter : (*StartIter)->CurrentPos_)
			{
				char AA[100];
				char BB[100];
				sprintf_s(AA, "%f", Iter.x);
				sprintf_s(BB, "%f", Iter.y);
				RECT Rect = { 0, 0, 500, 300};
				DrawText(GameEngine::BackBufferDC(), AA, -1, &Rect, DT_CENTER);
				
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
	, Speed_(1.0f)
	, AddSpeedIndex_(0.0f)
	, EffectType_(EffectType::DefaltEffect)
{
	Random_ = EffectManager::Random_;
}

QueueEffect::~QueueEffect()
{

}

void QueueEffect::IncreaseVector(float4& _MoveVector, float _Index)
{
	_MoveVector *= _Index;
}

void QueueEffect::PlusToAllPos()
{
	for (int i = 0 ; i < CurrentPos_.size(); i++)
	{
		CurrentPos_[i] = CurrentPos_[i] + MoveVector_[i];
	}
}

void QueueEffect::SetMoveVector()
{
	switch (EffectType_)
	{
	case EffectType::MoveEffect:
		for (float4& Iter : MoveVector_)
		{
			IncreaseVector(Iter, Speed_);
		}
		break;
	case EffectType::SprayEffect:
		for (float4& Iter : MoveVector_)
		{
			IncreaseVector(Iter, Speed_);
		}
		break;
	case EffectType::StatEffect:
		for (float4& Iter : MoveVector_)
		{
			IncreaseVector(Iter, Speed_);
		}
		break;
	case EffectType::DefaltEffect:
		return;
		break;
	default:
		break;
	}
	PlusToAllPos();
}


bool QueueEffect::FrameUpdate()
{
	SetMoveVector();
	CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime(0);
	if (0 >= CurrentInterTime_)
	{
		CurrentInterTime_ = OrignalInterTime_;
		CurrentFrame_ += 1;
		SetSpeedbyFrame();
		
		if (EndFrame_ < CurrentFrame_)
		{
			return false;
			// ³¡;
		}
	}
	CurrentImgScale_ = EffectImage_->GetCutScale(CurrentFrame_);
	CurrentImgPivot_ = EffectImage_->GetCutPivot(CurrentFrame_);

	return true;
}

void QueueEffect::SetSpeedbyFrame()
{
	switch (EffectType_)
	{
	case EffectType::MoveEffect:
		Speed_ -= 0.01f;
		if (Speed_ < 0)
		{
			Speed_ = 0;
		}
		break;
	case EffectType::SprayEffect:
		Speed_ -= Random_->RandomFloat(0.005f, 0.01f) * CurrentFrame_;
		if (Speed_ < 0)
		{
			Speed_ = 0;
		}
		break;
	case EffectType::StatEffect:
		Speed_ -= Random_->RandomFloat(0.003f, 0.008f);
		if (Speed_ < 0)
		{
			Speed_ = 0;
		}
		break;
	default:
		return;
		break;
	}
}
