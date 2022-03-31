#pragma once
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

	inline GameEngineImage* GetImage()
	{
		return Image_;
	}

	
	inline ObjectName GetName()
	{
		return Name_;
	}
	virtual void SettingImg(){}
	virtual void Destroy() = 0;

protected:
	GameEngineImage* Image_;
	ObjectName Name_;

private:

};

