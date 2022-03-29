#pragma once
#include <vector>
#include <GameEngine/GameEngineImage.h>
#include <GameEngine/GameEngineImageManager.h>
#include "GamePlayEnum.h"

// Ό³Έν :
class GamePlayObject
{
public:
	GamePlayObject();
	virtual ~GamePlayObject();

	GamePlayObject(const GamePlayObject& _Other) = delete;
	GamePlayObject(GamePlayObject&& _Other) noexcept = delete;
	GamePlayObject& operator=(const GamePlayObject& _Other) = delete;
	GamePlayObject& operator=(GamePlayObject&& _Other) noexcept = delete;

	inline std::map<int ,std::vector<GameEngineImage*>>* GetStopImage()
	{
		return &StopImage_;
	}

	inline std::map<int, std::vector<GameEngineImage*>>* GetMoveImage()
	{
		return &MoveImage_;
	}
	
	inline ObjectName GetName()
	{
		return Name_;
	}
	virtual void SettingImg(){}
	virtual void Destory(){}

protected:
	std::map<int ,std::vector<GameEngineImage*>> StopImage_;
	std::map<int, std::vector<GameEngineImage*>> MoveImage_;

	ObjectName Name_;

private:

};

