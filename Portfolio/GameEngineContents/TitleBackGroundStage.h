#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineRenderer.h>

class TitleBackGroundStage : public GameEngineActor
{
public:
	TitleBackGroundStage();
	~TitleBackGroundStage();

	TitleBackGroundStage(const TitleBackGroundStage& _Other) = delete;
	TitleBackGroundStage(TitleBackGroundStage&& _Other) noexcept = delete;
	TitleBackGroundStage& operator=(const TitleBackGroundStage& _Other) = delete;
	TitleBackGroundStage& operator=(TitleBackGroundStage&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	float4 MoveSpeed_;
};

