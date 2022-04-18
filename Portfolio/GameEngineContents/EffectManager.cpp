#include "EffectManager.h"
#include <math.h>

EffectManager::EffectManager() 
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
}

void EffectManager::ShowRandomEffect(const float4& _LUPos, GameEngineImage* _EffectImage, GameEngineRandom* _Random, int _Min, int _Max, float _InterTime)
{	
	QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, _Random, static_cast<int>(_EffectImage->GetCutCount() - 1), _InterTime);
	int Index = _Random->RandomInt(_Min, _Max);
	for (int i = 0; i < Index; i++)
	{
		float x = _Random->RandomFloat(_LUPos.x - static_cast<float>(DotSizeX/2), _LUPos.x + static_cast<float>(DotSizeX/2));
		float y = _Random->RandomFloat(_LUPos.y - static_cast<float>(DotSizeY/2), _LUPos.y + static_cast<float>(DotSizeY/2));
		Group->PosList_.push_back({x, y});
	}
	QueueEffect_.push_back(Group);
}

void EffectManager::ShowMoveEffect(const float4& _LUPos, GameEngineImage* _EffectImage, GameEngineRandom* _Random, Direction _Dir, float _InterTime)
{
	QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, _Random, static_cast<int>(_EffectImage->GetCutCount() - 1), _InterTime);
	switch (_Dir)
	{
	case Direction::Right:
		Group->PosList_.push_back({_Random->RandomFloat(_LUPos.x + 1.0f, _LUPos.x + 8.0f), _LUPos.y});
		break;
	case Direction::Up:
		Group->PosList_.push_back({ _LUPos.x, _Random->RandomFloat(_LUPos.y - 8.0f, _LUPos.y - 1.0f) });
		break;
	case Direction::Left:
		Group->PosList_.push_back({ _Random->RandomFloat(_LUPos.x - 8.0f, _LUPos.x - 1.0f), _LUPos.y });
		break;
	case Direction::Down:
		Group->PosList_.push_back({ _LUPos.x, _Random->RandomFloat(_LUPos.y + 1.0f, _LUPos.y + 8.0f) });
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
					GameEngine::BackBufferImage()->TransCopy((*StartIter)->EffectImage_, { Iter.x + static_cast<float>(DotSizeX / 2) - 10.0f, Iter.y + static_cast<float>(DotSizeY / 2) }, float4{ 20, 20 }, (*StartIter)->CurrentImgPivot_, (*StartIter)->CurrentImgScale_, RGB(255, 0, 255));
				}
				else
				{
					GameEngine::BackBufferImage()->TransCopy((*StartIter)->EffectImage_, Iter, float4{ DotSizeX, DotSizeY }, (*StartIter)->CurrentImgPivot_, (*StartIter)->CurrentImgScale_, RGB(255, 0, 255));
				}
			}
		}
	}
}

QueueEffect::QueueEffect(const float4& _Pos, GameEngineImage* _EffectImage, GameEngineRandom* _Random, int _EndFrame, float _InterTime) :
	CurrentInterTime_(_InterTime)
	, OrignalInterTime_(_InterTime)
	, CurrentFrame_(0)
	, EndFrame_(_EndFrame)
	, Pos_(_Pos)
	, EffectImage_(_EffectImage)
	, Random_(_Random)
	, MoveEffect_(false)
{

}

QueueEffect::~QueueEffect()
{

}

void QueueEffect::PlusPos(float _Index)
{
	for (float4& Iter : PosList_)
	{
		Iter += (Iter - Pos_) * _Index * GameEngineTime::GetInst()->GetDeltaTime(0);
	}

}

bool QueueEffect::FrameUpdate()
{
	if (MoveEffect_ == true)
	{
		if (CurrentFrame_ >= 5)
		{
			PlusPos(0.01f);
		}
		else
		{
			PlusPos(1.009f);
		}
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

