#pragma once
#include <GameEngine/GameEngineActor.h>
#include <GameEngine/GameEngineImage.h>

// Ό³Έν :
class PlayAndMainGrid : public GameEngineActor
{
public:
	PlayAndMainGrid();
	~PlayAndMainGrid();

	PlayAndMainGrid(const PlayAndMainGrid& _Other) = delete;
	PlayAndMainGrid(PlayAndMainGrid&& _Other) noexcept = delete;
	PlayAndMainGrid& operator=(const PlayAndMainGrid& _Other) = delete;
	PlayAndMainGrid& operator=(PlayAndMainGrid&& _Other) noexcept = delete;

	void Reset();

protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	float4 MapScale_;
	float4 StartDrawing_;

	int MapSizeX_;
	int MapSizeY_;
	float4 MapMaxSize_;


	GameEngineImage* GridMap_;
};

