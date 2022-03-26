#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <GameEngine/GameEngineActor.h>
#include "GamePlayEnum.h"
#include "GamePlayObject.h"
#include <map>

// Ό³Έν :
class PlayLevel;
class Coordinate : public GameEngineActor
{
	friend PlayLevel;
public:
	// constrcuter destructer
	Coordinate();
	~Coordinate();

	// delete Function
	Coordinate(const Coordinate& _Other) = delete;
	Coordinate(Coordinate&& _Other) noexcept = delete;
	Coordinate& operator=(const Coordinate& _Other) = delete;
	Coordinate& operator=(Coordinate&& _Other) noexcept = delete;

	//inline void SetPos(float4 _Pos)
	//{
	//	Pos_ = _Pos;
	//}

	//inline void SetCPos(float4 _Pos)
	//{
	//	Pos_ = _Pos;
	//}


protected:
	void Start() override;
	void Update() override;
	void Render() override;

private:
	float4 CPos_;

	std::map<int, std::vector<GameEngineImage*>>* StopImage_;
	std::map<int, std::vector<GameEngineImage*>>* MoveImage_;
};

