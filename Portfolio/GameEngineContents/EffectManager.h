#pragma once
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngine.h>
#include <GameEngineBase/GameEngineRandom.h>
#include <vector>
#include <map>
#include "Coordinate.h"

// Ό³Έν :
class QueueEffect;
class EffectManager : public GameEngineActor
{
public:
	EffectManager();
	~EffectManager();

	EffectManager(const EffectManager& _Other) = delete;
	EffectManager(EffectManager&& _Other) noexcept = delete;
	EffectManager& operator=(const EffectManager& _Other) = delete;
	EffectManager& operator=(EffectManager&& _Other) noexcept = delete;

	void ShowRandomEffect(const float4& _LUPos, GameEngineImage* _EffectImage,int _Min, int _Max , float CurrentInterTime_ = 0.1f);
	void ShowMoveEffect(const float4& _LUPos, GameEngineImage* _EffectImage,  Direction _Dir, float _InterTime);
	bool ShowStatEffect(const float4& _LUPos, GameEngineImage* _EffectImage, int _Min, int _Max);

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	std::list<QueueEffect*> QueueEffect_;
	GameEngineRandom* Random_;
};


class QueueEffect
{
public:
	QueueEffect(const float4& _Pos, GameEngineImage* _EffectImage, int _EndFrame, float _InterTime);
	~QueueEffect();

	void PlusPos(float _Index);
	void SameSpeedPos();
	bool FrameUpdate();


	QueueEffect(const QueueEffect& _Other) = delete;
	QueueEffect(QueueEffect&& _Other) noexcept = delete;
	QueueEffect& operator=(const QueueEffect& _Other) = delete;
	QueueEffect& operator=(QueueEffect&& _Other) noexcept = delete;

	float CurrentInterTime_;
	float OrignalInterTime_;
	int CurrentFrame_;
	int EndFrame_;
	float4 CurrentImgScale_;
	float4 CurrentImgPivot_;

	GameEngineImage* EffectImage_;
	std::vector<float4> PosList_;
	float4 Pos_;

	bool MoveEffect_;
	bool WinEffect_;
	float Speed_;
private:
};