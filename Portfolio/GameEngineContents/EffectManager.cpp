#include "EffectManager.h"

EffectManager::EffectManager() 
{
}


EffectManager::~EffectManager() 
{
}

void EffectManager::ShowEffect(const float4& _LUPos, GameEngineImage* _EffectImage, GameEngineRandom* _Random ,int _Min, int _Max)
{
	QueueEffect* Group = new QueueEffect();
	Group->EndFrame_ = static_cast<int>(_EffectImage->GetCutCount());
	Group->EffectImage_ = _EffectImage;
	int Index = _Random->RandomInt(_Min, _Max);
	for (int i = 0; i < Index; i++)
	{
		float x = _Random->RandomFloat(_LUPos.x, _LUPos.x + static_cast<float>(DotSizeX));
		float y = _Random->RandomFloat(_LUPos.y, _LUPos.y + static_cast<float>(DotSizeY));
		Group->PosList_.push_back({x, y});
	}
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
		for (; StartIter != EndIter; ++StartIter)
		{
			if ((*StartIter)->FrameUpdate() == true)
			{
				delete (*StartIter);
				(*StartIter) = nullptr;

				StartIter = QueueEffect_.erase(StartIter);
			}
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

QueueEffect::QueueEffect() :
	CurrentInterTime_(ImageSpeed)
	, CurrentFrame_(0)
	, EndFrame_(0)
{

}

QueueEffect::~QueueEffect()
{

}

bool QueueEffect::FrameUpdate()
{
	CurrentInterTime_ -= GameEngineTime::GetInst()->GetDeltaTime(0);
	if (0 >= CurrentInterTime_)
	{
		CurrentInterTime_ = ImageSpeed;
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