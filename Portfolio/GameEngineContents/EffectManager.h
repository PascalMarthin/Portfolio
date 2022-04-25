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
enum class EffectType;
class EffectManager : public GameEngineActor
{
public:
	EffectManager();
	~EffectManager();

	EffectManager(const EffectManager& _Other) = delete;
	EffectManager(EffectManager&& _Other) noexcept = delete;
	EffectManager& operator=(const EffectManager& _Other) = delete;
	EffectManager& operator=(EffectManager&& _Other) noexcept = delete;

	void PauseOff()
	{
		Pause_ = false;
	}
	void PauseOn()
	{
		Pause_ = true;
	}

	void ShowRandomEffect(const float4& _LUPos, GameEngineImage* _EffectImage,int _Min, int _Max , float CurrentInterTime_ = 0.1f);
	void ShowMoveEffect(const float4& _LUPos, GameEngineImage* _EffectImage,  Direction _Dir, float _InterTime);
	bool ShowStatEffect(const float4& _LUPos, GameEngineImage* _EffectImage, int _Min, int _Max);
	void ShowRandomSprayEffect(const float4& _LUPos, GameEngineImage* _EffectImage, int _Min, int _Max, float _MinVector, float _MaxVector, float _InterTime);
	static GameEngineRandom* Random_;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	std::list<QueueEffect*> QueueEffect_;
	bool Pause_;
};


class QueueEffect
{
public:
	QueueEffect(const float4& _Pos, GameEngineImage* _EffectImage, int _EndFrame, float _InterTime);
	~QueueEffect();

	void IncreaseVector(float4& _MoveVector, float _Index);
	void SetMoveVector();
	bool FrameUpdate();


	QueueEffect(const QueueEffect& _Other) = delete;
	QueueEffect(QueueEffect&& _Other) noexcept = delete;
	QueueEffect& operator=(const QueueEffect& _Other) = delete;
	QueueEffect& operator=(QueueEffect&& _Other) noexcept = delete;

	float4 CurrentImgScale_;
	float4 CurrentImgPivot_;
	GameEngineImage* EffectImage_;

	std::vector<float4> MoveVector_;
	std::vector<float4> CurrentPos_;

	float Speed_;
	float AddSpeedIndex_;
	GameEngineRandom* Random_;
	EffectType EffectType_;

private:
	float CurrentInterTime_;
	float OrignalInterTime_;
	int CurrentFrame_;
	int EndFrame_;

	float4 Pos_;
	void PlusToAllPos();
	void SetSpeedbyFrame();
};

enum class EffectType
{
	MoveEffect,
	SprayEffect,
	DefaltEffect,
	StatEffect
};