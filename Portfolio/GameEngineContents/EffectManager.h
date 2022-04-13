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

	void ShowEffect(const float4& _LUPos, GameEngineImage* _EffectImage, GameEngineRandom* _Random, int _Min, int _Max , float CurrentInterTime_ = 0.1f);
	void ShowWinEffect(const Coordinate& _Coordinate, GameEngineImage* _EffectImage, GameEngineRandom* _Random, int _Min, int _Max, float _InterTime);

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	std::list<QueueEffect*> QueueEffect_;
};

class QueueEffect
{
public:
	QueueEffect(const float4& _Pos, GameEngineImage* _EffectImage, GameEngineRandom* _Random, int _EndFrame, float _InterTime);
	~QueueEffect();

	void RandomPlusPos();
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

	GameEngineRandom* Random_;
	GameEngineImage* EffectImage_;
	std::vector<float4> PosList_;
	const float4& Pos_;
private:
};