#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class StageName : public GameEngineActor
{
public:
	// constrcuter destructer
	StageName();
	~StageName();

	// delete Function
	StageName(const StageName& _Other) = delete;
	StageName(StageName&& _Other) noexcept = delete;
	StageName& operator=(const StageName& _Other) = delete;
	StageName& operator=(StageName&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	std::map<Stage, GameEngineRenderer*> StageRenderer_;
};

