#include "EffectManager.h"

EffectManager::EffectManager() 
{
}


EffectManager::~EffectManager() 
{
}

void EffectManager::ShowEffect(const float4& _LUPos, GameEngineImage* _EffectImage, GameEngineRandom* _Random, int _Min, int _Max, float _InterTime)
{
	QueueEffect* Group = new QueueEffect(_LUPos, _EffectImage, _Random, static_cast<int>(_EffectImage->GetCutCount() - 1), _InterTime);
	int Index = _Random->RandomInt(_Min, _Max);
	for (int i = 0; i < Index; i++)
	{
		float x = _Random->RandomFloat(_LUPos.x - static_cast<float>(DotSizeX / 2), _LUPos.x + static_cast<float>(DotSizeX/2));
		float y = _Random->RandomFloat(_LUPos.y - static_cast<float>(DotSizeY / 2), _LUPos.y + static_cast<float>(DotSizeY/2));
		Group->PosList_.push_back({x, y});
	}
	QueueEffect_.push_back(Group);
}

void EffectManager::ShowWinEffect(const Coordinate& _Coordinate, GameEngineImage* _EffectImage, GameEngineRandom* _Random, int _Min, int _Max, float _InterTime)
{

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
				GameEngine::BackBufferImage()->TransCopy((*StartIter)->EffectImage_, Iter, float4{ DotSizeX, DotSizeY }, (*StartIter)->CurrentImgPivot_, (*StartIter)->CurrentImgScale_, RGB(255, 0, 255));
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
{

}

QueueEffect::~QueueEffect()
{

}

void QueueEffect::RandomPlusPos()
{
	for (float4& Iter : PosList_)
	{
		Iter += (Iter - Pos_) * 1.1f * GameEngineTime::GetInst()->GetDeltaTime(0);
	}

}

bool QueueEffect::FrameUpdate()
{
	RandomPlusPos();
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

